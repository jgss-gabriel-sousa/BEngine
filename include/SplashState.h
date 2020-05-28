#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Engine.h"
#include "Entity.h"

class SplashState : public State{
public:
    SplashState(GameDataRef data);

    void Init();

    void HandleInput();
    void Update(float dt);
    void Draw(float dt);

private:
    GameDataRef data;
    Entity entity = Entity("box",sf::Vector2f(START_SCREEN_WIDTH/4,START_SCREEN_HEIGHT/4));
    Entity entity2 = Entity("box2",sf::Vector2f(START_SCREEN_WIDTH/2,START_SCREEN_HEIGHT/2));
};
