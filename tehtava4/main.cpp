#include "kerrostalo.h"

#include <iostream>


int main()
{
    Kerrostalo kerrostalo;
    kerrostalo.maaritaAsunnot();
    std::cout << "Kerrostalon kulutus, = " << kerrostalo.laskeKulutus(1) << std::endl;
}
