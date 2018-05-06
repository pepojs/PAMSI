#ifndef KLASA_GRA_HPP
#define KLASA_GRA_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

class Gra
{
    char ** Pole_gry;
    int Rozmiar;
    int IleWRzedzie;
    int FHeurystyczna(char gracz, int x, int y);

public:

    Gra(int rozmiar);
    Gra();
    ~Gra();

    void RysujePoleGry();
    int WypelniPoleX(int x, int y);
    int WypelniPoleO(int x, int y);
    void ZmienRozmiar(int rozmiar);
    void ZmienRzad(int rzad);
    int ZwrocRozmiar(){return Rozmiar;}

    int SprawdzanieStanuGryX(int x, int y);
    int SprawdzanieStanuGryO(int x, int y);

    int MinMax(char gracz, int zaglebienie, int alfa, int beta, int *f);

};




#endif // KLASA_GRA_HPP
