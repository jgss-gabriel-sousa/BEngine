#include "InputManager.h"

bool InputManager::IsSpriteClicked(sf::FloatRect objectBounds, sf::Mouse::Button button, sf::RenderWindow &window, sf::View view){
    if(sf::Mouse::isButtonPressed(button)){
        if(objectBounds.contains(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window),view)))){
            return true;
        }
    }
    return false;
}

bool InputManager::IsOverSprite(sf::FloatRect objectBounds, sf::RenderWindow &window,sf::View view){
    if(objectBounds.contains(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window),view)))){
        return true;
    }
    return false;
}

sf::Vector2f InputManager::GetMousePosition(sf::RenderWindow &window,sf::View view){
    return window.mapPixelToCoords(sf::Mouse::getPosition(window),view);
}
