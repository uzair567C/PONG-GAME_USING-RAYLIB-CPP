/*

FUCTIONS:-
+———+————————————————————+———————————————————————————————————————————————————————————————————————————————————————————————————————————+
|   |    NAME            |   DESCRIPTION                                                                                             |
| 1 |    MAIN(MENU)      |   TO RUN MAIN MENU SCREEN FOR FURTHER STEP HAVING OPTIONS TO PLAY, SETTING, QUIT.                         |
| 2 |    GAME MODE       |   TO CHOSE OPTION IF YOU WANT TO PLAY WITH AN OTHER PLAYER OR WITH CPU.                                   |
| 3 |    PVP             |   MAIN GAME LOGIC TO PLAY WITH PLAYER.                                                                    |
| 4 |    PVC             |   MAIN GAME LOGIC TO PLAY WITH CPU.                                                                       |
| 5 |    SETTING         |   SETTING TO ADJUCT COLOR ONLY FOUR OPTIONS ARE AVAILABLE.                                                |
| 6 |    PAUSE MENU      |   THIS FUCTION HAVE TWO OPTION RESUME OR QUIT IT RETURN TRUE IF USER WANTS TO RESUME AND FALSE OTHERWISE. |
| 8 |    WIN             |   IT DISPLAY WINNER MESSAGE AND MENU BUTTON.                                                              |
| 7 |    COLORTOSTRING   |   TO CONVERT COLOR TO STRING THIS HELP US TO STORE DATA USING FSTREAM METHOD.                             |
+———+————————————————————+———————————————————————————————————————————————————————————————————————————————————————————————————————————+

*/

#include <iostream>
#include <fstream>
#include <raylib.h>
using namespace std;

const int Screenwidth = 1000;
const int Screenheight = 600;
bool playmusic = true;

void Setting()
{

    Rectangle button_lightgrey = {(Screenwidth / 2) - 300, (Screenheight / 2) - 50, 200, 50},
    button_blue = {(Screenwidth / 2) + 100, (Screenheight / 2) - 50, 200, 50},
    button_gold = {(Screenwidth / 2) - 300, (Screenheight / 2) + 50, 200, 50},
    button_red = {(Screenwidth / 2) + 100, (Screenheight / 2) + 50, 200, 50},
    button_music = {(Screenwidth / 2) - 300, (Screenheight / 2) + 150, 200, 50},
    button_quit = {(Screenwidth / 2) + 100, (Screenheight / 2) + 150, 200, 50};
    
    Color buttoncolor_lightgrey = LIGHTGRAY,
    buttoncolor_blue = BLUE,
    buttoncolor_gold = GOLD,
    buttoncolor_red = RED,
    buttoncolor_music = LIGHTGRAY,
    buttoncolor_quit = BLUE;
    
    SetWindowTitle("SETTING");
    Sound button = LoadSound("Extras/button.mp3");

    string selectedColor = "BLUE";
    fstream setting;
    setting.open("setting.txt", ios::in);
    if (setting.is_open()) {
        setting >> selectedColor;
        setting.close();
    }

    while (!WindowShouldClose())
    {
        Vector2 mousepoint = GetMousePosition();

        if (CheckCollisionPointRec(mousepoint, button_lightgrey))
        { // Check is mouse in on button or not
            buttoncolor_lightgrey = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_lightgrey = DARKBLUE;
                
                cout << "Set Entites color to light grey" << endl;
                selectedColor = "LIGHTGRAY";
                setting.open("setting.txt", ios::out);
                setting << selectedColor;
                setting.close();
            }
        }
        else if (CheckCollisionPointRec(mousepoint, button_blue))
        { // Check is mouse in on button or not
            buttoncolor_blue = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_blue = DARKBLUE;

                cout << "Set Entites color to blue" << endl;
                selectedColor = "BLUE";
                setting.open("setting.txt", ios::out);
                setting << selectedColor;
                setting.close();
            }
        }
        else if (CheckCollisionPointRec(mousepoint, button_gold))
        { // Check is mouse in on button or not
            buttoncolor_gold = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_gold = DARKBLUE;

                cout << "Set Entites color to gold" << endl;
                selectedColor = "GOLD";
                setting.open("setting.txt", ios::out);
                setting << selectedColor;
                setting.close();
            }
        }
        else if (CheckCollisionPointRec(mousepoint, button_red))
        { // Check is mouse in on button or not
            buttoncolor_red = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_red = DARKBLUE;

                cout << "Set Entites color to red" << endl;
                selectedColor = "RED";
                setting.open("setting.txt", ios::out);
                setting << selectedColor;
                setting.close();
            }
        }
        else if (CheckCollisionPointRec(mousepoint, button_music))
        { // Check is mouse in on button or not
            buttoncolor_music = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_music = DARKBLUE;

                cout << "change music status" << endl;
                playmusic = (playmusic == true) ? false : true;
            }
        }

        else if (CheckCollisionPointRec(mousepoint, button_quit))
        {
            buttoncolor_quit = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySound(button);
                buttoncolor_quit = DARKBLUE;
                return;
            }
        }
        
        else
        {
            buttoncolor_lightgrey = LIGHTGRAY;
            buttoncolor_blue = BLUE;
            buttoncolor_gold = GOLD;
            buttoncolor_red = RED;
            buttoncolor_music = LIGHTGRAY;
            buttoncolor_quit = LIGHTGRAY;
        }
        
        // Draw on screen.
        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawText("SETTING", Screenwidth / 2 - (MeasureText("SETTING", 100) / 2), Screenheight / 5, 100, BLUE);
        
        
        DrawRectangleRec(button_lightgrey, buttoncolor_lightgrey);
        DrawText((selectedColor == "LIGHTGRAY") ? "(LIGHT GREY)" : "LIGHT GREY", button_lightgrey.x + 39, button_lightgrey.y + 15, 20, BLACK);
        
        DrawRectangleRec(button_blue, buttoncolor_blue);
        DrawText((selectedColor == "BLUE") ? "(BLUE)" : "BLUE", button_blue.x + 74, button_blue.y + 15, 20, BLACK);
        
        DrawRectangleRec(button_gold, buttoncolor_gold);
        DrawText((selectedColor == "GOLD") ? "(GOLD)" : "GOLD", button_gold.x + 74, button_gold.y + 15, 20, BLACK);
        
        DrawRectangleRec(button_red, buttoncolor_red);
        DrawText((selectedColor == "RED") ? "(RED)" : "RED", button_red.x + 79, button_red.y + 15, 20, BLACK);
        
        DrawRectangleRec(button_quit, buttoncolor_quit);
        DrawText("BACK", button_quit.x + 74, button_quit.y + 15, 20, BLACK);
        
        DrawRectangleRec(button_music, buttoncolor_music);
        const char* musicStatus = playmusic ? "MUSIC: ON" : "MUSIC: OFF";
        DrawText(musicStatus, button_music.x + (200 - MeasureText(musicStatus, 20)) / 2, button_music.y + (50 - 20) / 2, 20, BLACK);
        EndDrawing();
    }
}

Color settingcolor()
{
    fstream setting;
    Color Entities_color = BLUE;

    setting.open("setting.txt", ios::in);
    if (setting.is_open())
    {
        string colorname;
        setting >> colorname;
        if (colorname == "RED")
            Entities_color = RED;
        else if (colorname == "GOLD")
            Entities_color = GOLD;
        else if (colorname == "LIGHTGRAY")
            Entities_color = LIGHTGRAY;
        else
            Entities_color = BLUE;
    }
    setting.close();
    return Entities_color;
}

bool pause_menu()
{

    Rectangle buttonbounds_resume = {(Screenwidth / 2) - 100, (Screenheight / 2) - 30, 200, 50};
    Rectangle buttonbounds_settings = {(Screenwidth / 2) - 100, (Screenheight / 2) + 30, 200, 50};
    Rectangle buttonbounds_menu = {(Screenwidth / 2) - 100, (Screenheight / 2) + 90, 200, 50};

    Color buttoncolor_resume = BLUE, buttoncolor_settings = BLUE, buttoncolor_menu = BLUE;
    Sound button = LoadSound("Extras/button.mp3");

    while (!WindowShouldClose())
    {
        Vector2 mousepoint = GetMousePosition();

        SetWindowTitle("PAUSE");

        if (CheckCollisionPointRec(mousepoint, buttonbounds_resume))
        { // Check is mouse in on button or not
            buttoncolor_resume = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_resume = DARKBLUE;

                // Perform button resume action
                cout << "RESUME" << endl;
                return true;
            }
        }

        else if (CheckCollisionPointRec(mousepoint, buttonbounds_settings))
        { // Check is mouse in on button or not
            buttoncolor_settings = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_settings = DARKBLUE;

                cout << "Setting" << endl;
                Setting();
            }
        }

        else if (CheckCollisionPointRec(mousepoint, buttonbounds_menu))
        {
            buttoncolor_menu = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySound(button);
                buttoncolor_menu = DARKBLUE;

                // Perform button menu action here
                std::cout << "Menu" << std::endl;
                return false;
            }
        }
        else
        {
            buttoncolor_resume = BLUE;
            buttoncolor_menu = BLUE;
        }

        // Draw on screen.
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("PAUSE MENU", Screenwidth / 2 - 326, Screenheight / 5, 100, BLUE);

        DrawRectangleRec(buttonbounds_resume, buttoncolor_resume);
        DrawText("RESUME", buttonbounds_resume.x + (200 - MeasureText("RESUME", 20)) / 2, buttonbounds_resume.y + 15, 20, WHITE);
        
        DrawRectangleRec(buttonbounds_settings, buttoncolor_settings);
        DrawText("SETTINGS", buttonbounds_settings.x + (200 - MeasureText("SETTINGS", 20)) / 2, buttonbounds_settings.y + 15, 20, WHITE);

        DrawRectangleRec(buttonbounds_menu, buttoncolor_menu);
        DrawText("CHANGE MODE", buttonbounds_menu.x + (200 - MeasureText("CHANGE MODE", 20)) / 2, buttonbounds_menu.y + (50 - 20) / 2, 20, WHITE);

        EndDrawing();
    }
    return true;
}

void won(const string player)
{
    Rectangle buttonbounds_menu = {(Screenwidth / 2) - 100, (Screenheight / 2) + 100, 200, 50};
    Color buttoncolor_menu = BLUE;
    Sound button = LoadSound("Extras/button.mp3");
    while (!WindowShouldClose())
    {
        Vector2 mousepoint = GetMousePosition();

        SetWindowTitle("WON");

        if (CheckCollisionPointRec(mousepoint, buttonbounds_menu))
        {
            buttoncolor_menu = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySound(button);
                buttoncolor_menu = DARKBLUE;

                // Perform button menu action here
                cout << "Menu" << endl;
                return;
            }
        }
        else
        {
            buttoncolor_menu = BLUE;
        }

        // Draw on screen.
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText(player.c_str(), Screenwidth / 2 - (MeasureText(player.c_str(), 100) / 2), Screenheight / 5, 100, BLUE);

        DrawRectangleRec(buttonbounds_menu, buttoncolor_menu);
        DrawText("PLAY AGAIN", buttonbounds_menu.x + (200 - MeasureText("PLAY AGAIN", 20)) / 2, buttonbounds_menu.y + (50 - 20) / 2, 20, WHITE);

        EndDrawing();
    }
}

void pvp(Color color)
{
    // main game

    Rectangle player_1 = {(float)20, (float)Screenheight / 2, 25, 100},
              player_2 = {(float)Screenwidth - 50, (float)Screenheight / 2, 25, 100};

    Vector2 ball = {(float)(Screenwidth) / 2, (float)(Screenheight / 2)};

    int ball_speed_x = 7, ball_speed_y = 7;
    int player_1_score = 0, player_2_score = 0;
    color = settingcolor();

    cout << "Pong game using raylib by Muhammad Uzair" << endl;
    SetWindowTitle("PONG");
    SetWindowFocused();
    Sound ball_bounce = LoadSound("Extras/ball_bounce.wav"), goal = LoadSound("Extras/goal.wav");
    Music music = LoadMusicStream("Extras/music.mp3");
    SetMusicVolume(music, 0.7);
    SetMusicPitch(music, 1);
    PlayMusicStream(music);

    while (true)
    {
        if (playmusic)
            UpdateMusicStream(music);

        // Paddle 1 control
        if (player_1.y >= 20)
            if (IsKeyDown(KEY_W))
            {
                player_1.y -= 10.0;
            }
        if (player_1.y + 120 <= Screenheight)
            if (IsKeyDown(KEY_S))
            {
                player_1.y += 10.0;
            }

        // Paddle 2 control
        if (player_2.y - 20 >= 0)
            if (IsKeyDown(KEY_UP))
            {
                player_2.y -= 10.0;
            }
        if (player_2.y + 120 <= Screenheight)
            if (IsKeyDown(KEY_DOWN))
            {
                player_2.y += 10.0;
            }

        ball.x += ball_speed_x;
        ball.y -= ball_speed_y;

        Vector2 ballpoint = {ball.x, ball.y};

        // Is ball miss the paddle
        if ((ball.x - 14) <= 0)
        {
            ball = {(float)Screenwidth / 2, (float)Screenheight / 2};
            player_2_score += 1;
            cout << "player 2 goal" << endl;
            PlaySound(goal);
        }
        if ((ball.x + 14) >= (Screenwidth))
        {
            ball = {(float)Screenwidth / 2, (float)Screenheight / 2};
            player_1_score += 1;
            cout << "player 1 goal" << endl;
            PlaySound(goal);
        }

        // Make ball bounce when collide with
        if (CheckCollisionPointRec(ballpoint, player_1))
        {
            ball_speed_x = -ball_speed_x;
            PlaySound(ball_bounce);
        }

        if (CheckCollisionPointRec(ballpoint, player_2))
        {
            ball_speed_x = -ball_speed_x;
            PlaySound(ball_bounce);
        }

        // Is ball collide to upper or lower wall if yes change direction.
        if ((ball.y - 14) <= 0)
        {
            ball_speed_y = -ball_speed_y;
        }
        if ((ball.y + 14) >= (Screenheight))
        {
            ball_speed_y = -ball_speed_y;
        }

        // Check for win condition
        if (player_1_score >= 10 || player_2_score >= 10)
        {
            won((player_1_score >= 10) ? "PLAYER 1 WON!" : "PLAYER 2 WON!");
            break;
        }

        // Call pause menu
        if (IsKeyReleased(KEY_ESCAPE))
        {
            if (!pause_menu())
            {
                break;
            }
            color = settingcolor();
        }

        // update screen
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextEx(GetFontDefault(), TextFormat("%i", player_1_score), {(float)(Screenwidth / 2 - 65), 20}, 30, 3.0f, color);
        DrawTextEx(GetFontDefault(), TextFormat("%i", player_2_score), {(float)(Screenwidth / 2 + 50), 20}, 30, 3.0f, color);

        DrawLine(Screenwidth / 2, 0, Screenwidth / 2, Screenheight, color);

        DrawRectangleRec(player_1, color);
        DrawRectangleRec(player_2, color);

        DrawCircleV(ball, 14, color);

        EndDrawing();
    }
    UnloadSound(goal);
    UnloadSound(ball_bounce);
    UnloadMusicStream(music);
}
void pvc(Color color)
{
    // main game

    Rectangle player_1 = {(float)20, (float)Screenheight / 2, 25, 100},
              cpu = {(float)Screenwidth - 50, (float)Screenheight / 2, 25, 100};

    Vector2 ball = {(float)(Screenwidth) / 2, (float)(Screenheight / 2)};

    int ball_speed_x = 7, ball_speed_y = 7;
    int player_score = 0, cpu_score = 0;

    color = settingcolor();

    cout << "Pong game using raylib by Muhammad Uzair" << endl;
    SetWindowTitle("PONG");
    SetWindowFocused();
    Sound ball_bounce = LoadSound("Extras/ball_bounce.wav"), goal = LoadSound("Extras/goal.wav");
    Music music = LoadMusicStream("Extras/music.mp3");
    SetMusicVolume(music, 0.7);
    SetMusicPitch(music, 1);
    PlayMusicStream(music);

    while (true)
    {
        if (playmusic)
            UpdateMusicStream(music);
        // Paddle 1 control
        if (player_1.y >= 20)
            if (IsKeyDown(KEY_W))
            {
                player_1.y -= 10.0;
            }
        if (player_1.y + 120 <= Screenheight)
            if (IsKeyDown(KEY_S))
            {
                player_1.y += 10.0;
            }

        // cpu control
        if ((cpu.y - 20 >= 0) && (ball.y < (cpu.y + 100)))
        {
            cpu.y -= 10.0;
        }
        if ((cpu.y + 120 <= Screenheight) && (ball.y > (cpu.y + 100)))
        {
            cpu.y += 10.0;
        }

        ball.x += ball_speed_x;
        ball.y -= ball_speed_y;

        Vector2 ballpoint = {ball.x, ball.y};

        // Is ball miss the paddle
        if ((ball.x - 14) <= 0)
        {
            ball = {(float)Screenwidth / 2, (float)Screenheight / 2};
            cpu_score += 1;
            cout << "player 2 goal" << endl;
            PlaySound(goal);
        }
        if ((ball.x + 14) >= (Screenwidth))
        {
            ball = {(float)Screenwidth / 2, (float)Screenheight / 2};
            player_score += 1;
            cout << "player 1 goal" << endl;
            PlaySound(goal);
        }
        if (player_score >= 10 || cpu_score >= 10)
        {
            won((player_score >= 10) ? "YOU WON!" : "CPU WON!");
            break;
        }

        // Make ball bounce when collide with
        if (CheckCollisionPointRec(ballpoint, player_1))
        {
            ball_speed_x = -ball_speed_x;
            PlaySound(ball_bounce);
        }

        if (CheckCollisionPointRec(ballpoint, cpu))
        {
            ball_speed_x = -ball_speed_x;
            PlaySound(ball_bounce);
        }

        // Is ball collide to upper or lower wall if yes change direction.
        if ((ball.y - 14) <= 0)
        {
            ball_speed_y = -ball_speed_y;
        }
        if ((ball.y + 14) >= (Screenheight))
        {
            ball_speed_y = -ball_speed_y;
        }

        // Call pause menu
        if (IsKeyReleased(KEY_ESCAPE))
        {
            if (!pause_menu())
            {
                break;
            }
            color = settingcolor();
        }

        // update screen
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextEx(GetFontDefault(), TextFormat("%i", player_score), {(float)(Screenwidth / 2 - 65), 20}, 30, 3.0f, color);
        DrawTextEx(GetFontDefault(), TextFormat("%i", cpu_score), {(float)(Screenwidth / 2 + 50), 20}, 30, 3.0f, color);

        DrawLine(Screenwidth / 2, 0, Screenwidth / 2, Screenheight, color);

        DrawRectangleRec(player_1, color);
        DrawRectangleRec(cpu, color);

        DrawCircleV(ball, 14, color);

        EndDrawing();
    }
    UnloadSound(ball_bounce);
    UnloadSound(goal);
    UnloadMusicStream(music);
}

void game_mode_selection(Color Entities_color)
{
    Rectangle button_pvp = {(Screenwidth / 2) - 400, (Screenheight / 2), 300, 50},
              button_pvc = {(Screenwidth / 2) + 100, (Screenheight / 2), 300, 50},
              button_menu = {(Screenwidth / 2) - 150, (Screenheight / 2) + 100, 300, 50};

    Color buttoncolor_pvp = BLUE,
          buttoncolor_pvc = BLUE,
          buttoncolor_menu = BLUE;

    SetWindowTitle("MODE");
    Sound button = LoadSound("Extras/button.mp3");
    while (!WindowShouldClose())
    {
        Vector2 mousepoint = GetMousePosition();

        if (CheckCollisionPointRec(mousepoint, button_pvp))
        { // Check is mouse in on button or not
            buttoncolor_pvp = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_pvp = DARKBLUE;

                cout << "Playing person vs person mode." << endl;
                pvp(Entities_color);
            }
        }

        else if (CheckCollisionPointRec(mousepoint, button_pvc))
        { // Check is mouse in on button or not
            buttoncolor_pvc = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_pvc = DARKBLUE;

                cout << "Playing person vs cpu mode." << endl;
                pvc(Entities_color);
            }
        }
        else if (CheckCollisionPointRec(mousepoint, button_menu))
        { // Check is mouse in on button or not
            buttoncolor_menu = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            { // Check is mouse button pressed
                PlaySound(button);
                buttoncolor_menu = DARKBLUE;
                return;
            }
        }

        else
        {
            buttoncolor_pvp = BLUE;
            buttoncolor_pvc = BLUE;
            buttoncolor_menu = BLUE;
        }

        // Draw on screen.
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("MODE", Screenwidth / 2 - (MeasureText("MODE", 100) / 2), Screenheight / 5, 100, BLUE);

        DrawRectangleRec(button_pvp, buttoncolor_pvp);
        DrawText("PERSON VS PERSON", button_pvp.x + (300 - MeasureText("PERSON VS PERSON", 20)) / 2, button_pvp.y + (50 - 20) / 2, 20, WHITE);

        DrawRectangleRec(button_pvc, buttoncolor_pvc);
        DrawText("PERSON VS CPU", button_pvc.x + (300 - MeasureText("PERSON VS CPU", 20)) / 2, button_pvc.y + (50 - 20) / 2, 20, WHITE);

        DrawRectangleRec(button_menu, buttoncolor_menu);
        DrawText("MENU", button_menu.x + (300 - MeasureText("MENU", 20)) / 2, button_menu.y + (50 - 20) / 2, 20, WHITE);

        EndDrawing();
    }
}

string colortostring(Color c)
{
    // fstream would not store color directly so in this fuction we convert selected colors to string.
    if (RED.r == c.r && RED.g == c.g && RED.b == c.b)
        return "RED";
    if (GOLD.r == c.r && GOLD.g == c.g && GOLD.b == c.b)
        return "GOLD";
    if (LIGHTGRAY.r == c.r && LIGHTGRAY.g == c.g && LIGHTGRAY.b == c.b)
        return "LIGHTGRAY";
    return "BLUE";
}

int main()
{

    Color Entities_color = settingcolor();

    InitWindow(Screenwidth, Screenheight, "MENU");
    SetTargetFPS(60);

    // set the top-left corner icon.
    Image icon = LoadImage("Extras/ping-pong.png");
    SetWindowIcon(icon);
    UnloadImage(icon);

    InitAudioDevice();
    Sound button = LoadSound("Extras/button.mp3");

    Rectangle buttonbounds_1 = {(Screenwidth / 2) - 100, (Screenheight / 2) - 30, 200, 50};
    Rectangle buttonbounds_2 = {(Screenwidth / 2) - 100, (Screenheight / 2) + 30, 200, 50};
    Rectangle buttonbounds_3 = {(Screenwidth / 2) - 100, (Screenheight / 2) + 90, 200, 50};
    Color buttoncolor_resume = BLUE, buttoncolor_menu = BLUE, buttoncolor_3 = BLUE;

    while (!WindowShouldClose())
    {
        Vector2 mousepoint = GetMousePosition();

        SetWindowTitle("MENU");

        if (CheckCollisionPointRec(mousepoint, buttonbounds_1))
        {
            buttoncolor_resume = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySound(button);
                buttoncolor_resume = DARKBLUE;

                // Perform button 1 action here
                game_mode_selection(Entities_color);
            }
        }

        else if (CheckCollisionPointRec(mousepoint, buttonbounds_2))
        {
            buttoncolor_menu = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySound(button);
                buttoncolor_menu = DARKBLUE;
                Setting();
                Entities_color = settingcolor();
                cout << "Setting" << endl;
            }
        }

        else if (CheckCollisionPointRec(mousepoint, buttonbounds_3))
        {
            buttoncolor_3 = DARKGRAY;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySound(button);
                buttoncolor_3 = DARKBLUE;

                // Perform button 3 action here
                cout << "Quit" << endl;
                break;
            }
        }
        else
        {
            buttoncolor_resume = BLUE;
            buttoncolor_menu = BLUE;
            buttoncolor_3 = BLUE;
        }

        // draw on screem
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("MENU", Screenwidth / 2 - (MeasureText("MENU", 100) / 2), Screenheight / 5, 100, BLUE);

        DrawRectangleRec(buttonbounds_1, buttoncolor_resume);
        DrawText("Play", buttonbounds_1.x + 80, buttonbounds_1.y + 15, 20, WHITE);

        DrawRectangleRec(buttonbounds_2, buttoncolor_menu);
        DrawText("Setting", buttonbounds_2.x + 65, buttonbounds_2.y + 15, 20, WHITE);

        DrawRectangleRec(buttonbounds_3, buttoncolor_3);
        DrawText("Quit", buttonbounds_3.x + 80, buttonbounds_3.y + 15, 20, WHITE);

        EndDrawing();
    }
    CloseAudioDevice();
}