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


template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::DFSRekurencja(char krol, Wierzcholek<TypKrawedzi, TypWierzcholka> wenzel,
                                                      vector <Wierzcholek<TypKrawedzi, TypWierzcholka> > &w,
                                                      vector <Wierzcholek<TypKrawedzi, TypWierzcholka> >odw)
{
    int flaga = 0;


    for(unsigned int i = 0; i < wenzel.IloscKrawedzi(); i++)
    {
        //cout<<i<<" "<<(wenzel.ZwrocKrawedz(i).ZwrocWskWierzP())->ZwrocDane()<<"  "<<wenzel.ZwrocDane();
        if((wenzel.ZwrocKrawedz(i).ZwrocWskWierzP())->ZwrocDane() == wenzel.ZwrocDane()) continue;

        for(unsigned int j = 0; j < odw.size(); j++)
        {
            if(odw[j].ZwrocDane() == (wenzel.ZwrocKrawedz(i).ZwrocWskWierzP())->ZwrocDane())
            {
                flaga = 1;
                break;
            }
        }

        //cout<<" "<<flaga<<endl;
        if(flaga)
        {
            flaga = 0;
            continue;
        }

        if(!odw.empty())
        {
            if(odw.back().ZwrocDane() != wenzel.ZwrocDane())
            odw.push_back(wenzel);
        }
        else odw.push_back(wenzel);

        if(wenzel.ZwrocDane() == krol)
        {
            for(unsigned int k = 0; k < odw.size(); k++)
                w.push_back(odw[k]);

            w.push_back(Wierzcholek<TypKrawedzi, TypWierzcholka>('|'));
            return;
        }
        DFSRekurencja(krol, *wenzel.ZwrocKrawedz(i).ZwrocWskWierzP(), w, odw);
    }


    //for(unsigned int i = 0; i < odw.size(); i++)
    //    cout<<i<<" "<<odw[i].ZwrocDane()<<endl;
}

template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::DFS(char kon, char wierza, char krol)
{
    int jest = 0;
    Wierzcholek<TypKrawedzi, TypWierzcholka> Pierwszy(0);
    vector<Wierzcholek<TypKrawedzi, TypWierzcholka> > Odwiedzone;
    vector<Wierzcholek<TypKrawedzi, TypWierzcholka> > Wynik;

    for(unsigned int i = 0; i < W.size(); i++)
    {
        if(W[i].ZwrocDane() == kon)
        {
            Pierwszy = W[i];
            break;
        }
    }

    //cout<<NieOdwiedzone[0].ZwrocDane()<<endl;

    do
    {
        jest = 0;
        DFSRekurencja(krol, Pierwszy,Wynik, Odwiedzone);

    }while(jest == 1);



   // for(unsigned int i = 0; i < Odwiedzone.size(); i++)
   //     cout<<endl<<Odwiedzone[i].ZwrocDane()<<endl;

    cout<<"Wynik "<<endl;

    for(unsigned int i = 0; i < Wynik.size(); i++)
    {
        cout<<Wynik[i].ZwrocDane()<<" ";
        if(Wynik[i].ZwrocDane() == '|')cout <<"\b\b "<<endl;
    }


}

template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::AGwiazdka(char kon, char wierza, char krol)
{
    vector<StrAGwiazdka<TypKrawedzi, TypWierzcholka> > Odwiedzone;
    vector<StrAGwiazdka<TypKrawedzi, TypWierzcholka> > NieOdwiedzone;

    for(unsigned int i = 0; i < W.size(); i++)
    {
        if(W[i].ZwrocDane() == kon)
        {
            NieOdwiedzone.push_back(StrAGwiazdka<TypKrawedzi, TypWierzcholka>());
            NieOdwiedzone.back().Wierz = W[i];
            break;
        }
    }

    NieOdwiedzone.back().NumerWierz = 1;
    NieOdwiedzone.back().FH = FHeurystyczna(kon, krol);
    NieOdwiedzone.back().FF = NieOdwiedzone.back().FG + NieOdwiedzone.back().FH;

    while(!NieOdwiedzone.empty())
    {

    }

}

template <typename TypKrawedzi, typename TypWierzcholka>
int Graf<TypKrawedzi, TypWierzcholka>::FHeurystyczna(char aktualny, char cel)
{
    int aktualny_x = 0, aktualny_y = 0;
    int cel_x = 0, cel_y = 0;
    int wynik = -1;

    aktualny = aktualny - 65;
    cel = cel - 65;

    aktualny_x = aktualny%5;
    aktualny_y = aktualny/5;

    cel_x = cel%5;
    cel_y = cel/5;

    wynik = fabs(aktualny_x - cel_x) + fabs(aktualny_y - cel_y);

    return wynik;
}

template class Graf<int,char>;
