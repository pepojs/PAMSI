#include "Klasa_graf.hpp"

//Dodawanie wierzcholka do grafu
template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::DodajWierzcholek(TypWierzcholka wartosc)
{
    //Sprawdzenie czy taki wierzcholek juz istnieje
    for(unsigned int i = 0; i < W.size(); i++)
    {
        if(W[i].ZwrocDane() == wartosc)
        {
            //cout<<"Wezel o tej wartosci juz istnieje"<<endl;
            return;
        }
    }
    //jezeli wierzcholek nie istnieje to dodaje wierzcholka do grafu
    W.push_back(Wierzcholek<TypKrawedzi, TypWierzcholka>(wartosc));
}

//Zwraca wskaznik na wierzcholek
template <typename TypKrawedzi, typename TypWierzcholka>
Wierzcholek<TypKrawedzi, TypWierzcholka>* Graf<TypKrawedzi, TypWierzcholka>::ZwrocWskWierz(TypWierzcholka wartosc)
{
    //jezeli wierzcholek istnieje zwraca wskaznik na niego
    for(unsigned int i = 0; i < W.size(); i++)
    {
        if(W[i].ZwrocDane() == wartosc) return &W[i];
    }

    //inaczej null
    return NULL;
}

//Dodaje krawedz miedzy dwoma wierzcholkami
template <typename TypKrawedzi, typename TypWierzcholka>
int Graf<TypKrawedzi, TypWierzcholka>::DodajKrawedz(TypKrawedzi wartosc, Wierzcholek<TypKrawedzi, TypWierzcholka>* L,
                                                    Wierzcholek<TypKrawedzi, TypWierzcholka>* P)
{
    //Sprawdza czy krawedz juz istnieje
    for(unsigned int i = 0; i < K.size(); i++)
    {
        if((K[i].ZwrocWartWierzL() == L->ZwrocDane() && K[i].ZwrocWartWierzP() == P->ZwrocDane()) ||
           (K[i].ZwrocWartWierzL() == P->ZwrocDane() && K[i].ZwrocWartWierzP() == L->ZwrocDane()))
        {
            //cout<<"Krawedz o tej wartosci juz istnieje"<<endl;
            return 1;
        }
    }

    //Tworzy krawedz miedzy wierzcholkami L i P o wartosci
    Krawedz<TypKrawedzi, TypWierzcholka> pom(wartosc, L, P);
    K.push_back(pom); //Dodaje do listy krawedzi
    L->UstawKrawedz(K.back());
    P->UstawKrawedz(K.back());
    return 0;
}

//Tworzy graf
template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::TworzGraf(char kon, char wierza, char krol)
{
    //Czysci liste krawedzi i wierzcholkow grafu
    K.clear();
    W.clear();

    int wierza_j = 0, wierza_i = 0, i, j;
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
                //Sprawdza wszystkie ruchy konia
                for(int k = 0; k < 8; k++)
                {
                    //jezeli ruch jest mozliwy (nie wychodzi poza tablice i nie staje na polu bicia wierzy)
                    if((j + ruchy_rzad[k] >= 0 && j + ruchy_rzad[k] < 5) &&
                    (i + ruchy_kolu[k] >= 0 && i + ruchy_kolu[k] < 5) &&
                    (tab_pom[i + ruchy_kolu[k]][j + ruchy_rzad[k]] != 0))
                    {
                        //Dodaje wierzcholek i tworzy krawedz miedzy wierzcholkami
                        DodajWierzcholek(tab_pom[i + ruchy_kolu[k]][j + ruchy_rzad[k]]);
                        DodajKrawedz(3, ZwrocWskWierz(tab_pom[i][j]), ZwrocWskWierz(tab_pom[i + ruchy_kolu[k]][j + ruchy_rzad[k]]));

                    }

                }
            }
        }

}

//Wyswietla wszystkie wierzcholki w grafie wraz z krawedziami
template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::WyswietlGraf()
{
    for(unsigned int i = 0; i < W.size(); i++)
    {
        W[i].Wyswietl();
    }

}

//Metoda uzywana podczas przeszukiwania w glab grafu
template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::DFSRekurencja(char krol, Wierzcholek<TypKrawedzi, TypWierzcholka> wenzel,
                                                      vector <Wierzcholek<TypKrawedzi, TypWierzcholka> > &w,
                                                      vector <Wierzcholek<TypKrawedzi, TypWierzcholka> >odw)
{
    int flaga = 0;

    //Sprawdzanie wszystkich krawedzi przypisanych wierzcholkowi
    for(unsigned int i = 0; i < wenzel.IloscKrawedzi(); i++)
    {
        //jezeli krawedz zaczyna sie i konczy tym samym wierzcholkiem
        if((wenzel.ZwrocKrawedz(i).ZwrocWskWierzP())->ZwrocDane() == wenzel.ZwrocDane()) continue;

        //Sprawdza czy wierzcholek na koncu krawedzi (nastepny) nie byl juz odwiedzony
        for(unsigned int j = 0; j < odw.size(); j++)
        {
            if(odw[j].ZwrocDane() == (wenzel.ZwrocKrawedz(i).ZwrocWskWierzP())->ZwrocDane())
            {
                flaga = 1;
                break;
            }
        }

        //jezeli wierzcholek byl odwiedzony to sprawdza nastepna krawedz
        if(flaga)
        {
            flaga = 0;
            continue;
        }


        if(!odw.empty())
        {
            //jezeli dany wirzcholek nie byl dodany do list odwiedzonych
            if(odw.back().ZwrocDane() != wenzel.ZwrocDane())
            odw.push_back(wenzel);
        }
        else odw.push_back(wenzel);

        //jezeli osiagnieto pole, na ktorym stoi krol
        if(wenzel.ZwrocDane() == krol)
        {
            //jezeli lista odwiedzonych wierzcholkow jest krotsza od wyniku
            if(w.size() != 0 && w.size() > odw.size())
            {
                w.swap(odw);//Zamienia liste wynik z odwiedzonymi wierzcholkami

            }else if(w.size() == 0)
            {
                w.swap(odw);
            }
            return;
        }
        //Rekurencja
        DFSRekurencja(krol, *wenzel.ZwrocKrawedz(i).ZwrocWskWierzP(), w, odw);
    }

}

//DFS
template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::DFS(char kon, char wierza, char krol)
{
    Wierzcholek<TypKrawedzi, TypWierzcholka> Pierwszy(0);
    vector<Wierzcholek<TypKrawedzi, TypWierzcholka> > Odwiedzone;
    vector<Wierzcholek<TypKrawedzi, TypWierzcholka> > Wynik;

    //Szuka w grafie pierwszego wierzcholka, na ktorym stoi kon
    for(unsigned int i = 0; i < W.size(); i++)
    {
        if(W[i].ZwrocDane() == kon)
        {
            Pierwszy = W[i];
            break;
        }
    }

    //Rekurencyjne wywolanie DFS
    DFSRekurencja(krol, Pierwszy,Wynik, Odwiedzone);

    //Wyswietla wynik przeszukiwania
    cout<<endl<<"Wynik dla DFS: "<<endl;

    if(Wynik.size() == 0)
    {
        cout<<"Brak rozwiazania !"<<endl;

    }else
    {
        for(unsigned int i = 0; i < Wynik.size(); i++)
        {
            cout<<Wynik[i].ZwrocDane()<<" ";
        }
        cout<<endl;
    }


}

//Metoda dla algorytmu A*
template <typename TypKrawedzi, typename TypWierzcholka>
void Graf<TypKrawedzi, TypWierzcholka>::AGwiazdka(char kon, char wierza, char krol)
{
    int pom = 0, pomFF = 0;
    StrAGwiazdka<TypKrawedzi, TypWierzcholka>* pomSAG;
    vector<StrAGwiazdka<TypKrawedzi, TypWierzcholka> > Odwiedzone;
    vector<StrAGwiazdka<TypKrawedzi, TypWierzcholka> > NieOdwiedzone;
    typename vector<StrAGwiazdka<TypKrawedzi, TypWierzcholka> >::iterator NOIter;

    //Dodaje do listy nieodwiedzonych wierzcholek, na ktorym stoi kon
    for(unsigned int i = 0; i < W.size(); i++)
    {
        if(W[i].ZwrocDane() == kon)
        {
            NieOdwiedzone.push_back(StrAGwiazdka<TypKrawedzi, TypWierzcholka>());
            NieOdwiedzone.back().Wierz = W[i];
            break;
        }
    }

    //Wypelnia pola struktury dla A* odpowiedznimi wartosciami
    NieOdwiedzone.back().NumerWierz = 1;
    NieOdwiedzone.back().FH = FHeurystyczna(kon, krol);
    NieOdwiedzone.back().FF = NieOdwiedzone.back().FG + NieOdwiedzone.back().FH;

    //Jezeli lista nieodwiedzonych wierzcholkow nie jest pusta
    while(!NieOdwiedzone.empty())
    {
        pomFF = NieOdwiedzone.back().FF; //Ustala pomocnicza zmienna

        //Szuka nieodwiedzonego wierzcholka o najmniejszej wartosci f(n)
        for(NOIter = NieOdwiedzone.begin(); NOIter != NieOdwiedzone.end(); NOIter++)
        {
            if(pomFF >= NOIter->FF)
            {
                pomFF = NOIter->FF;
                break;
            }
        }

        //Jezeli wierzcholkiem jest pole z krolem
        if(NOIter->Wierz.ZwrocDane() == krol)
        {
            //Wyswietla odwiedzone wierzcholki od ostatniego do pierwszego
            cout<<endl<<"Wynik dla A*: "<<endl;
            cout<<*NOIter<<endl;
            if(!NOIter->Rodzic.empty())
            {
                pomSAG = &(NOIter->Rodzic.back());

                while(!(*pomSAG).Rodzic.empty())
                {
                    cout<<(*pomSAG)<<endl;

                    pomSAG = &(*pomSAG).Rodzic.back();
                }

                cout<<(*pomSAG)<<endl;
            }

            return;
        }

        //Dodaje wierzcholek do odwiedzonych
        Odwiedzone.push_back(*NOIter);
        NieOdwiedzone.erase(NOIter);//Usuwa z nieodwiedzonych

        //Przeszukuje kolejne krawedzie polaczone z aktualnym wierzcholkiem
        for(unsigned int i = 0; i < Odwiedzone.back().Wierz.IloscKrawedzi(); i++)
        {
            //Sprawdza czy wierzcholek byl odwiedzony
            for(unsigned int j = 0; j < Odwiedzone.size(); j++)
            {
                if(Odwiedzone.back().Wierz.ZwrocKrawedz(i).ZwrocWartWierzP() == Odwiedzone[j].Wierz.ZwrocDane())
                {
                    pom = 1;
                    break;
                }

            }

            //Jezeli byl odwiedzony sprawdza nastepna krawed
            if(pom == 1)
            {
                pom = 0;
                continue;
            }

            //Sprawdza czy wierzcholek byl dodany do listy nieodwiedzonych
            for(unsigned int j = 0; j < NieOdwiedzone.size(); j++)
            {
                if(Odwiedzone.back().Wierz.ZwrocKrawedz(i).ZwrocWartWierzP() == NieOdwiedzone[j].Wierz.ZwrocDane())
                {
                    pom = 1;
                    break;
                }

            }

            //jezeli byl dodany do nieodwiedzonych to sprawdza kolejna krawedz
            if(pom == 1)
            {
                pom = 0;
                continue;
            }

            //jezeli nie byl dodany do odwiedzonych, dodaje i wypelnia pola struktury odpowiednim wartosciami
            NieOdwiedzone.push_back(StrAGwiazdka<TypKrawedzi, TypWierzcholka>());
            NieOdwiedzone.back().Wierz = *Odwiedzone.back().Wierz.ZwrocKrawedz(i).ZwrocWskWierzP();
            NieOdwiedzone.back().FH = FHeurystyczna(NieOdwiedzone.back().Wierz.ZwrocDane(), krol);
            NieOdwiedzone.back().FG = Odwiedzone.back().FG + 3; // 3 odległosc miedzy kolejnymi polami
            NieOdwiedzone.back().FF = NieOdwiedzone.back().FG + NieOdwiedzone.back().FH;
            NieOdwiedzone.back().Rodzic.push_back(Odwiedzone.back());
            NieOdwiedzone.back().NumerWierz = Odwiedzone.back().NumerWierz + 1;

        }

    }

    //Jezeli nie znalazl zadnej scierzki
    cout<<endl<<"Wynik dla A*: "<<endl;
    cout<<"Brak rozwiazania !"<<endl;

}

//Funkcja heurystyczna
template <typename TypKrawedzi, typename TypWierzcholka>
int Graf<TypKrawedzi, TypWierzcholka>::FHeurystyczna(char aktualny, char cel)
{
    int aktualny_x = 0, aktualny_y = 0;
    int cel_x = 0, cel_y = 0;
    int wynik = -1;

    //Zamienia litere z kodu ascii na liczbe od 0
    aktualny = aktualny - 65;
    cel = cel - 65;

    //Oblicza wspolrzedne pola, od ktorego szukamy
    aktualny_x = aktualny%5;
    aktualny_y = aktualny/5;

    //Oblicza wspolrzedne pola celu
    cel_x = cel%5;
    cel_y = cel/5;

    //Oblicza odleglosc ze wzoru h(n) = |u - p| + |v - q|
    wynik = fabs(aktualny_x - cel_x) + fabs(aktualny_y - cel_y);

    return wynik;
}

//Przeciarzenie pozwalajace wyswietlic strukture dla algorytmu A*
template <typename TypKrawedzi, typename TypWierzcholka>
ostream & operator<< (ostream &wy, StrAGwiazdka<TypKrawedzi, TypWierzcholka> &s)
{
    wy<<"Kolejnosc odnalezienia wierzcholka: "<<s.NumerWierz<<endl;
    wy<<"Pole: "<<s.Wierz.ZwrocDane()<<endl;
    wy<<"F(n): "<<s.FF<<endl;
    wy<<"G(n): "<<s.FG<<endl;
    wy<<"H(n): "<<s.FH<<endl;

    return wy;

}


template class Graf<int,char>;
