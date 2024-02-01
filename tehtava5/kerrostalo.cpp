#include "kerrostalo.h"

#include <iostream>


Kerrostalo::Kerrostalo()
{
    eka = new Katutaso();
    toka = new Kerros();
    kolmas = new Kerros();
    neljas = new Kerros();

    std::cout << "Kerrostalo luotu" << std::endl;
}

Kerrostalo::~Kerrostalo()
{
    delete eka;
    delete toka;
    delete kolmas;
    delete neljas;

    std::cout << "Kerrostalo tuhottu" << std::endl;
}

void Kerrostalo::maaritaAsunnot()
{
    eka->maaritaAsunnot();
    toka->maaritaAsunnot();
    kolmas->maaritaAsunnot();
    neljas->maaritaAsunnot();
}

double Kerrostalo::laskeKulutus(double hinta)
{
    double kulutus = 0;
    kulutus += eka->laskeKulutus(hinta);
    kulutus += toka->laskeKulutus(hinta);
    kulutus += kolmas->laskeKulutus(hinta);
    kulutus += neljas->laskeKulutus(hinta);
    return kulutus;
}
