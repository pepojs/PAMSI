#include "Klasa_drzewo.hpp"

DrzewoAVL::DrzewoAVL()
{
    rodzic = NULL;
    lewy = NULL;
    prawy = NULL;
    wartosc = 0;
    wr = 0;
}

DrzewoAVL::DrzewoAVL(TYP_DANYCH pocz_wartosc)
{
    rodzic = NULL;
    lewy = NULL;
    prawy = NULL;
    wartosc = pocz_wartosc;
    wr = 0;
}

void DrzewoAVL::Rotacja_PP(DrzewoAVL* &korzen, DrzewoAVL* Wezel_Gorny)
{
    DrzewoAVL* temp;
    DrzewoAVL* ojciecW;

    temp = Wezel_Gorny->prawy;
    ojciecW = Wezel_Gorny->rodzic;

    Wezel_Gorny->prawy = temp->lewy;

    if(Wezel_Gorny->prawy != NULL) Wezel_Gorny->prawy->rodzic = Wezel_Gorny;

    temp->lewy = Wezel_Gorny;
    temp->rodzic = ojciecW;
    Wezel_Gorny->rodzic = temp;

    if(ojciecW == NULL) korzen = temp;
    else if(ojciecW->lewy == Wezel_Gorny) ojciecW->lewy = temp;
    else ojciecW->prawy = temp;

    if(temp->wr == -1)
    {
        Wezel_Gorny->wr = 0;
        temp->wr = 0;
    }else
    {
        Wezel_Gorny->wr = -1;
        temp->wr = 1;
    }
}

void DrzewoAVL::Dodawani_Wezla(DrzewoAVL* &korzen, TYP_DANYCH nowa_wartosc)
{
    DrzewoAVL* Wkorzen;
    DrzewoAVL* temp = new DrzewoAVL(nowa_wartosc);

    Wkorzen = korzen;

    if(Wkorzen == NULL) korzen = temp;




}
