#include "Klasa_sort.hpp"
#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));
    char znak;

    cout<<"Start"<<endl;
    Sortowanie <int>scalanie(1000);
    scalanie.WypelniLos_INT(0, 100);
    scalanie.PrzezKopcowanie();
    scalanie.SprawdzSortRos();
    cout<<"Stop"<<endl;

    cin>>znak;

    return 0;
}
