# BEngine

v0.4 – C++ Game Engine built on [SFML](https://www.sfml-dev.org/)

BEngine is a game engine developed in C++, designed for learning purposes and for creating small games and applications.

## 🔧 Core Modules
### 🖼 Asset Manager
Handles all game resources:
- **Textures**
- **Animations** (frame-based loading)
- **Fonts**
- **Audio**

   
### 🖱 Input Manager
- Handles mouse and keyboard input

 
### 🧩 Entity Manager
- Add Entities: create fully customizable entities with specific behaviors
- Update Entities: run entity/component logic every frame

 
### 🔄 State Machine
Manages game flow using a state stack:
- **State Stack**: executes the state at the top of the stack
- **State Lifecycle**:
	- ```Init```: runs once when the state is created
  	- ```HandleInput```: processes user input every frame
	- ```Update```: runs main game logic every frame
	- ```Draw```: renders sprites every frame
