#include "Klasa_graf.hpp"

int main()
{
    char znak;
    Graf <int, char> graf;
    graf.TworzGraf('W', 'A', 'H');
    graf.WyswietlGraf();

    cin>>znak;
    return 0;
}
