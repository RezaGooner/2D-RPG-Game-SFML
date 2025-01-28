# 2D RPG Game (SFML)

This project is a **2D Role-Playing Game (RPG)** inspired by the nostalgic **Super Mario** style. It is developed in **C++** using the **SFML** library(v2.5.1)

## About the Game
Get ready for an exciting adventure!  
- Enemies will come your way, so gear up with your bow and shoot arrows to take them down.  
- If the enemies manage to injure you, eat bananas or apples to regain your health.  
- Be mindful of your arrows; they can run out! Collect coins throughout the game to increase your score.  

The game features:
- Various visuals and sound effects
- Background music
- Multiple collectible items (coins, health boosts, etc.)

## Project Structure
### Key Files and Directories
- **`include/config.h`**: Contains constants, variables, and configurations for the game, linked to the main file (`main.cpp`).
- **`assets/`**: Includes all the assets required for the game, such as:
  - Images and sprites
  - Sound effects and music
  - Fonts for text display
- **`CMakeLists.txt`**: Links necessary libraries and compilers for building the project.

## Button guide
### Move to right
![g14209](https://github.com/user-attachments/assets/3aa77982-5a18-4aab-8d04-52a87d53aa16) 
### Move to left
![g14134](https://github.com/user-attachments/assets/f85f2230-14ec-4a80-a35c-cd4b69cfbdf9)
### Jump
![g14253](https://github.com/user-attachments/assets/17a50544-188e-46ba-9b2c-81fe944eae33)
### Shoot
![g14245](https://github.com/user-attachments/assets/8294bd03-b36d-49c6-a021-145e7b79954f)


## Installation and Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/RezaGooner/2D-RPG-Game-SFML.git
   cd 2D-RPG-Game-SFML
Ensure you have SFML installed on your system. Download it from SFML's official website.
Build the project using CMake:
bash
Copy
Edit
mkdir build
cd build
cmake ..
make
Run the game:
bash
Copy
Edit
./2D-RPG-Game
Screenshots
Here are some screenshots from the game:


![P1](https://github.com/user-attachments/assets/0cebbabb-7ffe-4341-8acc-9a6f5994428e)
![P2](https://github.com/user-attachments/assets/1f452d2b-a7aa-4a4c-85f6-6ebbb643032f)
![P3](https://github.com/user-attachments/assets/f25ea733-f58b-47c4-b735-c36ee1d5413f)
![P4](https://github.com/user-attachments/assets/9f063b4e-38d8-45c2-9c39-f86c475fe4e2)
![P5](https://github.com/user-attachments/assets/1f19ae20-e21f-4bcf-9bbe-ea91392a5650)




Features
Dynamic Gameplay: Combat enemies, collect coins, and manage resources.
Audio-Visual Effects: Engaging visuals, sound effects, and background music.
Item System: Collect health items and arrows to survive.
Configurable Settings: Easily modify game settings via config.h.
