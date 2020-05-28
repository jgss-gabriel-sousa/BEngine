#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "UI.h"
#include "Log.h"

#define BUTTON_FONT "arial"
#define BUTTON_AUDIO "Button Click"
#define FRAMES_CLICK_ANIMATION 5

using namespace std;

namespace UI{
    class Button : public BaseEntity{
        public:
            Button(sf::Vector2f,sf::Vector2f,string,string,sf::Font&);
            ~Button(){};

            void Update(sf::RenderWindow*,sf::View);
            void Draw(sf::RenderWindow*);
            void Set(string);
            int Return();
            void SetButtonColor();

        private:
            bool visible;
            bool clicked;

            string style;

            int framesBetweenClick = FRAMES_CLICK_ANIMATION;

            sf::RectangleShape sprite;
            sf::Text text;
    };
}
