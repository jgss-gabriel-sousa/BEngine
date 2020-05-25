#pragma once

#include <SFML/Graphics.hpp>
#include "UI.h"

namespace UI{
    class Text : public BaseEntity{
        public:
            Text(sf::Vector2f position, std::string text, std::string font, bool visible);
            ~Text(){};

            void Update();
            void Draw();
            int Return();

            void Click();

        private:
            int visible;

            sf::Text text;
    };
}
