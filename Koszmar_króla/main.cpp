#include "Klasa_graf.hpp"

int main()
{
    Graf <int, int> graf;
    graf.DodajWierzcholek(1);
    graf.DodajWierzcholek(2);
    graf.DodajKrawedz(1,graf.ZwrocWskWierz(1),graf.ZwrocWskWierz(2));
    return 0;
}
