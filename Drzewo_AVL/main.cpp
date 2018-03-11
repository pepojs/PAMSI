#include <iostream>
#include "Klasa_drzewo.hpp"

int main()
{
    DrzewoAVL drzewo(1);

    drzewo.Dodawani_Wezla(10);
    drzewo.Dodawani_Wezla(20);
    drzewo.Dodawani_Wezla(15);
    drzewo.Dodawani_Wezla(30);
    drzewo.Dodawani_Wezla(25);
    drzewo.Dodawani_Wezla(40);
    drzewo.Dodawani_Wezla(24);

    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(30));
    drzewo.Przegladaj_Drzewo();


    return 0;
}
