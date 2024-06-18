#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Calculator");

    // Variables for GUI
    char input[128] = "\0";
    bool exitWindow = false;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose() && !exitWindow) {
        // Update
        // TODO: Implement calculator logic here

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // GUI controls
        if (GuiButton((Rectangle){ 10, 10, 100, 30 }, "Exit")) exitWindow = true;
        GuiTextBox((Rectangle){ 10, 50, 200, 30 }, input, 128, true);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}

