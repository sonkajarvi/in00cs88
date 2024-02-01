#include "katutaso.h"

#include <iostream>


Katutaso::Katutaso()
{
    std::cout << "Katutaso luotu" << std::endl;
}

void Katutaso::maaritaAsunnot()
{
    std::cout << "Maaritetaan 2 kpl katutason asuntoja" << std::endl;

    as1.maarita(2, 100);
    as2.maarita(2, 100);
}

double Katutaso::laskeKulutus(double hinta)
{
    double kulutus = 0;
    kulutus += as1.laskeKulutus(hinta);
    kulutus += as2.laskeKulutus(hinta);
    return kulutus;
}
