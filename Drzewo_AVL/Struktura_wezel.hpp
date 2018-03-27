#ifndef STRUKTURA_WEZEL_HPP
#define STRUKTURA_WEZEL_HPP

#include <iostream>
#include <cstdlib>
//#define TYP_DANYCH int

using namespace std;


template <typename TYP_DANYCH>
struct Wezel
{

    Wezel<TYP_DANYCH>* rodzic;
    Wezel<TYP_DANYCH>* lewy;
    Wezel<TYP_DANYCH>* prawy;
    TYP_DANYCH wartosc;
    int wr;

    Wezel();
    Wezel(TYP_DANYCH pocz_wartosc);

    void Wyswietl_Wezel();

};

template <typename TYP_DANYCH>
Wezel<TYP_DANYCH>::Wezel()
{
    rodzic = NULL;
    lewy = NULL;
    prawy = NULL;
    wartosc = 0;
    wr = 0;
}

template <typename TYP_DANYCH>Wezel<TYP_DANYCH>::Wezel(TYP_DANYCH pocz_wartosc)
{
    rodzic = NULL;
    lewy = NULL;
    prawy = NULL;
    wartosc = pocz_wartosc;
    wr = 0;
}

template <typename TYP_DANYCH>void Wezel<TYP_DANYCH>::Wyswietl_Wezel()
{
    if(this != NULL)
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

    }else cout<<"Drzewo jest puste"<<endl;
}





#endif
