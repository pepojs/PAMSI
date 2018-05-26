#include "Klasa_graf.hpp"

int main()
{
    Graf <int, char> graf;
    graf.TworzGraf('W', 'A', 'H');
    graf.WyswietlGraf();
    return 0;
}
