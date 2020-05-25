#pragma once

#include <SFML/Graphics.hpp>
#include "UI.h"

namespace UI{
    class Bar : public BaseEntity{
        public:
            Bar(float* posX,float* posY,int* value,int* maxValue,sf::Color color,int width,int thickness,bool visible);
            ~Bar(){};

            void Update();
            void Draw();
            int Return();

        private:
            bool visible;

            sf::RectangleShape bar;
            sf::RectangleShape barBackground;

            float barWidth;
            float barThickness;

            sf::Vector2f position;
            float* posX;
            float* posY;

            int* value;
            int* maxValue;
    };
}
