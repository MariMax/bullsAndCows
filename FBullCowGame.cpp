//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Milovanov, Maxim (Ext) on 9/4/17.
//  Copyright © 2017 Maxim Milovanov. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <iostream>
#include <unordered_set>
#include <algorithm>

using FString = std::string;
using int32 = int;
using TSet = std::unordered_set<char>;


int32 FBullCowGame::getMaxAttemptNumber() const { return maxAttempts;}
int32 FBullCowGame::getCurrentAttemptNumber() const { return currentAttempt;}
int32 FBullCowGame::getSecretWordLength() const { return static_cast<int32>(secretWord.length()); }

FBullCowGame::FBullCowGame():currentAttempt(1),maxAttempts(3) {}

FString FBullCowGame::selectWord() const {
    return "ant";
}

void FBullCowGame::startGame() {
    secretWord = selectWord();
    currentAttempt = 1;
    bGameIsWon = false;
    std::cout << "Can you guess the " << getSecretWordLength() << " letters isogram I'm thinking of?" << std::endl;
    while (getCurrentAttemptNumber() <= getMaxAttemptNumber() && !isGameWon()) {
        auto guess = getValidGuess();
        auto counts = submitValidGuess(guess);
        printAttemptResults(counts);
        std::cout << std::endl;
    }
}

FBullCowCount FBullCowGame::submitValidGuess(FString& guess) {
    currentAttempt++;
    std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
    
    FBullCowCount res;
    auto wowrdLength = secretWord.length();
    for(auto i = 0; i!=wowrdLength; ++i){
        for(auto j = 0; j!=wowrdLength; ++j){
            if (secretWord[i] == guess[j] && i == j){
                res.bulls+=1;
            }
            if (secretWord[i] == guess[j] && i !=j){
                res.cows+=1;
            }
        }
    }
    bGameIsWon = res.bulls == wowrdLength;
    
    return res;
}

FString FBullCowGame::getValidGuess() const {
    FString guess{""};
    EGuessStatus status = EGuessStatus::UNDEFINED;
    do {
        std::cout << "Attempt: " << getCurrentAttemptNumber();
        std::cout << " from: " << getMaxAttemptNumber();
        std::cout << " Take a guess: ";
        getline(std::cin, guess);
        status = checkAGuess(guess);
        printError(status);
    } while (status != EGuessStatus::OK);
    return guess;
}

void FBullCowGame::printAttemptResults(const FBullCowCount &guessCounts) const {
    if (isGameWon()){
        std::cout << "Congrats you've won!!!";
        return;
    }
    if (getMaxAttemptNumber() < getCurrentAttemptNumber()){
        std::cout << "Better luck next time!";
        return;
    }
    std::cout<< "You've got: " << guessCounts.bulls << " bulls and ";
    std::cout<< guessCounts.cows << " cows" << std::endl;
}

EGuessStatus FBullCowGame::checkAGuess(const FString& guess) const {
    if (guess.length() > secretWord.length()) return EGuessStatus::TOO_LONG;
    if (guess.length() < secretWord.length()) return EGuessStatus::TOO_SHORT;
    if (!checkIfIsogram(guess)) return EGuessStatus::NOT_ISOGRAM;
    return EGuessStatus::OK;
}

bool FBullCowGame::isGameWon() const {
    return bGameIsWon;
}

bool FBullCowGame::checkIfIsogram(const FString& guess) const {
    auto str = guess;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    TSet s{};
    for (auto i:str){
        s.insert(i);
    }
    return s.size() == str.length();
}

void FBullCowGame::printError(EGuessStatus status) const {
    switch (status) {
        case EGuessStatus::TOO_LONG:
            std::cout << "Please enter shorter word" << std::endl;
            break;
        case EGuessStatus::TOO_SHORT:
            std::cout << "Please enter longer word" << std::endl;
            break;
        case EGuessStatus::NOT_ISOGRAM:
            std::cout << "Please enter isogram" << std::endl;
            break;
            
        default:
            break;
    }
}
