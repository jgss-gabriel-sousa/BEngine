#pragma once

#include <SFML/Graphics.hpp>

class InputManager{
public:
    InputManager(){}
    ~InputManager(){}

    bool IsSpriteClicked(sf::FloatRect objectBounds, sf::Mouse::Button button, sf::RenderWindow &window, sf::View view);
    bool IsOverSprite(sf::FloatRect objectBounds, sf::RenderWindow &window, sf::View view);
    sf::Vector2f GetMousePosition(sf::RenderWindow &window, sf::View view);
};
