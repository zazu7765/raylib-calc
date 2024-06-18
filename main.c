#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 256

int main() {
    // Initialization
    const int screenWidth = 230;
    const int screenHeight = 300;
    InitWindow(screenWidth, screenHeight, "Calculator");

    char input[MAX_INPUT_LENGTH] = "\0";
    bool enterPressed = false;

    SetTargetFPS(60); 

    const int defaultX = 0;
    const int defaultY = 0;
    const int buttonUnderBarY = 60;

    const int buttonWidth = 60;
    const int buttonHeight = 40;
    const int padding = 0;

    const int firstRowY = buttonUnderBarY +padding;
    const int secondRowY = firstRowY + buttonHeight + padding;
    const int thirdRowY = secondRowY + buttonHeight + padding;
    const int fourthRowY = thirdRowY + buttonHeight + padding;
    const int fifthRowY = fourthRowY + buttonHeight + padding;

    const int firstColX = defaultX;
    const int secondColX = defaultX + buttonWidth + padding;
    const int thirdColX = secondColX + buttonWidth + padding;
    const int fourthColX = thirdColX + buttonWidth + padding;

    while (!WindowShouldClose()) {

        if (GuiButton((Rectangle){ firstColX, firstRowY, buttonWidth, buttonHeight }, "AC")) {
            memset(input, 0, MAX_INPUT_LENGTH);
        }
        if (GuiButton((Rectangle){ secondColX, firstRowY, buttonWidth, buttonHeight }, "+/-")) strcat(input, "DONT DO IT");
        if (GuiButton((Rectangle){ thirdColX, firstRowY, buttonWidth, buttonHeight }, "\%")) strcat(input, "%");
        if (GuiButton((Rectangle){ fourthColX, firstRowY, buttonWidth, buttonHeight }, "/")) strcat(input, "/");

        if (GuiButton((Rectangle){ firstColX, secondRowY, buttonWidth, buttonHeight }, "7")) strcat(input, "7");
        if (GuiButton((Rectangle){ secondColX, secondRowY, buttonWidth, buttonHeight }, "8")) strcat(input, "8");
        if (GuiButton((Rectangle){ thirdColX, secondRowY, buttonWidth, buttonHeight }, "9")) strcat(input, "9");
        if (GuiButton((Rectangle){ fourthColX, secondRowY, buttonWidth, buttonHeight }, "*")) strcat(input, "*");

        if (GuiButton((Rectangle){ firstColX, thirdRowY, buttonWidth, buttonHeight }, "4")) strcat(input, "4");
        if (GuiButton((Rectangle){ secondColX, thirdRowY, buttonWidth, buttonHeight }, "5")) strcat(input, "5");
        if (GuiButton((Rectangle){ thirdColX, thirdRowY, buttonWidth, buttonHeight }, "6")) strcat(input, "6");
        if (GuiButton((Rectangle){ fourthColX, thirdRowY, buttonWidth, buttonHeight }, "-")) strcat(input, "-");

        if (GuiButton((Rectangle){ firstColX, fourthRowY, buttonWidth, buttonHeight }, "1")) strcat(input, "1");
        if (GuiButton((Rectangle){ secondColX, fourthRowY, buttonWidth, buttonHeight }, "2")) strcat(input, "2");
        if (GuiButton((Rectangle){ thirdColX, fourthRowY, buttonWidth, buttonHeight }, "3")) strcat(input, "3");
        if (GuiButton((Rectangle){ fourthColX, fourthRowY, buttonWidth, buttonHeight }, "+")) strcat(input, "+");

        if (GuiButton((Rectangle){ firstColX, fifthRowY, buttonWidth*2, buttonHeight }, "0")) strcat(input, "0");
        if (GuiButton((Rectangle){ thirdColX, fifthRowY, buttonWidth, buttonHeight }, ".")) strcat(input, ".");
        if (GuiButton((Rectangle){ fourthColX, fifthRowY, buttonWidth, buttonHeight }, "=")) {
            enterPressed = true;
        }


        if (GuiTextBox((Rectangle){ defaultX, defaultY, 300, 60 }, input, MAX_INPUT_LENGTH, true)){
            enterPressed = true;
        }

        if (enterPressed) {
            strcpy(input, "woops didn't implement");
            enterPressed = false;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}

