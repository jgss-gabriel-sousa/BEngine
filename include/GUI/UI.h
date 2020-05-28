#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace UI{
    class BaseEntity{
        public:
            virtual void Update(sf::RenderWindow*,sf::View) = 0;
            virtual void Draw(sf::RenderWindow*) = 0;
            virtual int Return() = 0;
            virtual void Set(std::string) = 0;
    };
}
