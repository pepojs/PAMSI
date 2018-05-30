#include "Klasa_graf.hpp"

template <typename TypKrawedzi, typename TypWierzcholka>
void Wierzcholek<TypKrawedzi, TypWierzcholka>::UstawKrawedz(Krawedz<TypKrawedzi, TypWierzcholka> kra)
{
    if(kra.ZwrocWartWierzL() == Dane)
        Kra.push_back(kra);
    else
        Kra.push_back(Krawedz<TypKrawedzi, TypWierzcholka>(kra.ZwrocWartKraw(),kra.ZwrocWskWierzP(), kra.ZwrocWskWierzL()));
}

template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::DodajWierzcholek(TypWierzcholka wartosc)
{
    for(unsigned int i = 0; i < W.size(); i++)
    {
        if(W[i].ZwrocDane() == wartosc)
        {
            //cout<<"Wezel o tej wartosci juz istnieje"<<endl;
            return;
        }
    }
    W.push_back(Wierzcholek<TypKrawedzi, TypWierzcholka>(wartosc));
}

template <typename TypKrawedzi, typename TypWierzcholka>
int Graf<TypKrawedzi, TypWierzcholka>::DodajKrawedz(TypKrawedzi wartosc, Wierzcholek<TypKrawedzi, TypWierzcholka>* L,
                                                    Wierzcholek<TypKrawedzi, TypWierzcholka>* P)
{
    for(unsigned int i = 0; i < K.size(); i++)
    {
        if((K[i].ZwrocWartWierzL() == L->ZwrocDane() && K[i].ZwrocWartWierzP() == P->ZwrocDane()) ||
           (K[i].ZwrocWartWierzL() == P->ZwrocDane() && K[i].ZwrocWartWierzP() == L->ZwrocDane()))
        {
            //cout<<"Krawedz o tej wartosci juz istnieje"<<endl;
            return 1;
        }
    }

    Krawedz<TypKrawedzi, TypWierzcholka> pom(wartosc, L, P);
    K.push_back(pom);
    L->UstawKrawedz(K.back());
    P->UstawKrawedz(K.back());
    return 0;
}

template <typename TypKrawedzi, typename TypWierzcholka>
Wierzcholek<TypKrawedzi, TypWierzcholka>* Graf<TypKrawedzi, TypWierzcholka>::ZwrocWskWierz(TypWierzcholka wartosc)
{
    for(unsigned int i = 0; i < W.size(); i++)
    {
        if(W[i].ZwrocDane() == wartosc) return &W[i];
    }

    return NULL;
}

template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::TworzGraf(char kon, char wierza, char krol)
{
    int wierza_j = 0, wierza_i = 0, i, j, kon_i = 0, kon_j = 0;
    char tab_pom[5][5]; //Tworzy tablice pomocnicza 5x5 odpowiadajaca planszy
    const int ruchy_rzad[] = {1, 2, 2, 1, -1, -2, -2, -1};
    const int ruchy_kolu[] = {-2, -1, 1, 2,2, 1, -1, -2};

    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
        {
            if(wierza == 'A'+j+(i*5)) //zapisuje kolumne i rzad w ktorej stoji wierza
            {
                wierza_i = i;
                wierza_j = j;
            }

            if(kon == 'A'+j+(i*5))
            {
                kon_i = i;
                kon_j = j;
            }

            tab_pom[i][j] = 'A'+j+(i*5); //Wypelnia tablice kolejnymi nazwami pol

        }

    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
        {
            if(i == wierza_i || j == wierza_j) //Zaznacza pola w ktorych kon nie moze stanac
                tab_pom[i][j] = 0;
            else
                DodajWierzcholek(tab_pom[i][j]);

        }


    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
        {
            if(tab_pom[i][j] != 0)
            {
                for(int k = 0; k < 8; k++)
                {
                    if((j + ruchy_rzad[k] >= 0 && j + ruchy_rzad[k] < 5) &&
                    (i + ruchy_kolu[k] >= 0 && i + ruchy_kolu[k] < 5) &&
                    (tab_pom[i + ruchy_kolu[k]][j + ruchy_rzad[k]] != 0))
                    {
                        DodajWierzcholek(tab_pom[i + ruchy_kolu[k]][j + ruchy_rzad[k]]);
                        DodajKrawedz(k, ZwrocWskWierz(tab_pom[i][j]), ZwrocWskWierz(tab_pom[i + ruchy_kolu[k]][j + ruchy_rzad[k]]));

                    }

                }
            }
        }


/*
    DodajWierzcholek(kon);
    pom_wierz = kon;
    j = 0;

    while(pom_petla == 1)
    {
        pom_petla = 0;
        for(i = 0; i < 8; i++)
        {
            if((kon_j + ruchy_rzad[i] >= 0 && kon_j + ruchy_rzad[i] < 5) &&
               (kon_i + ruchy_kolu[i] >= 0 && kon_i + ruchy_kolu[i] < 5) &&
               tab_pom[kon_i + ruchy_kolu[i]][kon_j + ruchy_rzad[i]] != 0)
            {
                DodajWierzcholek(tab_pom[kon_i + ruchy_kolu[i]][kon_j + ruchy_rzad[i]]);
                cout<<"Tutaj "<<endl;
                if(!DodajKrawedz(i, ZwrocWskWierz(pom_wierz), ZwrocWskWierz(tab_pom[kon_i + ruchy_kolu[i]][kon_j + ruchy_rzad[i]])))
                   pom_petla = 1;
            }
        }

        pom_wierz = K[j].ZwrocWartWierzP();
        cout<< pom_wierz<<"  "<<endl;
        kon_i = kon_i + ruchy_kolu[K[j].ZwrocWartKraw()];
        kon_j = kon_j + ruchy_rzad[K[j].ZwrocWartKraw()];
        j++;

    }

*/



}

template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::WyswietlGraf()
{
    for(unsigned int i = 0; i < W.size(); i++)
    {
        W[i].Wyswietl();
    }

}

template class Graf<int,char>;
