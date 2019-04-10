#include "logic.h"

void initializeAppState(AppState* appState) {
    // TA-TODO: Initialize everything that's part of this AppState struct here.
    // Suppose the struct contains random values, make sure everything gets
    // the value it should have when the app begins.
    appState->coins[0].x = 10;
    appState->coins[0].y = 10;
    appState->coins[1].x = 10;
    appState->coins[1].y = 120;
    appState->coins[2].x = 80;
    appState->coins[2].y = 32;
    appState->coins[3].x = 196;
    appState->coins[3].y = 67;

    appState->bombs[0].x = 118;
    appState->bombs[0].y = 102;
    appState->bombs[1].x = 120;
    appState->bombs[1].y = 10;
    appState->bombs[2].x = 40;
    appState->bombs[2].x = 60;

    appState->numOfCoinsCollected = 0;
    appState->gameOver = 0; 

    appState->playerxLocation = 220;
    appState->playeryLocation = 120;

    appState->stringxLocation = 225;
    appState->stringyLocation = 150;
}

// TA-TODO: Add any process functions for sub-elements of your app here.
// For example, for a snake game, you could have a processSnake function
// or a createRandomFood function or a processFoods function.
//
// e.g.:
// static Snake processSnake(Snake* currentSnake);
// static void generateRandomFoods(AppState* currentAppState, AppState* nextAppState);

// This function processes your current app state and returns the new (i.e. next)
// state of your application.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow) {
    /* TA-TODO: Do all of your app processing here. This function gets called
     * every frame.
     *
     * To check for key presses, use the KEY_JUST_PRESSED macro for cases where
     * you want to detect each key press once, or the KEY_DOWN macro for checking
     * if a button is still down.
     *
     * To count time, suppose that the GameBoy runs at a fixed FPS (60fps) and
     * that VBlank is processed once per frame. Use the vBlankCounter variable
     * and the modulus % operator to do things once every (n) frames. Note that
     * you want to process button every frame regardless (otherwise you will
     * miss inputs.)
     *
     * Do not do any drawing here.
     *
     * TA-TODO: VERY IMPORTANT! READ THIS PART.
     * You need to perform all calculations on the currentAppState passed to you,
     * and perform all state updates on the nextAppState state which we define below
     * and return at the end of the function. YOU SHOULD NOT MODIFY THE CURRENTSTATE.
     * Modifying the currentAppState will mean the undraw function will not be able
     * to undraw it later.
     */

    AppState nextAppState = *currentAppState;

    //Process movement
   if (KEY_DOWN(BUTTON_L, keysPressedNow)){
        if (nextAppState.playerxLocation > 0) {
            nextAppState.playerxLocation--;
        }
    } 
    if (KEY_DOWN(BUTTON_R, keysPressedNow)) {
        if (nextAppState.playerxLocation < WIDTH-20) {
            nextAppState.playerxLocation++;
        }
    } 
    if (KEY_DOWN(BUTTON_UP, keysPressedNow)) {
        if (nextAppState.playeryLocation > 0) {
            nextAppState.playeryLocation--;
        }
        
    }
    if (KEY_DOWN(BUTTON_DOWN, keysPressedNow)) {
        if (nextAppState.playeryLocation < HEIGHT - 40) {
            nextAppState.playeryLocation++;
        }
    }

    if (KEY_DOWN(BUTTON_SELECT, keysPressedNow)) {
        nextAppState.gameOver = 1;
    }
    UNUSED(keysPressedBefore);

    return nextAppState;
}

int * checkForCollisions(AppState* currentAppState) {
    static int counter[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int playerX = currentAppState->playerxLocation;
    int playerY = currentAppState->playeryLocation;
    for (int i = 0; i < 5; i++) {
        coin currCoin = currentAppState->coins[i];
        if (currCoin.x < playerX + 20 &&
            currCoin.x + 15 > playerX &&
            currCoin.y < playerY + 20 &&
            currCoin.y + 15 > playerY) {
            counter[i] = 1;
        }
    }
    currentAppState->numOfCoinsCollected++;
    return counter;
}
