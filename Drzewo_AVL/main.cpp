#include <iostream>
#include "Klasa_drzewo.hpp"

int main()
{
    DrzewoAVL drzewo(10);

    drzewo.Dodawani_Wezla(11);
    drzewo.Przegladaj_Drzewo();
    drzewo.Dodawani_Wezla(12);
    drzewo.Przegladaj_Drzewo();
    return 0;
}
