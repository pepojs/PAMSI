#ifndef KLASA_DRZEWO_HPP
#define KLASA_DRZEWO_HPP

#include <iostream>
#include <cstdlib>
#include "Klasa_wezel.hpp"

#define TYP_DANYCH int

class DrzewoAVL
{
    Wezel* korzen;

    void Rotacja_PP(Wezel* WGorny);
    void Rotacja_LL(Wezel* WGorny);
    void Rotacja_PL(Wezel* WGorny);
    void Rotacja_LP(Wezel* WGorny);

    public:

    DrzewoAVL();
    DrzewoAVL(TYP_DANYCH pocz_wartosc);
    ~DrzewoAVL();

    void Dodawani_Wezla(TYP_DANYCH nowa_wartosc);
    void Usuwanie_Wezla();
    void Przegladaj_Drzewo();
};

#endif
