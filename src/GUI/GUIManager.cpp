#include "GUI/GUIManager.h"

void GUIManager::Init(AssetManager* asset, sf::RenderWindow* window){
    this->asset = asset;
    this->window = window;
}

void GUIManager::Update(){
    for(pair<string,UI::BaseEntity*> element : elements){
        element.second->Update(window,window->getDefaultView());
    }
}

void GUIManager::Draw(){
    sf::View worldView = window->getView();
    window->setView(window->getDefaultView());

    for(pair<string,UI::BaseEntity*> element : elements){
        element.second->Draw(window);
    }

    window->setView(worldView);
}

int GUIManager::getReturn(std::string name){
    for(pair<string,UI::BaseEntity*> element : elements){
        if(element.first == name){
            return element.second->Return();
        }
    }

    /*
    for(int i = 0; i < elements.size(); i++){
        if(elements[i].first == name)
            return elements[i].second->Return();
    }*/
}

void GUIManager::Set(string name,string argument){
    elements[name]->Set(argument);
}

void GUIManager::Remove(string name){
    elements.erase(name);
}

void GUIManager::Reset(){
    elements.clear();
}

void GUIManager::AddButton(string name,sf::Vector2f position,sf::Vector2f Size,string text,string style){
    elements[name] = new UI::Button(position,Size,text,style,asset->GetFont(BUTTON_FONT));
}

void GUIManager::AddText(std::string name,sf::Vector2f position, std::string text, std::string font, bool visible){
    elements[name] = new UI::Text(position,text,asset->GetFont(BUTTON_FONT),visible);
}

void GUIManager::AddBar(std::string name,sf::Color color,float* posX,float* posY,int* value,int* maxValue,int width,int thickness,bool visible){
    //elements[name] = new UI::Bar(float* posX,float* posY,int* value,int* maxValue,sf::Color color,int width,int thickness,bool visible);
}

void GUIManager::AddHotbar(std::string name,sf::Vector2f position,int elements,bool visible){
    //elements[name] = new UI::Hotbar(position,elements,visible);
}
