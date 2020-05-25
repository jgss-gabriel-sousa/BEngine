#pragma once

#include <SFML/Graphics.hpp>
#include "UI.h"

#define SLOT_TEXTURE "hotbarSlot"
#define ITEM_NAME_FONT "arial"

namespace UI{
    class Hotbar : public BaseEntity{
        public:
            Hotbar(sf::Vector2f position, int elements, bool visible);
            ~Hotbar(){};

            void Update();
            void Draw();
            int Return();

        private:
            bool visible;

            sf::Sprite slot;
            sf::View view;

            sf::Text itemName;

            int actualSelected;
    };
}
