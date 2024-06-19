#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 256

// Custom Text Box that allows for input as I want it, since the library default is not fun for me to work with.
void DrawCustomTextBox(Font font, Rectangle bounds, char *text)
{
    Color borderColor = borderColor;
    Color backgroundColor = LIGHTGRAY;
    Color otherColor = {40, 37, 43, 255};
    Color textColor = WHITE;

    // Initialize text to "0" if empty
    if (strlen(text) == 0)
    {
        strcpy(text, "0");
    }
    else if (strlen(text) == 2 && text[0] == '0')
    {
        memmove(text, text + 1, strlen(text));
    }
    DrawRectangleRec(bounds, otherColor);

    int key = GetKeyPressed();
    while (key > 0)
    {
        bool shiftDown = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);

        if ((key >= 32) && (key <= 125) && (strlen(text) < MAX_INPUT_LENGTH - 1))
        {
            if (shiftDown)
            {
                switch (key)
                {
                case KEY_EQUAL:
                    strcat(text, "+");
                    break;
                case KEY_EIGHT:
                    strcat(text, "*");
                    break;
                case KEY_FIVE:
                    strcat(text, "%");
                    break;
                // Add more cases for other shifted keys if needed
                default:
                    break;
                }
            }
            else
            {
                if (key == KEY_EQUAL)
                {
                    strcat(text, "=");
                }
                else
                {
                    int len = strlen(text);
                    text[len] = (char)key;
                    text[len + 1] = '\0';
                }
            }
        }

        if (key == KEY_BACKSPACE)
        {
            if (IsKeyDown(KEY_LEFT_CONTROL)) {
                memset(text, 0, MAX_INPUT_LENGTH);
            }
            else{
            int len = strlen(text);
            if (len > 0)
            {
                text[len - 1] = '\0';
            }
            }
        }

        key = GetKeyPressed();
    }

    Vector2 textSize = MeasureTextEx(font, text, 40, 2);
    float textX = bounds.x + bounds.width - textSize.x - 10; // Adjust 10 for padding
    float textY = bounds.height - textSize.y;

    // Draw the text
    DrawTextEx(font, text, (Vector2){textX, textY}, 40, 2, textColor);
}

int main()
{
    SetTraceLogLevel(LOG_NONE);
    // Initialization
    const int screenWidth = 230;
    const int screenHeight = 295;
    InitWindow(screenWidth, screenHeight, "");

    char input[MAX_INPUT_LENGTH] = "\0";
    bool enterPressed = false;

    SetTargetFPS(60);
    Font customFont = LoadFontEx("../fonts/helvetica.ttf", 64, 0, 0);
    SetTextureFilter(customFont.texture, TEXTURE_FILTER_POINT);
    GuiSetFont(customFont);

    const int defaultX = 0;
    const int defaultY = 0;
    const int buttonUnderBarY = 50;

    const float buttonWidth = 57.5;
    const float buttonHeight = 48;
    const int padding = 0;

    const int firstRowY = buttonUnderBarY + padding;
    const int secondRowY = firstRowY + buttonHeight + padding;
    const int thirdRowY = secondRowY + buttonHeight + padding;
    const int fourthRowY = thirdRowY + buttonHeight + padding;
    const int fifthRowY = fourthRowY + buttonHeight + padding;

    const int firstColX = defaultX;
    const int secondColX = defaultX + buttonWidth + padding;
    const int thirdColX = secondColX + buttonWidth + padding;
    const int fourthColX = thirdColX + buttonWidth + padding;

    Color normalColor = {93, 91, 95, 255};
    Color specialColor = {61, 57, 64, 255};
    Color operatorColor = {(uint8_t)242, (uint8_t)163, (uint8_t)60, (uint8_t)255};
    Color borderColor = {40, 37, 43, 255};

    while (!WindowShouldClose())
    {
        GuiSetStyle(DEFAULT, TEXT_SIZE, 18);
        GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(WHITE));

        GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);
        // Special Buttons
        GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(specialColor));
        if (GuiButton((Rectangle){firstColX, firstRowY, buttonWidth, buttonHeight}, "AC"))
        {
            memset(input, 0, MAX_INPUT_LENGTH);
        }
        if (GuiButton((Rectangle){secondColX, firstRowY, buttonWidth, buttonHeight}, "+/-"))
            strcat(input, "DONT DO IT");
        if (GuiButton((Rectangle){thirdColX, firstRowY, buttonWidth, buttonHeight}, "\%"))
            strcat(input, "%");

        // Normal Buttons
        GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(normalColor));
        if (GuiButton((Rectangle){firstColX, secondRowY, buttonWidth, buttonHeight}, "7"))
            strcat(input, "7");
        if (GuiButton((Rectangle){secondColX, secondRowY, buttonWidth, buttonHeight}, "8"))
            strcat(input, "8");
        if (GuiButton((Rectangle){thirdColX, secondRowY, buttonWidth, buttonHeight}, "9"))
            strcat(input, "9");

        if (GuiButton((Rectangle){firstColX, thirdRowY, buttonWidth, buttonHeight}, "4"))
            strcat(input, "4");
        if (GuiButton((Rectangle){secondColX, thirdRowY, buttonWidth, buttonHeight}, "5"))
            strcat(input, "5");
        if (GuiButton((Rectangle){thirdColX, thirdRowY, buttonWidth, buttonHeight}, "6"))
            strcat(input, "6");

        if (GuiButton((Rectangle){firstColX, fourthRowY, buttonWidth, buttonHeight}, "1"))
            strcat(input, "1");
        if (GuiButton((Rectangle){secondColX, fourthRowY, buttonWidth, buttonHeight}, "2"))
            strcat(input, "2");
        if (GuiButton((Rectangle){thirdColX, fourthRowY, buttonWidth, buttonHeight}, "3"))
            strcat(input, "3");

        if (GuiButton((Rectangle){firstColX, fifthRowY, buttonWidth * 2, buttonHeight + 10}, "0"))
            strcat(input, "0");
        if (GuiButton((Rectangle){thirdColX, fifthRowY, buttonWidth, buttonHeight + 10}, "."))
            strcat(input, ".");

        // Operator buttons
        GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(operatorColor));
        if (GuiButton((Rectangle){fourthColX, firstRowY, buttonWidth + 10, buttonHeight}, "/"))
            strcat(input, "/");
        if (GuiButton((Rectangle){fourthColX, secondRowY, buttonWidth + 10, buttonHeight}, "*"))
            strcat(input, "*");
        if (GuiButton((Rectangle){fourthColX, thirdRowY, buttonWidth + 10, buttonHeight}, "-"))
            strcat(input, "-");
        if (GuiButton((Rectangle){fourthColX, fourthRowY, buttonWidth + 10, buttonHeight}, "+"))
            strcat(input, "+");
        if (GuiButton((Rectangle){fourthColX, fifthRowY, buttonWidth + 10, buttonHeight + 10}, "="))
        {
            enterPressed = true;
        } 
        if (IsKeyPressed(KEY_ENTER)) {
            enterPressed = true;
        }

        if (enterPressed)
        {
            strcpy(input, "woops didn't implement");
            enterPressed = false;
        }

        // Draw vertical borders
        DrawLineEx((Vector2){secondColX, buttonUnderBarY}, (Vector2){secondColX, fifthRowY}, 1, borderColor);
        DrawLineEx((Vector2){thirdColX, buttonUnderBarY}, (Vector2){thirdColX, screenHeight}, 1, borderColor);
        DrawLineEx((Vector2){fourthColX, buttonUnderBarY}, (Vector2){fourthColX, screenHeight}, 1, borderColor);

        // Draw horizontal borders
        DrawLineEx((Vector2){firstColX, buttonUnderBarY}, (Vector2){screenWidth, buttonUnderBarY}, 1, borderColor);
        DrawLineEx((Vector2){firstColX, firstRowY}, (Vector2){screenWidth, firstRowY}, 1, borderColor);
        DrawLineEx((Vector2){firstColX, secondRowY}, (Vector2){screenWidth, secondRowY}, 1, borderColor);
        DrawLineEx((Vector2){firstColX, thirdRowY}, (Vector2){screenWidth, thirdRowY}, 1, borderColor);
        DrawLineEx((Vector2){firstColX, fourthRowY}, (Vector2){screenWidth, fourthRowY}, 1, borderColor);
        DrawLineEx((Vector2){firstColX, fifthRowY}, (Vector2){screenWidth, fifthRowY}, 1, borderColor);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawCustomTextBox(customFont, (Rectangle){defaultX, defaultY, 230, 50}, input);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
