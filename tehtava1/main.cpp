#include <iostream>
#include <ctime>


int game(int max)
{
    std::srand(std::time(nullptr));
    int number = std::rand() % max + 1;

    int guess = 0;
    int tries = 0;

    do {
        std::cout << "arvaa luku (0-" << max << "):";
        std::cin >> guess;

        if (guess < number) std::cout << "luku on suurempi" << std::endl;
        else if (guess > number) std::cout << "luku on pienempi" << std::endl;
        tries++;
    } while (guess != number);

    std::cout << "oikea vastaus!" << std::endl;

    return tries;
}


int main()
{
    int tries = game(40);
    std::cout << "yritykset: " << tries << std::endl;
}
