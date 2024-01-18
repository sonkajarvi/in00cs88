#pragma once


class Game
{
public:
    Game(int max);
    ~Game();

    void play();

private:
    void printGameResult() const;

    int maxNumber;
    int randomNumber;
    int playerGuess;
    int numOfGuesses;
};
