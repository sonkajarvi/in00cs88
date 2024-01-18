#include "game.h"

#include <iostream>
#include <ctime>


Game::Game(int max)
    : max(max)
{
    std::srand(std::time(nullptr));
    number = std::rand() % max + 1;
    guess = 0;
    tries = 0;

    std::cout << "GAME CONSTRUCTOR: object initialized with 10 as a maximum value" << std::endl;
}

Game::~Game()
{
    std::cout << "GAME DESTRUCTOR: object cleared from stack memory" << std::endl;
}


void Game::play()
{
    do {
        std::cout << "Give your guess between 1-" << max << std::endl;
        std::cin >> guess;

        if (guess < number) std::cout << "Your guess is too small" << std::endl;
        else if (guess > number) std::cout << "Your guess is too big" << std::endl;
        tries++;
    } while (guess != number);

    std::cout << "Your guess is right = " << guess << std::endl;
    printGameResult();
}


void Game::printGameResult() const
{
    std::cout << "Your guessed the right answer = " << guess << " with " << tries << " guesses" << std::endl;
}
