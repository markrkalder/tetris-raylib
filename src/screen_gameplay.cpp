/**********************************************************************************************
 *
 *   raylib - Advance Game template
 *
 *   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
 *
 *   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
 *
 *   This software is provided "as-is", without any express or implied warranty. In no event
 *   will the authors be held liable for any damages arising from the use of this software.
 *
 *   Permission is granted to anyone to use this software for any purpose, including commercial
 *   applications, and to alter it and redistribute it freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not claim that you
 *     wrote the original software. If you use this software in a product, an acknowledgment
 *     in the product documentation would be appreciated but is not required.
 *
 *     2. Altered source versions must be plainly marked as such, and must not be misrepresented
 *     as being the original software.
 *
 *     3. This notice may not be removed or altered from any source distribution.
 *
 **********************************************************************************************/

#include "raylib.h"
#include "screens.h"
#include <iostream>
#include <string>
using namespace std;

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
Texture2D tetrisBlock;
int dropRate = 5;
int tetrisBlockXCord;
int tetrisBlockYCord;
int yBounds;
enum GRID_SQUARE
{
    EMPTY,
    FULL
};
GRID_SQUARE currentObject[4][4];
#define GRID_WIDTH 12
#define GRID_HEIGHT 20
GRID_SQUARE grid[GRID_WIDTH][GRID_HEIGHT];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    tetrisBlock = LoadTexture("resources/tetrisblock2.png");
    tetrisBlockXCord = (GetScreenWidth() / 2);
    tetrisBlockYCord = 20;
    yBounds = GetScreenHeight() - 55;
    GRID_SQUARE straight[4][4] =
        {EMPTY, EMPTY, FULL, EMPTY,
         EMPTY, EMPTY, FULL, EMPTY,
         EMPTY, EMPTY, FULL, EMPTY,
         EMPTY, EMPTY, FULL, EMPTY};
    GRID_SQUARE tShaped[3][3];
    GRID_SQUARE lShaped[3][3];
    GRID_SQUARE box[2][2];
    memcpy(currentObject, straight, sizeof(currentObject));
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!

    // Press enter or tap to change to ENDING screen
    // if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    //{
    //    finishScreen = 1;
    //    PlaySound(fxCoin);
    //}

    DrawTexture(tetrisBlock, tetrisBlockXCord, tetrisBlockYCord, WHITE);

    if (yBounds > tetrisBlockYCord)
    {
        tetrisBlockYCord += dropRate;
        if (IsKeyPressed(KEY_RIGHT))
        {
            tetrisBlockXCord += 36;
        }
        if (IsKeyPressed(KEY_LEFT))
        {
            tetrisBlockXCord -= 36;
        }
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
    Vector2 pos = {20, 10};
    DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize * 2.0f, 4, MAROON);
    // DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
    int gameGridSizeX = GRID_WIDTH * 36;
    int gameGridSizeY = GRID_HEIGHT * 36;
    DrawRectangle(200, 80, gameGridSizeX, gameGridSizeY, BLACK);
    DrawTexture(tetrisBlock, tetrisBlockXCord, tetrisBlockYCord, WHITE);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}