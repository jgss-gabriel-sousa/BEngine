#include "SplashState.h"

SplashState::SplashState(GameDataRef data) : _data(data){
    ;
}

void SplashState::Init(){
    entity.SetColor(0,255,0,255);
    entity2.SetColor(255,0,0,255);
    //entity2.SetTexture("entity",_data->assets);

    entity.SetSize(40,50);
    entity2.SetSize(500,50);

    entity.AddComponent("draggable","");
    entity2.AddComponent("draggable","");
    //entity.AddComponent("gravity","9");
    entity.AddComponent("solid","");
    entity2.AddComponent("solid","");
    //entity.AddComponent("bullet","1.0");
    entity.AddComponent("wrap","");
    entity2.AddComponent("wrap","");
    entity.AddComponent("movement","arrows|5");
    //entity.AddComponent("snapToGrid","100");
    //entity.AddComponent("rotate","arrows|gradually|0");

    _data->gui.AddButton("test",sf::Vector2f(_data->window.getSize().x,_data->window.getSize().y),sf::Vector2f(100,100),"text","light");

    _data->entities.AddEntity(&entity);
    _data->entities.AddEntity(&entity2);
}

void SplashState::HandleInput(){
    ;
}

void SplashState::Update(float dt){
    ;
    entity.GetVelocity();
}

void SplashState::Draw(float dt){
    ;
}







