# BEngine

v0.4 of a C++ Game Engine using SFML

SFML (Simple and Fast Multimedia Library): https://www.sfml-dev.org/

The engine was created for my own games and apps, but can be used for a wide variety of other projects.

## Internal Assembly

- ### Engine
  - #### Asset Manager
	- Animations
	- Audios
	- Fonts
    - Textures
  - #### Input Manager
    - Mouse Checks
  - #### Entity Manager
	- Add Entities: Possibility of performing the most diverse behaviors, fully customizable
	- Update Entities: Execution of Component Behaviors
  - #### State Machine
	- State Stack: A stack that stores the states, executing the top state
    - State
	  - Methods
	    - Init: Initial state settings. Runs only at start of state
	    - Handle Input: Manage user input or UI. Runs every frame of state
	    - Update: General code to runs at every frame of state
	    - Draw: Drawing of sprites. Runs every frame of state
