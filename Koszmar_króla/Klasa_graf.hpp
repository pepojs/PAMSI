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
};

template <typename TypKrawedzi, typename TypWierzcholka>
class Graf
{
    vector <Krawedz<TypKrawedzi, TypWierzcholka> > K;
    vector <TypWierzcholka> W;

public:

    void DodajWierzcholek(TypWierzcholka wartosc);
    void DodajKrawedz(TypKrawedzi wartosc, TypWierzcholka* wartoscL,TypWierzcholka* wartoscP);
    TypWierzcholka* ZwrocWskWierz(TypWierzcholka wartosc);

};



#endif // KLASA_GRAF_HPP
