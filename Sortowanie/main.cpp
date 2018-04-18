#include "Klasa_sort.hpp"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <fstream>

void ZapisDoPliku(fstream &plik, int proba, int rozmiar, int czas, int posortowanie)
{
    if(plik.good())
    {
        plik<<proba<<","<<rozmiar<<","<<czas<<","<<posortowanie<<endl;

    }else std::cout<<"Nie mozna zapisac do pliku"<<endl;
}


int main()
{
    srand(time(NULL));
    char znak;
    DWORD czas_start, czas_stop;
    fstream plik;
    int rozm[] = {200000,500000, 800000, 1000000, 10000000};
    plik.open("Szybkie.txt", std::ios::out);

    for(int j = 0; j<5;j++){
    Sortowanie <int>scalanie(rozm[j]);
    for(int i = 0; i<100;i++)
    {

        scalanie.WypelniLos_INT(0, 100);
        cout<<"Start"<<endl;
        czas_start = GetTickCount();
        scalanie.Szybkie(0, scalanie.ZwrocRozmiar()-1);
        czas_stop = GetTickCount();
        scalanie.SprawdzSortRos();
        cout<<"Stop"<<endl;
        cout<<"Czas trwania rowny: "<<czas_stop-czas_start<<" ms"<<endl;
        ZapisDoPliku(plik, i,rozm[j],czas_stop-czas_start,0);
    }
    }

    cin>>znak;
    plik.close();
    return 0;
}
