#include "GUI/Text.h"

UI::Text::Text(sf::Vector2f position, std::string text, sf::Font& font, bool visible){
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setPosition(position);
    this->visible = visible;
}

void UI::Text::Update(sf::RenderWindow* window, sf::View view){
    ;
}

void UI::Text::Set(std::string text){
    ;
}

int UI::Text::Return(){
    return -1;
}

void UI::Text::Draw(sf::RenderWindow* window){
    window->draw(text);
}
