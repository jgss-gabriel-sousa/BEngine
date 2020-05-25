#include "GUI/Hotbar.h"

UI::Hotbar::Hotbar(sf::Vector2f position, int elements, bool visible){
    this->visible = visible;
/*
    sprite.setPosition(position);
    sprite.setTexture(_data->assets.GetTexture(BUTTON_TEXTURE));
    sprite.setScale(scale,scale);

    buttonText.setFont(_data->assets.GetFont(BUTTON_FONT));
    buttonText.setString(text);
    buttonText.setOrigin(buttonText.getGlobalBounds().width/2,buttonText.getGlobalBounds().height/2);
    buttonText.setPosition(position.x+(sprite.getGlobalBounds().width/2),position.y+(sprite.getGlobalBounds().height/2)-(buttonText.getCharacterSize()/4));
*/
}

void UI::Hotbar::Update(){
    /*
    if(clicked && framesBetweenClick > 0)
        clicked = false;

    if(framesBetweenClick != -1)
        framesBetweenClick++;

    if(framesBetweenClick > FRAMES_CLICK_ANIMATION){
        clicked = false;
        framesBetweenClick = -1;
        sprite.setTexture(_data->assets.GetTexture(BUTTON_TEXTURE));
    }
    */
}

int UI::Hotbar::Return(){
    return actualSelected;
}

void UI::Hotbar::Draw(){
    if(visible){
       ;//_data->window.draw(buttonText);
    }
}
