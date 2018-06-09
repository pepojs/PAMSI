#include "Klasa_wierz_kraw.hpp"

template <typename TypKrawedzi, typename TypWierzcholka>
void Wierzcholek<TypKrawedzi, TypWierzcholka>::UstawKrawedz(Krawedz<TypKrawedzi, TypWierzcholka> kra)
{
    if(kra.ZwrocWartWierzL() == Dane)
        Kra.push_back(kra);
    else
        Kra.push_back(Krawedz<TypKrawedzi, TypWierzcholka>(kra.ZwrocWartKraw(),kra.ZwrocWskWierzP(), kra.ZwrocWskWierzL()));
}

template class Wierzcholek<int,char>;
