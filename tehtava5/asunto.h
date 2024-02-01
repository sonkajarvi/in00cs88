#pragma once

class Asunto
{
public:
    Asunto();
    void maarita(int _asukasMaara, int _neliot);
    double laskeKulutus(double hinta);

    int asukasMaara;
    int neliot;
};
