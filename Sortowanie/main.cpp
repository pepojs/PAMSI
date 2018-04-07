#include "Klasa_sort.hpp"
#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));
    char znak;

    cout<<"Start"<<endl;
    Sortowanie <int>scalanie(1000000);
    scalanie.WypelniLos_INT(0, 100);
    scalanie.PrzezScalanieMal(0, scalanie.ZwrocRozmiar()-1);
    scalanie.SprawdzSortMal();
    cout<<"Stop"<<endl;

    cin>>znak;

    return 0;
}
