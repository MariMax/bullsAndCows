//
//  gameEngine.cpp
//  BullCowGame
//
//  Created by Milovanov, Maxim (Ext) on 9/4/17.
//  Copyright © 2017 Maxim Milovanov. All rights reserved.
//

#include "gameEngine.h"
#include <iostream>
#include "FBullCowGame.hpp"

using FText = std::string;


void GameEngine::intro() const {
    std::cout << "Welcome to Bulls and Cows" << std::endl;
}

void GameEngine::playGame() {
    game.startGame();
}

bool GameEngine::askToPlayAgain() const {
    FText answer{""};
    std::cout << "Do you want to play again (y/N)? ";
    std::getline(std::cin, answer);
    return answer[0] == 'y' || answer[0] == 'Y';
}
