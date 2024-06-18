#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 256

int main() {
    // Initialization
    const int screenWidth = 230;
    const int screenHeight = 295;
    InitWindow(screenWidth, screenHeight, "");

    char input[MAX_INPUT_LENGTH] = "\0";
    bool enterPressed = false;

    SetTargetFPS(60); 

    const int defaultX = 0;
    const int defaultY = 0;
    const int buttonUnderBarY = 50;

    const float buttonWidth = 57.5;
    const float buttonHeight = 48;
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


    Color normalColor = {93, 91, 95, 0};
    Color specialColor = {61, 57, 64, 0};
    Color operatorColor = {(uint8_t)242, (uint8_t)163, (uint8_t)60, (uint8_t)0};

    while (!WindowShouldClose()) {

        GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(WHITE));
        GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);
        // Special Buttons
        GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(specialColor));
        if (GuiButton((Rectangle){ firstColX, firstRowY, buttonWidth, buttonHeight }, "A C")) {
            memset(input, 0, MAX_INPUT_LENGTH);
        }
        if (GuiButton((Rectangle){ secondColX, firstRowY, buttonWidth, buttonHeight }, "+/-")) strcat(input, "DONT DO IT");
        if (GuiButton((Rectangle){ thirdColX, firstRowY, buttonWidth, buttonHeight }, "\%")) strcat(input, "%");

        // Normal Buttons
        GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(normalColor));
        if (GuiButton((Rectangle){ firstColX, secondRowY, buttonWidth, buttonHeight }, "7")) strcat(input, "7");
        if (GuiButton((Rectangle){ secondColX, secondRowY, buttonWidth, buttonHeight }, "8")) strcat(input, "8");
        if (GuiButton((Rectangle){ thirdColX, secondRowY, buttonWidth, buttonHeight }, "9")) strcat(input, "9");

        if (GuiButton((Rectangle){ firstColX, thirdRowY, buttonWidth, buttonHeight }, "4")) strcat(input, "4");
        if (GuiButton((Rectangle){ secondColX, thirdRowY, buttonWidth, buttonHeight }, "5")) strcat(input, "5");
        if (GuiButton((Rectangle){ thirdColX, thirdRowY, buttonWidth, buttonHeight }, "6")) strcat(input, "6");

        if (GuiButton((Rectangle){ firstColX, fourthRowY, buttonWidth, buttonHeight }, "1")) strcat(input, "1");
        if (GuiButton((Rectangle){ secondColX, fourthRowY, buttonWidth, buttonHeight }, "2")) strcat(input, "2");
        if (GuiButton((Rectangle){ thirdColX, fourthRowY, buttonWidth, buttonHeight }, "3")) strcat(input, "3");

        if (GuiButton((Rectangle){ firstColX, fifthRowY, buttonWidth*2, buttonHeight+10 }, "0")) strcat(input, "0");
        if (GuiButton((Rectangle){ thirdColX, fifthRowY, buttonWidth, buttonHeight+10 }, ".")) strcat(input, ".");

        // Operator buttons
        GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(operatorColor));
        if (GuiButton((Rectangle){ fourthColX, firstRowY, buttonWidth+10, buttonHeight }, "/")) strcat(input, "/");
        if (GuiButton((Rectangle){ fourthColX, secondRowY, buttonWidth+10, buttonHeight }, "*")) strcat(input, "*");
        if (GuiButton((Rectangle){ fourthColX, thirdRowY, buttonWidth+10, buttonHeight }, "-")) strcat(input, "-");
        if (GuiButton((Rectangle){ fourthColX, fourthRowY, buttonWidth+10, buttonHeight }, "+")) strcat(input, "+");
        if (GuiButton((Rectangle){ fourthColX, fifthRowY, buttonWidth+10, buttonHeight+10 }, "=")) {
            enterPressed = true;
        }

        GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, ColorToInt(specialColor));
        GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(specialColor));
        GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, ColorToInt(specialColor));
        GuiTextBox((Rectangle){ defaultX, defaultY, 300, 50 }, input, MAX_INPUT_LENGTH, true);

        // give me a list of all the rectangles from above
        Rectangle rectangles[] = {
            (Rectangle){ firstColX, firstRowY, buttonWidth, buttonHeight },
            (Rectangle){ secondColX, firstRowY, buttonWidth, buttonHeight },
            (Rectangle){ thirdColX, firstRowY, buttonWidth, buttonHeight },
            (Rectangle){ firstColX, secondRowY, buttonWidth, buttonHeight },
            (Rectangle){ secondColX, secondRowY, buttonWidth, buttonHeight },
            (Rectangle){ thirdColX, secondRowY, buttonWidth, buttonHeight },
            (Rectangle){ firstColX, thirdRowY, buttonWidth, buttonHeight },
            (Rectangle){ secondColX, thirdRowY, buttonWidth, buttonHeight },
            (Rectangle){ thirdColX, thirdRowY, buttonWidth, buttonHeight },
            (Rectangle){ firstColX, fourthRowY, buttonWidth, buttonHeight },
            (Rectangle){ secondColX, fourthRowY, buttonWidth, buttonHeight },
            (Rectangle){ thirdColX, fourthRowY, buttonWidth, buttonHeight },
            (Rectangle){ firstColX, fifthRowY, buttonWidth*2, buttonHeight+10 },
            (Rectangle){ thirdColX, fifthRowY, buttonWidth, buttonHeight+10 },
            (Rectangle){ fourthColX, firstRowY, buttonWidth+10, buttonHeight },
            (Rectangle){ fourthColX, secondRowY, buttonWidth+10, buttonHeight },
            (Rectangle){ fourthColX, thirdRowY, buttonWidth+10, buttonHeight },
            (Rectangle){ fourthColX, fourthRowY, buttonWidth+10, buttonHeight },
            (Rectangle){ fourthColX, fifthRowY, buttonWidth+10, buttonHeight+10 }
        };
        for(int i = 0; i < sizeof(rectangles)/sizeof(rectangles[0]); i++){
            DrawRectangleLinesEx(rectangles[i], 0.5, BLACK);
        };
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

