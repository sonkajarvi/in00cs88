#include "katutaso.h"
#include "kerros.h"


class Kerrostalo
{
public:
    Kerrostalo();
    ~Kerrostalo();
    void maaritaAsunnot();
    double laskeKulutus(double hinta);

private:
    Katutaso *eka;
    Kerros *toka;
    Kerros *kolmas;
    Kerros *neljas;
};
