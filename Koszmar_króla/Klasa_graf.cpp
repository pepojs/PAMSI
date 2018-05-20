#include "Klasa_graf.hpp"

template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::DodajWierzcholek(TypWierzcholka wartosc)
{
    for(int i = 0; i < W.size(); i++)
    {
        if(W[i] == wartosc)
        {
            cout<<"Wezel o tej wartosci juz istnieje"<<endl;
            return;
        }
    }
    W.push_back(wartosc);
}

template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::DodajKrawedz(TypKrawedzi wartosc, TypWierzcholka* L, TypWierzcholka* P)
{
    Krawedz<TypKrawedzi, TypWierzcholka> pom(wartosc, L, P);
    K.push_back(pom);
}

template <typename TypKrawedzi, typename TypWierzcholka>
TypWierzcholka* Graf<TypKrawedzi, TypWierzcholka>::ZwrocWskWierz(TypWierzcholka wartosc)
{
    for(int i = 0; i < W.size(); i++)
    {
        if(W[i] == wartosc) return &W[i];
    }

    return NULL;
}

template class Graf<int,int>;
