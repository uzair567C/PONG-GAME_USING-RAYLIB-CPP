# PONG-GAME_USING-RAYLIB-CPP
This is my first-semester project focused on procedural programming, covering essential concepts in programming fundamentals. It demonstrates the use of structured code, algorithms, modularity, and control flow to solve practical problems like a game.

---

## 🏓 Raylib Pong Game
A feature-rich, cross-platform Pong implementation built with C++ and Raylib. Play against a friend or a CPU, customize your visuals, and enjoy a polished arcade experience.

## 🚀 Features


| ID | Name | Description |
|---|---|---|
| 1 | **Main Menu** | Clean UI for navigation between Play, Settings, and Quit. |
| 2 | **Game Mode** | Selection screen for Player vs Player or Player vs CPU. |
| 3 | **PvP** | Local 1v1 multiplayer with smooth paddle physics. |
| 4 | **PvC** | Single-player mode with an AI-controlled opponent. |
| 5 | **Settings** | Real-time color theme switching (Blue, Gold, Red, Light Gray). |
| 6 | **Music Toggle** | Enable or disable background music and sound effects. |
| 7 | **Pause Menu** | Intermediate screen to resume gameplay or quit to menu. |
| 8 | **Data Saving** | Uses `fstream` to remember your selected theme in `setting.txt`. |

## 🛠️ Installation & Requirements

### 1. Install Raylib
Before building the project, you need the Raylib development files. (Note: the included `include/` and `lib/` folders are for Windows; Linux uses system libraries).

**Linux (Arch/Manjaro):**
```bash
sudo pacman -S raylib
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt install libraylib-dev
```

**Windows:**
1. Download the [MinGW-w64 installer](https://www.mingw-w64.org/) or follow [VS Code](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites) steps.
2. Add the `bin` folder of MinGW to your **System Environment Variables (PATH)**.
3. *Note:* This repository includes a local `lib/` and `include/` folder for Windows portability.

### 2. 📁 Project Structure
```text
.
├── bin/          # Compiled executables
├── Extras/       # Game assets (button.mp3, etc.)
├── include/      # Raylib headers (Windows)
├── lib/          # Raylib static libs (Windows)
├── src/          # C++ source code
├── obj/          # Object files
├── Makefile      # Build script
└── setting.txt   # User settings
```

## 🏗️ Building and Running
The included Makefile detects your OS automatically.

### **Linux (Terminal) and Windows (CMD/Powershell)**
```bash
make        # Compiles and runs immediately
make run    # if already complied then it runs
make build  # Compiles only
make clean  # Removes build artifacts
```



## 🎮 How to Play
* **Left Player:** `W` (Up) / `S` (Down)
* **Right Player:** `Up Arrow` / `Down Arrow`
* **Pause:** Press `P` or `ESC` during a match.
* **Settings:** Change the paddle and ball colors in the Settings menu; your choice will be saved for next time!

## 📜 Credits
* **Framework:** [Raylib](https://www.raylib.com/)
* **Language:** C++17

---
*Created for the community — feel free to fork and improve!*
