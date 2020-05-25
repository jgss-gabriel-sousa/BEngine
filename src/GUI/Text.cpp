#include "GUI/Text.h"

UI::Text::Text(sf::Vector2f position, std::string text, std::string font, bool visible){
    this->text.setString(text);
    //this->text.setFont(_data->assets.GetFont(font));
    this->text.setPosition(position);
    this->visible = visible;
}

void UI::Text::Update(){
    ;
}

int UI::Text::Return(){
    return -1;
}

void UI::Text::Draw(){
    //_data->window.draw(text);
}
