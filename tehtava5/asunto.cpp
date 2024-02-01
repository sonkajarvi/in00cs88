#include "asunto.h"

#include <iostream>


Asunto::Asunto() {
    std::cout << "asunto luotu" << std::endl;
}

void Asunto::maarita(int _asukasMaara, int _neliot) {
    asukasMaara = _asukasMaara;
    neliot = _neliot;

    std::cout << "Asunto maaritetty asukkaita= " << asukasMaara << " nelioita= " << neliot << std::endl;
}

double Asunto::laskeKulutus(double hinta) {
    return asukasMaara * neliot * hinta;
}
