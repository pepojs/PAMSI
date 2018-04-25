#ifndef KLASA_SORT_HPP
#define KLASA_SORT_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

template <class TYP_DANYCH>
class Sortowanie
{
    TYP_DANYCH* Tab; //Tablica z wartosciami do posortowania
    TYP_DANYCH* tab_pom; //Tablica pomocnicza potrzebna do sortowania przez scalanie
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

//Konstruktor, jezeli nie podamy ilosci elementow nie stworzy tablicy
template <class TYP_DANYCH> Sortowanie<TYP_DANYCH>::Sortowanie()
{
    Tab = NULL;
    tab_pom = NULL;
    Rozmiar = 0;
}

//Konstruktor, tworzy tablice o podanym rozmiarze
template <class TYP_DANYCH> Sortowanie<TYP_DANYCH>::Sortowanie(int rozmiar)
{
    Tab = new TYP_DANYCH[rozmiar];
    tab_pom = new TYP_DANYCH[rozmiar];
    Rozmiar = rozmiar;
}

//Destruktor, zwalnianie pamięci
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

//Funkcja pomocnicza sluzaca do sprawdzenia czy tablica zostala posortowana rosnaco
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

//Funkcja pomocnicza sluzaca do sprawdzenia czy tablica zostala posortowana malejaco
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

//Funkcja pomocnicza sluzaca do wypelniania tablicy wartosciami losowymi w zakresie od min_liczba do max_liczba
template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::WypelniLos_INT(int min_liczba, int max_liczba)
{
    for(int i = 0; i<Rozmiar; i++) Tab[i] = (rand()%(max_liczba+1))+min_liczba;
}

//Funkcja pomocnicza wyswietlajaca zawartosc tablicy
template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::WyswietlTab()
{
    cout<<"Tablica: "<<endl;
    for(int i = 0; i<Rozmiar; i++) cout<<"Tab["<<i<<"]: "<<Tab[i]<<endl;
    cout<<endl;
}

//Sortowanie przez scalanie, funkcja sortuje tablice rosnaco
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

        //Jezeli czesc pierwsza nie zostala w calosci skopiowana, zostaje dodana na koncu
        //Druga juz jest na koncu, wiec w drugim przypadku nie trzeba jej kopiowac
        while(pom1 <= sr)
        {
            Tab[pom3] = tab_pom[pom1];
            pom1++;
            pom3++;
        }
    }

    //delete tab_pom;
}

//Sortowanie przez scalanie, funkcja sortuje wartosci malejaco
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

        while(pom1 <= sr && pom2 <= kon) //Rob az jedna z czesci sie skonczy, scalanie tablicy
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

        //Jezeli czesc pierwsza nie zostala w calosci skopiowana, zostaje dodana na koncu
        //Druga juz jest na koncu, wiec w drugim przypadku nie trzeba jej kopiowac
        while(pom1 <= sr)
        {
            Tab[pom3] = tab_pom[pom1];
            pom1++;
            pom3++;
        }
    }

    //delete tab_pom;
}

//Rekurencyjne sortowanie przez scalanie rosnaco
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

//Rekurencyjne sortowanie przez scalanie malejaco
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

//Sortowanie szybkie, sortuje wartosci rosnaco
template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::Szybkie(int pocz,int kon)
{
    int pom1 = pocz, pom2 = kon, pom3, element_osiowy = Tab[(pocz+kon)/2];

    //Szukana indeksu elementu podzialu
    do
    {
        //szuka elemnetu wiekszego od elementu osiowego dla elementow o mniejszym indeksie od tego elementu
        while(Tab[pom1] < element_osiowy)
            pom1++;

        //szuka elemnetu ,mniejszego od elementu osiowego dla elementow o wiekszym indeksie od tego elementu
        while(Tab[pom2] > element_osiowy)
            pom2--;

        //zamienia miejscami elemenety znalezione
        if(pom1 <= pom2)
        {
            pom3 = Tab[pom1];
            Tab[pom1] = Tab[pom2];
            Tab[pom2] = pom3;

            pom1++;
            pom2--;
        }

    }while(pom1 <= pom2); // petal konczy sie gdy indeksy szukanych elementow przekrocza indeks elementu osiowego

    //rekurencyjne wywolanie dla podzielonej tablicy na 2 czesci
    if(pocz < pom2) Szybkie(pocz, pom2);

    if(kon > pom1) Szybkie(pom1, kon);

}

//Funkcja uzywana do sortowania przez kopcowanie, tworzy kopiec
template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::TworzKopiec()
{
    TYP_DANYCH pom;
    int pom1, pom2; // pomocnicze indeksy elementow tablicy

    //petla od 2 elementu az do konca tablicy, wyznacza kolejne elementy dodawane do kopca,
    // 1 element i tak zostal by na swoim miejscu
    for(int i = 1; i <Rozmiar; i++)
    {
        //Pomocnicze zmienne
        pom1 = i;
        pom2 = pom1 / 2;
        pom = Tab[i];

        //Szuka miejsca dla elementy pom w tablicy wyjsciowej
        while((pom1 > 0) && (Tab[pom2] < pom))
        {
            Tab[pom1] = Tab[pom2]; //Zamiana tego elementu
            pom1 = pom2;
            pom2 = pom1 / 2; //Kolejny element z wyzszego wezla do porownania
        }

        Tab[pom1] = pom; //Zapisanie elementu dla ktorego szukalismy miejsca
    }

}

//Funkcja uzywana do sortowania przez kopcowanie, rozbiera kopiec sortujac tablice
template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::UsunKopiec()
{
    TYP_DANYCH pom;
    int pom1, pom2, pom3;

    for(int i = Rozmiar-1; i > 0; i--)
    {
        //Zamiana liscia z korzeniem
        pom = Tab[0];
        Tab[0] = Tab[i];
        Tab[i] = pom;
        pom1 = 0;
        pom2 = 1;

        while(pom2 < i) //Petla rownowazaca kopiec
        {
            //Sprawdza ktory syn jest wiekszy, (pom2+1) to prawy syn, pom2 to lewy
            if((pom2 + 1 < i) && (Tab[pom2 + 1] > Tab[pom2]))
                pom3 = pom2 + 1;
            else
                pom3 = pom2;

            if(Tab[pom3] <= Tab[pom1]) break; //Jezeli ojciec wiekszy od wiekszego syna to koniec

            //Ojciec jest mniejszy od wiekszego syna wiec jest zamieniany
            pom = Tab[pom1];
            Tab[pom1] = Tab[pom3];
            Tab[pom3] = pom;

            //Idiemy od korzenia w dol
            pom1 = pom3;
            pom2 = pom1 + pom1;
        }
    }
}

//Sortowanie przez kopcowanie
template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::PrzezKopcowanie()
{
    TworzKopiec();
    UsunKopiec();
}

//Sorotwanie introspetywne
template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::Intro(int pocz, int kon,int maxrek)
{
    int pom1 = pocz, pom2 = kon, element_osiowy = Tab[(pocz+kon)/2];
    TYP_DANYCH  pom3;

    if(maxrek) PrzezKopcowanie();  // Jezeli zaglebienie rekurencyjne wieksze od 2*log(n) to sortowanie pomocnicze
    else //Rekurencyjne wywolanie sortowania introspektywnego
    {

        //Szukana indeksu elementu podzialu
        while(pom1 <= pom2)// petal konczy sie gdy indeksy szukanych elementow przekrocza indeks elementu osiowego
        {
            //szuka elemnetu wiekszego od elementu osiowego dla elementow o mniejszym indeksie od tego elementu
            while(Tab[pom1] < element_osiowy)
                pom1++;

            //szuka elemnetu ,mniejszego od elementu osiowego dla elementow o wiekszym indeksie od tego elementu
            while(Tab[pom2] > element_osiowy)
                pom2--;

            if(pom1 <= pom2)//zamienia miejscami elemenety znalezione
            {
                pom3 = Tab[pom1];
                Tab[pom1] = Tab[pom2];
                Tab[pom2] = pom3;

                pom1++;
                pom2--;
            }

        }


        if(pocz < pom2) Intro(pocz, pom2, maxrek-1);

        if(kon > pom1) Intro(pom1, kon, maxrek-1);
    }
}


template <class TYP_DANYCH> void Sortowanie<TYP_DANYCH>::Introspektywne(int pocz, int kon)
{
    int maxrek = 2*log2(Rozmiar);
    Intro(pocz, kon, maxrek);
}

#endif
