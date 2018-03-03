#include "Klasa_wezel.hpp"

using namespace std;

Wezel::Wezel()
{
    rodzic = NULL;
    lewy = NULL;
    prawy = NULL;
    wartosc = 0;
    wr = 0;
}

Wezel::Wezel(TYP_DANYCH pocz_wartosc)
{
    rodzic = NULL;
    lewy = NULL;
    prawy = NULL;
    wartosc = pocz_wartosc;
    wr = 0;
}

void Wezel::Wyswietl_Wezel()
{
    if(this->rodzic == NULL)
        cout<<"To jest korzen"<<endl;
    else
        cout<<"Wartosc wezla rodzica: "<<this->rodzic->wartosc<<endl;

    cout<<"Wartosc wezla: "<<this->wartosc<<endl;

    if(this->lewy == NULL)
        cout<<"Brak lewej galezi"<<endl;
    else
        cout<<"Wartosc lewej galezi: "<<this->lewy->wartosc<<endl;

    if(this->prawy == NULL)
        cout<<"Brak prawej galezi"<<endl;
    else
        cout<<"Wartosc prawej galezi: "<<this->prawy->wartosc<<endl;

    cout<<"Wspolczynnik rownowagi wezla: "<<this->wr<<endl;
}



