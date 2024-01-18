#include "game.h"

#include <iostream>
#include <ctime>


Game::Game(int maxNumber)
    : maxNumber(maxNumber)
{
    std::srand(std::time(nullptr));
    randomNumber = std::rand() % maxNumber + 1;
    playerGuess = 0;
    numOfGuesses = 0;

    std::cout << "GAME CONSTRUCTOR: object initialized with 10 as a maximum value" << std::endl;
}

Game::~Game()
{
    std::cout << "GAME DESTRUCTOR: object cleared from stack memory" << std::endl;
}


void Game::play()
{
    do {
        std::cout << "Give your guess between 1-" << maxNumber << std::endl;
        std::cin >> playerGuess;

        if (playerGuess < randomNumber) std::cout << "Your guess is too small" << std::endl;
        else if (playerGuess > randomNumber) std::cout << "Your guess is too big" << std::endl;
        numOfGuesses++;
    } while (playerGuess != randomNumber);

    std::cout << "Your guess is right = " << playerGuess << std::endl;
    printGameResult();
}


void Game::printGameResult() const
{
    std::cout << "Your guessed the right answer = " << playerGuess << " with " << numOfGuesses << " guesses" << std::endl;
}
