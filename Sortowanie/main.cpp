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
    int rozm[] = {100000, 200000,500000, 800000, 1000000, 2000000, 4000000};
    float pro_sort[] = {0, 0.25, 0.50, 0.75, 0.9, 0.95, 0.997};
    plik.open("Scalaie21.txt", std::ios::out);

    for(int j = 0; j<7;j++){
    Sortowanie <int>scalanie(rozm[j]);
    for(int i = 0; i<100;i++)
    {
        scalanie.WypelniLos_INT(0, 100);
        scalanie.PrzezScalanieMal(0,rozm[j]-1);
        cout<<"Start"<<endl;
        czas_start = GetTickCount();
        //scalanie.Szybkie(0, scalanie.ZwrocRozmiar()-1);
        scalanie.PrzezScalanieRos(0, scalanie.ZwrocRozmiar()-1);
        //scalanie.Introspektywne(0, scalanie.ZwrocRozmiar()-1);
        czas_stop = GetTickCount();
        scalanie.SprawdzSortRos();
        cout<<"Stop"<<endl;
        cout<<"Czas trwania rowny: "<<czas_stop-czas_start<<" ms"<<endl;
        //ZapisDoPliku(plik, i,rozm[j],czas_stop-czas_start,0);
        plik<<i<<","<<rozm[j]<<","<<czas_stop-czas_start<<","<<"-1"<<endl;
    }
    }

    cin>>znak;
    plik.close();
    return 0;
}
