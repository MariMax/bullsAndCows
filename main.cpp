//
//  main.cpp
//  BullCowGame
//
//  Created by Milovanov, Maxim (Ext) on 9/4/17.
//  Copyright © 2017 Maxim Milovanov. All rights reserved.
//

#include <iostream>
#include <string>
#include "gameEngine.h"

int main(int argc, const char * argv[]) {
    GameEngine gameEngine{};
    gameEngine.intro();
    do {
        gameEngine.playGame();
    } while (gameEngine.askToPlayAgain());

    return 0;
}
