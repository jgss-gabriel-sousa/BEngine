#include "GUI/Button.h"

UI::Button::Button(sf::Vector2f position,sf::Vector2f Size,string sText,string style,sf::Font& font){
    framesBetweenClick = 0;
    this->style = style;

    sprite.setSize(Size);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    sprite.setPosition(position);
    text.setString(sText);
    text.setFont(font);
}

void UI::Button::Update(sf::RenderWindow* window,sf::View view){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(sprite.getGlobalBounds().contains(sf::Vector2f(window->mapPixelToCoords(sf::Mouse::getPosition(*window),view)))){
            framesBetweenClick = 0;
            clicked = true;
        }
    }

    if(!visible){
        sprite.setPosition(-1000,-1000);
    }
    else{
        text.setCharacterSize(sprite.getGlobalBounds().width*0.3);
        text.setOrigin(text.getGlobalBounds().width/2,text.getGlobalBounds().height);
        text.setPosition(sprite.getPosition().x,sprite.getPosition().y);

        if(framesBetweenClick != -1)
            framesBetweenClick++;

        if(framesBetweenClick > FRAMES_CLICK_ANIMATION){
            clicked = false;
            framesBetweenClick = -1;
        }
    }

    SetButtonColor();
}

void UI::Button::Set(string argument){
    if(argument == "invisible"){
        visible = false;
    }
    else if(argument == "visible"){
        visible = true;
    }
    else if(argument.find("text=") != string::npos){
        try{
            text.setString(argument.substr(argument.find("=")+1));
        }catch(exception& e){
            LogPush("Error in UI::Button argument \""+argument+"\"");
        }
    }
}

void UI::Button::SetButtonColor(){
    if(style == "light"){
        text.setFillColor(sf::Color::Black);

        if(clicked)
            sprite.setFillColor(sf::Color(224,224,224,255));
        else
            sprite.setFillColor(sf::Color::White);
    }
    else if(style == "dark"){
        text.setFillColor(sf::Color::White);

        if(clicked)
            sprite.setFillColor(sf::Color(32,32,32,255));
        else
            sprite.setFillColor(sf::Color::Black);
    }
    else{
        LogPush("Error: Button with incorrect Style Argument");
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





