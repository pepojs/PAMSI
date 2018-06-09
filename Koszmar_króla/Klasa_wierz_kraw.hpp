#ifndef KLASA_WIERZ_KRAW_HPP
#define KLASA_WIERZ_KRAW_HPP

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

template <typename TypKrawedzi, typename TypWierzcholka>
class Krawedz;



template <typename TypKrawedzi, typename TypWierzcholka>
class Wierzcholek
{
    TypWierzcholka Dane;
    vector <Krawedz<TypKrawedzi, TypWierzcholka> > Kra;

public:

    Wierzcholek(TypWierzcholka wartosc){Dane = wartosc;}
    void UstawKrawedz(Krawedz<TypKrawedzi, TypWierzcholka> kra);
    TypWierzcholka ZwrocDane() {return Dane;}
    void Wyswietl(){cout<<"Wierzcholek: "<<Dane<<endl; for(unsigned int i = 0; i < Kra.size(); i++)Kra[i].Wyswietl();}
    unsigned int IloscKrawedzi() {return Kra.size();}
    Krawedz<TypKrawedzi, TypWierzcholka> ZwrocKrawedz(unsigned int numer){return Kra[numer];}

};



template <typename TypKrawedzi, typename TypWierzcholka>
class Krawedz
{
    TypKrawedzi Dane;
    Wierzcholek<TypKrawedzi, TypWierzcholka>* Lewy;
    Wierzcholek<TypKrawedzi, TypWierzcholka>* Prawy;

public:

    Krawedz(TypKrawedzi wartosc, Wierzcholek<TypKrawedzi, TypWierzcholka>* L, Wierzcholek<TypKrawedzi, TypWierzcholka>* P){Lewy = L; Prawy = P; Dane = wartosc;}
    void Wyswietl() {cout<<"Wierzcholek 1: "<< Lewy->ZwrocDane() <<" Krawedz: "<<Dane<< " Wierzcholek 2: "<<Prawy->ZwrocDane()<<endl;}
    TypWierzcholka ZwrocWartWierzL() {return Lewy->ZwrocDane();}
    TypWierzcholka ZwrocWartWierzP() {return Prawy->ZwrocDane();}
    Wierzcholek<TypKrawedzi, TypWierzcholka>* ZwrocWskWierzL(){return Lewy;}
    Wierzcholek<TypKrawedzi, TypWierzcholka>* ZwrocWskWierzP(){return Prawy;}
    TypKrawedzi ZwrocWartKraw() {return Dane;}
};



#endif
