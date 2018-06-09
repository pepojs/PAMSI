#ifndef KLASA_GRAF_HPP
#define KLASA_GRAF_HPP

#include <iostream>
#include <vector>
#include <cmath>

#include "Klasa_wierz_kraw.hpp"

using namespace std;


template <typename TypKrawedzi, typename TypWierzcholka>
struct StrAGwiazdka
{
    int FH;
    int FG;
    int FF;
    vector<StrAGwiazdka> Rodzic;
    Wierzcholek<TypKrawedzi, TypWierzcholka> Wierz;
    int NumerWierz;

    StrAGwiazdka():Wierz(0){FH = 0; FG = 0; FF = 0; NumerWierz = 0;}
};

template <typename TypKrawedzi, typename TypWierzcholka>
ostream & operator<< (ostream &wy, const StrAGwiazdka<TypKrawedzi, TypWierzcholka> &s);

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
