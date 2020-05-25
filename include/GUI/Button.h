#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "UI.h"
#include "Log.h"

#define BUTTON_TEXTURE "Button"
#define BUTTON_CLICKED_TEXTURE "ButtonClicked"
#define BUTTON_FONT "arial"
#define BUTTON_AUDIO "Button Click"
#define FRAMES_CLICK_ANIMATION 5

using namespace std;

namespace UI{
    class Button : public BaseEntity{
        public:
            Button(sf::Vector2f,sf::Vector2f,string,string,sf::Font&);
            ~Button(){};

            void Update();
            void Draw(sf::RenderWindow*);
            void Set(string);
            int Return();

            void Click();

        private:
            bool visible;
            bool clicked;

            int framesBetweenClick;

            sf::RectangleShape sprite;
            sf::Text text;
    };
}
