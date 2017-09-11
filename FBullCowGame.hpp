//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Milovanov, Maxim (Ext) on 9/4/17.
//  Copyright © 2017 Maxim Milovanov. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>

using FString = std::string;
using int32 = int;

enum class EGuessStatus {
    UNDEFINED,
    OK,
    NOT_ISOGRAM,
    TOO_SHORT,
    TOO_LONG,
};

struct FBullCowCount {
    int32 bulls = 0;
    int32 cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame();
    void startGame();
private:
    FString secretWord = "";
    int32 currentAttempt = 1;
    int32 maxAttempts = 3;
    bool bGameIsWon = false;

    int32 getCurrentAttemptNumber() const;
    int32 getMaxAttemptNumber() const;
    bool isGameWon() const;
    int32 getSecretWordLength() const;
    FString selectWord() const;
    bool checkIfIsogram(const FString&) const;
    FString getValidGuess() const;
    void printAttemptResults(const FBullCowCount&) const;
    EGuessStatus checkAGuess(const FString&) const;
    void printError(EGuessStatus) const;


    FBullCowCount submitValidGuess(FString&);
};

#endif /* FBullCowGame_hpp */
