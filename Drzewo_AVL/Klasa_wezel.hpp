#ifndef KLASA_WEZEL_HPP
#define KLASA_WEZEL_HPP

#include <iostream>
#include <cstdlib>
#define TYP_DANYCH int

class Wezel
{
    public:

    Wezel* rodzic;
    Wezel* lewy;
    Wezel* prawy;
    TYP_DANYCH wartosc;
    int wr;

    Wezel();
    Wezel(TYP_DANYCH pocz_wartosc);

    void Wyswietl_Wezel();

};

#endif
