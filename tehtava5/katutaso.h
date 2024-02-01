#pragma once

#include "kerros.h"

class Katutaso : public Kerros
{
public:
    Katutaso();
    ~Katutaso();
    virtual void maaritaAsunnot() override;
    virtual double laskeKulutus(double hinta) override;

    Asunto *as1;
    Asunto *as2;
};
