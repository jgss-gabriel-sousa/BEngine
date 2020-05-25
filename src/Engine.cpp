#include "Engine.h"
#include "SplashState.h"

Engine::Engine(){
    UserConfigs();

    _data->window.setVerticalSyncEnabled(true);
    _data->machine.AddState(StateRef(new SplashState(this->_data)));

    sf::Image icon;
    icon.loadFromFile("resources/textures/icon.png");
    _data->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    _data->gui.Init(&_data->assets,&_data->window);

    this->Run();
}

void Engine::UserConfigs(){
    int width = actualResolution.x, height = actualResolution.y;
    bool fullscreen = false;
    ifstream file;
    string read;

    file.open(USER_CONFIG_FILE,ios::in);

    if(file.is_open()){
        while(!file.eof() && !file.bad()){
            getline(file,read);

            try{
                if(read.find("resolution") != string::npos){
                    read = read.substr(read.find("=")+1);
                    width = stoi(read.substr(0,read.find("x")));
                    height = stoi(read.substr(read.find("x")+1));
                }
                else if(read.find("fullscreen") != string::npos){
                    read = read.substr(read.find("=")+1);
                    if(read == "true")
                        fullscreen = true;
                }
            }
            catch(exception& e){
                LogPush("Error in \"Config.ini\" file");
            }
        }
    }


    if(width == 0 || height == 0){
        width = START_SCREEN_WIDTH;
        height = START_SCREEN_HEIGHT;
        actualResolution = sf::Vector2f(START_SCREEN_WIDTH,START_SCREEN_HEIGHT);
    }

    if(fullscreen)
        _data->window.create(sf::VideoMode(width,height),"",sf::Style::Fullscreen);
    else
        _data->window.create(sf::VideoMode(width,height),"",sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar);
}

void Engine::CheckFocus(){
    if(!_data->window.hasFocus()){
        _data->window.setFramerateLimit(10);
    }
    else{
        _data->window.setFramerateLimit(framerate);
    }
}

void Engine::UpdateAndDrawEntities(){
    _data->entities.Update(_data->window,worldView);
}

void Engine::UpdateUI(){
    _data->gui.Update();
}

void Engine::DrawUI(){
    _data->gui.Draw();
}

void Engine::GlobalWindowEvents(){
    sf::Event event;
    GUIview = _data->window.getDefaultView();

    while(_data->window.pollEvent(event)){
        if(sf::Event::Closed == event.type){
            this->_data->window.close();
        }
        if(event.type == sf::Event::Resized){
            GUIview.setSize({
                static_cast<float>(event.size.width),
                static_cast<float>(event.size.height)
            });

            actualResolution = sf::Vector2f(GUIview.getSize().x,GUIview.getSize().y);

            _data->window.setView(GUIview);
        }
    }
}

void Engine::Run(){
    float newTime, frameTime, interpolation;

    float currentTime = gameClock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while(_data->window.isOpen()){
        CheckFocus();
        GlobalWindowEvents();

        _data->machine.ProcessStateChanges();

        newTime = gameClock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if(frameTime > 0.25f)
            frameTime = 0.25f;


        currentTime = newTime;
        accumulator += frameTime;

        while(accumulator >= dt){
            _data->machine.GetActiveState()->HandleInput();
            _data->machine.GetActiveState()->Update(dt);

            _data->gui.Update();

            accumulator -= dt;
        }
        interpolation = accumulator / dt;
        _data->window.clear();
        _data->machine.GetActiveState()->Draw(interpolation);

        _data->window.setView(worldView);
        UpdateAndDrawEntities();
        _data->window.setView(GUIview);
        DrawUI();
        _data->window.display();
    }
}
