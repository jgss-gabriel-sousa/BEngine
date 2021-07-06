#include "SplashState.h"

SplashState::SplashState(GameDataRef data) : data(data){
    ;
}

void SplashState::Init(){
    entity.SetColor(sf::Color(0,255,0,255));
    entity2.SetColor(sf::Color(255,0,0,255));

    entity.SetSize(40,50);
    entity2.SetSize(500,50);
    data-

    entity.AddComponent("draggable","");
    entity.AddComponent("solid","");
    entity2.AddComponent("solid","");
    entity.AddComponent("bullet","1.0");
    entity.AddComponent("wrap","");
    entity2.AddComponent("wrap","");

    data->gui.AddButton("test",sf::Vector2f(data->engine.screenWidth-50,data->engine.screenHeight-50),sf::Vector2f(100,100),"text","light");

    data->entities.AddEntity(&entity);
    data->entities.AddEntity(&entity2);
}

void SplashState::HandleInput(){
    ;
}

void SplashState::Update(float dt){
    data->gui.Set("test","text="+to_string(data->engine.fps));
}

void SplashState::Draw(float dt){
    ;
}







