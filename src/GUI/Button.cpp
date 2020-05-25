#include "GUI/Button.h"

UI::Button::Button(sf::Vector2f position,sf::Vector2f Size,string sText,string style,sf::Font& font){
    framesBetweenClick = 0;

    sprite.setSize(Size);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    sprite.setPosition(position);
    text.setString(sText);

    if(style == "light"){
        sprite.setFillColor(sf::Color::White);
        text.setFillColor(sf::Color::Black);
    }
    else if(style == "dark"){
        sprite.setFillColor(sf::Color::Black);
        text.setFillColor(sf::Color::White);
    }
    else{
        LogPush("Error: Button with incorrect Style Argument");
    }

    text.setFont(font);
    text.setCharacterSize(sprite.getGlobalBounds().width*0.3);
    text.setOrigin(text.getGlobalBounds().width/2,text.getGlobalBounds().height);
    text.setPosition(position.x,position.y);
}

void UI::Button::Update(){
    if(!visible){
        sprite.setPosition(-1000,-1000);
    }

    if(clicked && framesBetweenClick > 0)
        clicked = false;

    if(framesBetweenClick != -1)
        framesBetweenClick++;

    if(framesBetweenClick > FRAMES_CLICK_ANIMATION){
        clicked = false;
        framesBetweenClick = -1;
    }
}

void UI::Button::Set(string argument){
    if(argument == "invisible"){
        visible = false;
    }
    else if(argument == "visible"){
        visible = true;
    }
    else if(argument.find("text") != string::npos){
        ;
    }
}

int UI::Button::Return(){
    if(clicked){
        return 1;
    }
    else{
        return 0;
    }
}

void UI::Button::Draw(sf::RenderWindow* window){
    if(visible){
        window->draw(sprite);
        window->draw(text);
    }
}

void UI::Button::Click(){
    framesBetweenClick = 0;
    //_data->assets.PlayAudio(BUTTON_AUDIO);
    //sprite.setTexture(_data->assets.GetTexture(BUTTON_CLICKED_TEXTURE));
}
