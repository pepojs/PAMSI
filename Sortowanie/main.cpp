#include "Klasa_sort.hpp"
#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));
    char znak;

    cout<<"Start"<<endl;
    Sortowanie <int>scalanie(100);
    scalanie.WypelniLos_INT(0, 100);
    scalanie.PrzezScalanieRos(0, scalanie.ZwrocRozmiar()-1);
    scalanie.SprawdzSortRos();
    cout<<"Stop"<<endl;

    cin>>znak;

    return 0;
}
