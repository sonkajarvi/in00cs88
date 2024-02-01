#include "kerrostalo.h"

#include <iostream>


int main()
{
    Kerrostalo *kerrostalo = new Kerrostalo();
    kerrostalo->maaritaAsunnot();
    std::cout << "Kerrostalon kulutus, = " << kerrostalo->laskeKulutus(1) << std::endl;
    delete kerrostalo;
}
