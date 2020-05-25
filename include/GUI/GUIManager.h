#pragma once

#include "GUI/Button.h"
#include "GUI/Text.h"
#include "GUI/Hotbar.h"
#include "GUI/Bar.h"

#include "AssetManager.h"

#include <map>

using namespace std;

class GUIManager{
public:
    enum Style{
        light,
        dark
    };

    GUIManager(){};
    ~GUIManager(){};

    void Init(AssetManager* asset, sf::RenderWindow* window);
    void Update();
    void Draw();
    void Set(string name,string argument);
    void Reset();
    void Remove(string name);

    void AddButton(string,sf::Vector2f,sf::Vector2f,string,string);
    void AddText(string name,sf::Vector2f position,string text,string font,bool visible);
    void AddBar(string name,sf::Color color,float* posX,float* posY,int* value,int* maxValue,int width,int thickness,bool visible);
    void AddHotbar(string name,sf::Vector2f position,int elements,bool visible);

    int getReturn(std::string name);

private:
    map<string,UI::BaseEntity*> elements;

    AssetManager* asset;
    sf::RenderWindow* window;
};
