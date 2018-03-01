#ifndef KLASA_DRZEWO_HPP
#define KLASA_DRZEWO_HPP

#include <iostream>
#define TYP_DANYCH int


class DrzewoAVL
{
    DrzewoAVL* rodzic;
    DrzewoAVL* lewy;
    DrzewoAVL* prawy;
    TYP_DANYCH wartosc;
    int wr;

    void Rotacja_PP(DrzewoAVL* &korzen, DrzewoAVL* WGorny);
    void Rotacja_LL(DrzewoAVL* WGorny);
    void Rotacja_PL(DrzewoAVL* WGorny);
    void Rotacja_LP(DrzewoAVL* WGorny);

    public:

    DrzewoAVL();
    DrzewoAVL(TYP_DANYCH pocz_wartosc);

    void Dodawani_Wezla(DrzewoAVL* &korzen, TYP_DANYCH nowa_wartosc);
    void Usuwanie_Wezla();
};

#endif
