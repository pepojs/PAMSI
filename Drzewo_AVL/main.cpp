#include <iostream>
#include "Klasa_drzewo.hpp"

int main()
{
    DrzewoAVL* Korzen = new DrzewoAVL(10);

    Korzen->Dodawani_Wezla(15);
    Korzen->Dodawani_Wezla(5);
    Korzen->Dodawani_Wezla(9);
    Korzen->Przegladaj_Drzewo();
    return 0;
}
