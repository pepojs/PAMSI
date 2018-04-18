#ifndef KLASA_SORT_HPP
#define KLASA_SORT_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

template <class TYP_DANYCH>
class Sortowanie
{
    TYP_DANYCH* Tab;
    TYP_DANYCH* tab_pom;
    int Rozmiar;

    void ScalanieRos(int pocz, int sr, int kon);
    void ScalanieMal(int pocz, int sr, int kon);
    void TworzKopiec();
    void UsunKopiec();
    void Intro(int pocz, int kon, int maxrek);


    public:
    Sortowanie();
    Sortowanie(int rozmiar);
    ~Sortowanie();

    int SprawdzSortRos();
    int SprawdzSortMal();
    void WypelniLos_INT(int min_liczba, int max_liczba);
    void WyswietlTab();
    int ZwrocRozmiar(){return Rozmiar;}



    void PrzezScalanieRos(int pocz, int kon);
    void PrzezScalanieMal(int pocz, int kon);
    void Szybkie(int pocz, int kon);
    void PrzezKopcowanie();
    void Introspektywne(int pocz, int kon);

};

template <class TYP_DANYCH> Sortowanie<TYP_DANYCH>::Sortowanie()
{
    Tab = NULL;
    tab_pom = NULL;
    Rozmiar = 0;
}

template <class TYP_DANYCH> Sortowanie<TYP_DANYCH>::Sortowanie(int rozmiar)
{
    Tab = new TYP_DANYCH[rozmiar];
    tab_pom = new TYP_DANYCH[rozmiar];
    Rozmiar = rozmiar;
}

template <class TYP_DANYCH> Sortowanie<TYP_DANYCH>::~Sortowanie()
{
    if(Tab != NULL)
    {
        delete[] Tab;
        Tab = NULL;
    }

    if(tab_pom != NULL)
    {
        delete[] tab_pom;
        tab_pom = NULL;
    }
}

template <class TYP_DANYCH> int Sortowanie<TYP_DANYCH>::SprawdzSortRos()
{
    if(Tab != NULL)
    {
        for(int i = 0;i < (Rozmiar-1); i++)
            if(Tab[i] > Tab[i+1])
            {
                cout<<"Tablica jest zle posortowana"<<endl;
                return -1;
            }

    }else
    {
        cout<<"Tablica do sortowania jest pusta. "<<endl;
        return -1;
    }

    return 0;
}

template <class TYP_DANYCH> int Sortowanie<TYP_DANYCH>::SprawdzSortMal()
{
    if(Tab != NULL)
    {
        for(int i = 0;i < (Rozmiar-1); i++)
            if(Tab[i] < Tab[i+1])
            {
                cout<<"Tablica jest zle posortowana"<<endl;
                return -1;
            }

    }else
    {
        cout<<"Tablica do sortowania jest pusta. "<<endl;
        return -1;
    }

    return 0;
}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::WypelniLos_INT(int min_liczba, int max_liczba)
{
    for(int i = 0; i<Rozmiar; i++) Tab[i] = (rand()%(max_liczba+1))+min_liczba;
}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::WyswietlTab()
{
    cout<<"Tablica: "<<endl;
    for(int i = 0; i<Rozmiar; i++) cout<<"Tab["<<i<<"]: "<<Tab[i]<<endl;
    cout<<endl;
}


template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::ScalanieRos(int pocz, int sr,int kon)
{
    int pom1, pom2, pom3;
    //TYP_DANYCH* tab_pom = new TYP_DANYCH[kon+1];


    if(Tab != NULL)
    {
        for(pom1 = pocz; pom1 <= kon; pom1++) tab_pom[pom1] = Tab[pom1]; //Kopiuje tablice elementow do posortowania(scalenia) do tablicy tymczasowej

        pom1 = pocz; //Pokazuje poczatek 1 czesci tablicy do scalenia
        pom2 = sr+1; //Wskazuje poczatek 2 czesci tablicy do scalenia
        pom3 = pocz; //Numer elementu do ktorego zapisuje sie posortowana liczbe

        while(pom1 <= sr && pom2 <= kon) //Rob az jedna z czesci sie skonczy
        {
            if(tab_pom[pom1] < tab_pom[pom2])
            {
                Tab[pom3] = tab_pom[pom1];
                pom3++;
                pom1++;
            }else
            {
                Tab[pom3] = tab_pom[pom2];
                pom3++;
                pom2++;
            }
        }

        while(pom1 <= sr) //Jezeli czesc pierwsza nie zostala w calosci skopiowana, zostaje dodana na koncu
        {
            Tab[pom3] = tab_pom[pom1];
            pom1++;
            pom3++;
        }
    }

    //delete tab_pom;
}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::ScalanieMal(int pocz, int sr,int kon)
{
    int pom1, pom2, pom3;
    //TYP_DANYCH* tab_pom = new TYP_DANYCH[kon+1];


    if(Tab != NULL)
    {
        for(pom1 = pocz; pom1 <= kon; pom1++) tab_pom[pom1] = Tab[pom1]; //Kopiuje tablice elementow do posortowania(scalenia) do tablicy tymczasowej

        pom1 = pocz; //Pokazuje poczatek 1 czesci tablicy do scalenia
        pom2 = sr+1; //Wskazuje poczatek 2 czesci tablicy do scalenia
        pom3 = pocz; //Numer elementu do ktorego zapisuje sie posortowana liczbe

        while(pom1 <= sr && pom2 <= kon) //Rob az jedna z czesci sie skonczy
        {
            if(tab_pom[pom1] > tab_pom[pom2])
            {
                Tab[pom3] = tab_pom[pom1];
                pom3++;
                pom1++;
            }else
            {
                Tab[pom3] = tab_pom[pom2];
                pom3++;
                pom2++;
            }
        }

        while(pom1 <= sr) //Jezeli czesc pierwsza nie zostala w calosci skopiowana, zostaje dodana na koncu
        {
            Tab[pom3] = tab_pom[pom1];
            pom1++;
            pom3++;
        }
    }

    //delete tab_pom;
}

//Rekurencyjne sortowanie przez scalanie
template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::PrzezScalanieRos(int pocz,int kon)
{
    int sr;
    if(pocz<kon) //Jezeli wiecej niz 1 element
    {
        sr = (pocz+kon)/2; //Znajduje srodek tablicy do posortowania
        PrzezScalanieRos(pocz, sr); //Najpierw dzieli lewa czesc tablicy
        PrzezScalanieRos(sr+1, kon); //Nastepnie prawa czesc
        ScalanieRos(pocz, sr, kon); //Scala i sortuje
    }
}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::PrzezScalanieMal(int pocz,int kon)
{
    int sr;
    if(pocz<kon) //Jezeli wiecej niz 1 element
    {
        sr = (pocz+kon)/2; //Znajduje srodek tablicy do posortowania
        PrzezScalanieMal(pocz, sr); //Najpierw dzieli lewa czesc tablicy
        PrzezScalanieMal(sr+1, kon); //Nastepnie prawa czesc
        ScalanieMal(pocz, sr, kon); //Scala i sortuje
    }
}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::Szybkie(int pocz,int kon)
{
    int pom1 = pocz, pom2 = kon, pom3, element_osiowy = Tab[(pocz+kon)/2];

    do
    {
        while(Tab[pom1] < element_osiowy)
            pom1++;

        while(Tab[pom2] > element_osiowy)
            pom2--;

        if(pom1 <= pom2)
        {
            pom3 = Tab[pom1];
            Tab[pom1] = Tab[pom2];
            Tab[pom2] = pom3;

            pom1++;
            pom2--;
        }

    }while(pom1 <= pom2);

    if(pocz < pom2) Szybkie(pocz, pom2);

    if(kon > pom1) Szybkie(pom1, kon);

}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::TworzKopiec()
{
    TYP_DANYCH pom;
    int pom1, pom2;

    for(int i = 1; i <Rozmiar; i++)
    {
        pom1 = i;
        pom2 = pom1 / 2;
        pom = Tab[i];

        while((pom1 > 0) && (Tab[pom2] < pom))
        {
            Tab[pom1] = Tab[pom2];
            pom1 = pom2;
            pom2 = pom1 / 2;
        }

        Tab[pom1] = pom;
    }

}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::UsunKopiec()
{
    TYP_DANYCH pom;
    int pom1, pom2, pom3;

    for(int i = Rozmiar-1; i > 0; i--)
    {
        pom = Tab[0];
        Tab[0] = Tab[i];
        Tab[i] = pom;
        pom1 = 0;
        pom2 = 1;

        while(pom2 < i)
        {
            if((pom2 + 1 < i) && (Tab[pom2 + 1] > Tab[pom2]))
                pom3 = pom2 + 1;
            else
                pom3 = pom2;

            if(Tab[pom3] <= Tab[pom1]) break;

            pom = Tab[pom1];
            Tab[pom1] = Tab[pom3];
            Tab[pom3] = pom;

            pom1 = pom3;
            pom2 = pom1 + pom1;
        }
    }
}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::PrzezKopcowanie()
{
    TworzKopiec();
    UsunKopiec();
}

template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::Intro(int pocz, int kon,int maxrek)
{
    int pom1 = pocz, pom2 = kon, pom3, element_osiowy = Tab[(pocz+kon)/2];

    do
    {
        while(Tab[pom1] < element_osiowy)
            pom1++;

        while(Tab[pom2] > element_osiowy)
            pom2--;

        if(pom1 <= pom2)
        {
            pom3 = Tab[pom1];
            Tab[pom1] = Tab[pom2];
            Tab[pom2] = pom3;

            pom1++;
            pom2--;
        }

    }while(pom1 <= pom2);

    if(pom2 > maxrek) PrzezKopcowanie();
    else
    {
        if(pocz < pom2) Intro(pocz, pom2, maxrek-1);

        if(kon > pom1) Intro(pom1, kon, maxrek-1);
    }
}


template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::Introspektywne(int pocz, int kon)
{
    int maxrek = 2*log(Rozmiar);
    Intro(pocz, kon, maxrek);
}

#endif
