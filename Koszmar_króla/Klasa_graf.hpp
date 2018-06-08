#ifndef KLASA_GRAF_HPP
#define KLASA_GRAF_HPP

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename TypKrawedzi, typename TypWierzcholka>
class Wierzcholek;

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
struct StrAGwiazdka
{
    int FH;
    int FG;
    int FF;
    Wierzcholek<TypKrawedzi, TypWierzcholka> Rodzic;
    Wierzcholek<TypKrawedzi, TypWierzcholka> Wierz;
    int NumerWierz;

    StrAGwiazdka():Rodzic(0),Wierz(0){FH = 0; FG = 0; FF = 0; NumerWierz = 0;}
};

template <typename TypKrawedzi, typename TypWierzcholka>
class Graf
{
    vector <Krawedz<TypKrawedzi, TypWierzcholka> > K;
    vector <Wierzcholek<TypKrawedzi, TypWierzcholka> > W;

    void DFSRekurencja(char krol, Wierzcholek<TypKrawedzi, TypWierzcholka> wenzel, vector <Wierzcholek<TypKrawedzi, TypWierzcholka> > &w, vector <Wierzcholek<TypKrawedzi, TypWierzcholka> >odw);

public:
int FHeurystyczna(char aktualny, char cel);

    void DodajWierzcholek(TypWierzcholka wartosc);
    int DodajKrawedz(TypKrawedzi wartosc,Wierzcholek<TypKrawedzi, TypWierzcholka> * wartoscL,Wierzcholek<TypKrawedzi, TypWierzcholka> * wartoscP);
    Wierzcholek<TypKrawedzi, TypWierzcholka>* ZwrocWskWierz(TypWierzcholka wartosc);
    void TworzGraf(char kon, char wierza, char krol);
    void WyswietlGraf();
    void DFS(char kon, char wierza, char krol);
    void AGwiazdka(char kon, char wierza, char krol);
};


#endif // KLASA_GRAF_HPP
