#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include "log.h"

#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "EntityManager.h"
#include "GUI/GUIManager.h"
#include "DEFINITIONS.h"

struct EngineInfo{
    int screenWidth;
    int screenHeight;
    int fps;
};

struct GameData{
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    EntityManager entities;
    GUIManager gui;
    EngineInfo engine;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Engine{
public:
    Engine();

    sf::Vector2f actualResolution;
    const int framerate = 60;
    const string title = "BEngine 3.0";

private:
    const float dt = 1.0f/60.0f;
    sf::Clock gameClock;

    GameDataRef data = std::make_shared<GameData>();

    sf::View GUIview;
    sf::View worldView;

    void UserConfigs();
    void CheckFocus();
    void UpdateAndDrawEntities();
    void UpdateUI();
    void CorrectUIScale(const sf::View);
    void DrawUI();
    void GlobalWindowEvents();
    void UpdateEngineInfo(float);

    void Run();
};






