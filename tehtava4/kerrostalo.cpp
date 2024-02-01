#include "kerrostalo.h"

#include <iostream>


Kerrostalo::Kerrostalo()
{
    std::cout << "Kerrostalo luotu" << std::endl;
}

void Kerrostalo::maaritaAsunnot()
{
    eka.maaritaAsunnot();
    toka.maaritaAsunnot();
    kolmas.maaritaAsunnot();
    neljas.maaritaAsunnot();
}

double Kerrostalo::laskeKulutus(double hinta)
{
    double kulutus = 0;
    kulutus += eka.laskeKulutus(hinta);
    kulutus += toka.laskeKulutus(hinta);
    kulutus += kolmas.laskeKulutus(hinta);
    kulutus += neljas.laskeKulutus(hinta);
    return kulutus;
}
