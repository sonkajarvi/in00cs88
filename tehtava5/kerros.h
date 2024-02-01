#pragma once

#include "asunto.h"


class Kerros
{
public:
    Kerros();
    ~Kerros();
    virtual void maaritaAsunnot();
    virtual double laskeKulutus(double hinta);

    Asunto *as1;
    Asunto *as2;
    Asunto *as3;
    Asunto *as4;
};
