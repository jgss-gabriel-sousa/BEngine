#pragma once

class State{
public:
    virtual void Init() = 0; //Initial state settings. Runs only at start of state

    virtual void HandleInput() = 0; //Manage user input or UI. Runs every frame of state
    virtual void Update(float dt) = 0; //General code to runs at every frame of state
    virtual void Draw(float dt) = 0; //Drawing of sprites. Runs every frame of state

    virtual void Pause(){};
    virtual void Resume(){};
};
