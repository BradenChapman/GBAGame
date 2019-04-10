#include "draw.h"
#include "gba.h"
#include "logic.h"


#include <stdio.h>
#include <stdlib.h>

// TA-TODO: Include any header files for images generated by nin10kit.
// Example for the provided garbage image:
// #include "images/garbage.h"
#include "images/coin.h"
#include "images/Bomb.h"
#include "images/gamescreen.h"
// TA-TODO: Add any draw/undraw functions for sub-elements of your app here.
// For example, for a snake game, you could have a drawSnake function
// or a drawFood function
//
// e.g.:
// static void drawSnake(Snake* snake);
// static void drawFood(Food* food);
// static void drawCoins(coin coins[5]);
// static void drawBombs(bomb bombs[3]);

// This function will be used to draw everything about the app
// including the background and whatnot.
void fullDrawAppState(AppState *state) {
    // TA-TODO: IMPLEMENT.
    // drawCoins(state->coins);
    // drawBombs(state->bombs);
   UNUSED(state);
}

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. E.g. in a Snake game, erase the Snake, the food & the score.
void undrawAppState(AppState *state) {
    // TA-TODO: IMPLEMENT.
    UNUSED(state);
}

// This function will be used to draw things that might have moved in a frame.
// For example, in a Snake game, draw the snake, the food, the score.
void drawAppState(AppState *state) {
    // TA-TODO: IMPLEMENT.
    UNUSED(state);
}

void coverCoin(AppState *currentAppState, int pos) {
	drawRectDMA(currentAppState->coins[pos].x, currentAppState->coins[pos].y, 18, 18, CUSTOM);
	int numRemaining = 4 - currentAppState->numOfCoinsCollected;
    if (numRemaining == 3) {
        drawRectDMA(currentAppState->stringxLocation, currentAppState->stringyLocation, 10, 10, CUSTOM);
        drawString(currentAppState->stringxLocation, currentAppState->stringyLocation, "3", BLACK);
    } else if (numRemaining == 2) {
        drawRectDMA(currentAppState->stringxLocation, currentAppState->stringyLocation, 10, 10, CUSTOM);
        drawString(currentAppState->stringxLocation, currentAppState->stringyLocation, "2", BLACK);
    } else if (numRemaining == 1) {
        drawRectDMA(currentAppState->stringxLocation, currentAppState->stringyLocation, 10, 10, CUSTOM);
        drawString(currentAppState->stringxLocation, currentAppState->stringyLocation, "1", BLACK);
    } else if (numRemaining == 0) {
        drawRectDMA(currentAppState->stringxLocation, currentAppState->stringyLocation, 10, 10, CUSTOM);
        drawString(currentAppState->stringxLocation, currentAppState->stringyLocation, "0", BLACK);
    }
}