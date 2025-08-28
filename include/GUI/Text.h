#pragma once

#include <SFML/Graphics.hpp>
#include "UI.h"

namespace UI{
    class Text : public BaseEntity{
        public:
            Text(sf::Vector2f position, std::string text, sf::Font& font, bool visible);
            ~Text(){};

            void Update(sf::RenderWindow*,sf::View);
            void Draw(sf::RenderWindow*);
            void Set(std::string);
            int Return();

            void Click();

        private:
            int visible;

            sf::Text text;
    };
}
