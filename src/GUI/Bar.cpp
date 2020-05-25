#include "GUI/Bar.h"

UI::Bar::Bar(float* posX,float* posY,int* value,int* maxValue,sf::Color color,int width,int thickness,bool visible){
    this->visible = visible;
    this->posX = posX;
    this->posY = posY;
    this->value = value;
    this->maxValue = maxValue;
    barWidth = width;
    barThickness = thickness;

    bar.setFillColor(color);
    bar.setSize(sf::Vector2f(barWidth,barThickness));

    barBackground.setFillColor(sf::Color::Black);
    barBackground.setSize(sf::Vector2f(barWidth,barThickness));
    barBackground.setOrigin(0,0);
}

void UI::Bar::Update(){
    position = sf::Vector2f(*posX,*posY);

    bar.setPosition(position.x,position.y-40);
    bar.setSize(sf::Vector2f(barWidth/(*maxValue / (*value+0.001)),barThickness));
    barBackground.setPosition(position.x,position.y-40);
}

int UI::Bar::Return(){
    ;
}

void UI::Bar::Draw(){
    if(visible){
        //_data->window.draw(barBackground);
        //_data->window.draw(bar);
    }
}
