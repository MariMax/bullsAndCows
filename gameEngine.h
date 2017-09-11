//
//  gameEngine.h
//  BullCowGame
//
//  Created by Milovanov, Maxim (Ext) on 9/4/17.
//  Copyright © 2017 Maxim Milovanov. All rights reserved.
//

#ifndef gameEngine_h
#define gameEngine_h

#include <string>
#include "FBullCowGame.hpp"

class GameEngine {
private:
    FBullCowGame game{};
public:
    void intro() const;
    void playGame();
    bool askToPlayAgain() const;
};

#endif /* gameEngine_h */
