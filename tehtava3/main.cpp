#include <iostream>
#include <string>


class Chef
{
public:
    Chef(const std::string& name) : name(name) {
        std::cout << "Chef " << name << " konstruktori" << std::endl;
    }
    ~Chef() {
        std::cout << "Chef " << name << " destruktori" << std::endl;
    }
    void makeSalad() {
        std::cout << "Chef " << name << " makes salad" << std::endl;
    }
    void makeSoup() {
        std::cout << "Chef " << name << " makes soup" << std::endl;
    }

protected:
    std::string name;
};


class ItalianChef : public Chef
{
public:
    ItalianChef(const std::string& name, int flour, int water) : Chef(name), flour(flour), water(water) {
        std::cout << "Chef " << name << " konstruktori" << std::endl;
    }
    const std::string& getName() const { return name; }
    void makePasta() {
        std::cout << "Chef " << name << " makes pasta with special recipe" << std::endl;
        std::cout << "Chef " << name << " users jauhot = " << flour << std::endl;
        std::cout << "Chef " << name << " users vesi = " << water << std::endl;
    }

private:
    int flour;
    int water;
};


int main()
{
//    Chef gr("Gordon Ramsay");
//    gr.makeSalad();
//    gr.makeSoup();
//    Chef ab("Anthony Bourdain");
//    ab.makeSalad();
//    ab.makeSoup();

    ItalianChef mario("Mario", 250, 100);
    mario.makePasta();
}

