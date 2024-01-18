#pragma once


class Game
{
public:
    Game(int max);
    ~Game();

    void play();

private:
    void printGameResult() const;

    int max;
    int number;
    int guess;
    int tries;
};
