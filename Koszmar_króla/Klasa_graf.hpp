#ifndef KLASA_GRAF_HPP
#define KLASA_GRAF_HPP

#include <iostream>
#include <vector>

using namespace std;

/*template <typename TypDanych>
class Wierzcholek
{
    TypDanych Dane;


};*/

template <typename TypKrawedzi, typename TypWierzcholka>
class Krawedz
{
    TypKrawedzi Dane;
    TypWierzcholka* Lewy;
    TypWierzcholka* Prawy;

public:

    Krawedz(TypKrawedzi wartosc, TypWierzcholka* L, TypWierzcholka* P){Lewy = L; Prawy = P; Dane = wartosc;}
    void Wyswietl() {cout<<"Wierzcholek 1: "<< *Lewy <<" Krawedz: "<<Dane<< " Wierzcholek 2: "<<*Prawy<<endl;}
    TypWierzcholka ZwrocWartWierzL() {return *Lewy;}
    TypWierzcholka ZwrocWartWierzP() {return *Prawy;}
    TypKrawedzi ZwrocWartKraw() {return Dane;}
};

template <typename TypKrawedzi, typename TypWierzcholka>
class Graf
{
    vector <Krawedz<TypKrawedzi, TypWierzcholka> > K;
    vector <TypWierzcholka> W;

public:

    void DodajWierzcholek(TypWierzcholka wartosc);
    int DodajKrawedz(TypKrawedzi wartosc, TypWierzcholka* wartoscL,TypWierzcholka* wartoscP);
    TypWierzcholka* ZwrocWskWierz(TypWierzcholka wartosc);
    void TworzGraf(char kon, char wierza, char krol);
    void WyswietlGraf();
};



#endif // KLASA_GRAF_HPP
