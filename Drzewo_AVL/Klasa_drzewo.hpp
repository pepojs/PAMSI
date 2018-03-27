#ifndef KLASA_DRZEWO_HPP
#define KLASA_DRZEWO_HPP

#include <iostream>
#include <cstdlib>

#include "Struktura_wezel.hpp"

//#define TYP_DANYCH int

using namespace std;

template<class TYP_DANYCH>
class DrzewoAVL
{
    Wezel<TYP_DANYCH>* korzen;

    void Rotacja_PP(Wezel<TYP_DANYCH>* Wezel_Gorny);
    void Rotacja_LL(Wezel<TYP_DANYCH>* Wezel_Gorny);
    void Rotacja_PL(Wezel<TYP_DANYCH>* Wezel_Gorny);
    void Rotacja_LP(Wezel<TYP_DANYCH>* Wezel_Gorny);

    public:

    DrzewoAVL();
    DrzewoAVL(TYP_DANYCH pocz_wartosc);
    ~DrzewoAVL();

    void Dodawani_Wezla(TYP_DANYCH nowa_wartosc);
    TYP_DANYCH Usuwanie_Wezla(Wezel<TYP_DANYCH>* UWezel);
    void Przegladaj_Drzewo();
    Wezel<TYP_DANYCH>* ZnajdzWezel(TYP_DANYCH szukana_wartosc);
    void Wyswietl_Drzewo();
    void Wyswietl_Wysokosc_Drzewa();

    void Przejscie_Wzdluzne(Wezel<TYP_DANYCH>* wezel);
    void Przejscie_Wsteczne(Wezel<TYP_DANYCH>* wezel);
    void Przejscie_Poprzeczne(Wezel<TYP_DANYCH>* wezel);
};

template<class TYP_DANYCH>DrzewoAVL<TYP_DANYCH>::DrzewoAVL()
{
    korzen = new Wezel<TYP_DANYCH>();
}

template<class TYP_DANYCH>DrzewoAVL<TYP_DANYCH>::DrzewoAVL(TYP_DANYCH pocz_wartosc)
{
    korzen = new Wezel<TYP_DANYCH>(pocz_wartosc);
}

template<class TYP_DANYCH>DrzewoAVL<TYP_DANYCH>::~DrzewoAVL()
{
    while(korzen != NULL)
    {
        this->Usuwanie_Wezla(korzen);
    }
    delete(korzen);
}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Rotacja_PP(Wezel<TYP_DANYCH>* Wezel_Gorny)
{
    Wezel<TYP_DANYCH>* Wpom;
    Wezel<TYP_DANYCH>* Wpom_rodzic;

    Wpom = Wezel_Gorny->prawy;
    Wpom_rodzic = Wezel_Gorny->rodzic;

    Wezel_Gorny->prawy = Wpom->lewy;

    if(Wezel_Gorny->prawy != NULL) Wezel_Gorny->prawy->rodzic = Wezel_Gorny;

    Wpom->lewy = Wezel_Gorny;
    Wpom->rodzic = Wpom_rodzic;
    Wezel_Gorny->rodzic = Wpom;

    if(Wpom_rodzic == NULL) this->korzen = Wpom;
    else
    {
        if(Wpom_rodzic->lewy == Wezel_Gorny) Wpom_rodzic->lewy = Wpom;
        else Wpom_rodzic->prawy = Wpom;
    }

    if(Wpom->wr == -1)
    {
        Wezel_Gorny->wr = 0;
        Wpom->wr = 0;
    }else
    {
        Wezel_Gorny->wr = -1;
        Wpom->wr = 1;
    }
}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Rotacja_LL(Wezel<TYP_DANYCH>* Wezel_Gorny)
{
    Wezel<TYP_DANYCH>* Wpom;
    Wezel<TYP_DANYCH>* Wpom_rodzic;

    Wpom = Wezel_Gorny->lewy;
    Wpom_rodzic = Wezel_Gorny->rodzic;

    Wezel_Gorny->lewy = Wpom->prawy;

    if(Wezel_Gorny->lewy != NULL) Wezel_Gorny->lewy->rodzic = Wezel_Gorny;

    Wpom->prawy = Wezel_Gorny;
    Wpom->rodzic = Wpom_rodzic;
    Wezel_Gorny->rodzic = Wpom;

    if(Wpom_rodzic == NULL) this->korzen = Wpom;
    else
    {
        if(Wpom_rodzic->lewy == Wezel_Gorny) Wpom_rodzic->lewy = Wpom;
        else Wpom_rodzic->prawy = Wpom;
    }

    if(Wpom->wr == 1)
    {
        Wezel_Gorny->wr = 0;
        Wpom->wr = 0;
    }else
    {
        Wezel_Gorny->wr = 1;
        Wpom->wr = -1;
    }

}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Rotacja_PL(Wezel<TYP_DANYCH>* Wezel_Gorny)
{
    Wezel<TYP_DANYCH>* Wpom_l, *Wpom_p;
    Wezel<TYP_DANYCH>* Wpom_rodzic;

    Wpom_p = Wezel_Gorny->prawy;
    Wpom_l = Wpom_p->lewy;

    Wpom_rodzic = Wezel_Gorny->rodzic;

    Wpom_p->lewy = Wpom_l->prawy;
    if(Wpom_p->lewy != NULL) Wpom_p->lewy->rodzic = Wpom_p;

    Wezel_Gorny->prawy = Wpom_l->lewy;
    if(Wezel_Gorny->prawy != NULL) Wezel_Gorny->prawy->rodzic = Wezel_Gorny;

    Wpom_l->lewy = Wezel_Gorny;
    Wpom_l->prawy = Wpom_p;
    Wezel_Gorny->rodzic = Wpom_l;
    Wpom_p->rodzic = Wpom_l;

    Wpom_l->rodzic = Wpom_rodzic;

    if(Wpom_rodzic == NULL) this->korzen = Wpom_l;
    else
    {
        if(Wpom_rodzic->lewy == Wezel_Gorny) Wpom_rodzic->lewy = Wpom_l;
        else Wpom_rodzic->prawy = Wpom_l;
    }

    if(Wpom_l->wr == -1) Wezel_Gorny->wr = 1;
    else Wezel_Gorny->wr = 0;

    if(Wpom_l->wr == 1) Wpom_p->wr = -1;
    else Wpom_p->wr = 0;

    Wpom_l->wr = 0;

}
template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Rotacja_LP(Wezel<TYP_DANYCH>* Wezel_Gorny)
{
    Wezel<TYP_DANYCH>* Wpom_l, *Wpom_p;
    Wezel<TYP_DANYCH>* Wpom_rodzic;

    Wpom_l = Wezel_Gorny->lewy;
    Wpom_p = Wpom_l->prawy;


    Wpom_rodzic = Wezel_Gorny->rodzic;

    Wpom_l->prawy = Wpom_p->lewy;
    if(Wpom_l->prawy != NULL) Wpom_l->prawy->rodzic = Wpom_l;

    Wezel_Gorny->lewy = Wpom_p->prawy;
    if(Wezel_Gorny->lewy != NULL) Wezel_Gorny->lewy->rodzic = Wezel_Gorny;

    Wpom_p->prawy = Wezel_Gorny;
    Wpom_p->lewy = Wpom_l;
    Wezel_Gorny->rodzic = Wpom_p;
    Wpom_l->rodzic = Wpom_p;
    Wpom_p->rodzic = Wpom_rodzic;

    if(Wpom_rodzic == NULL) this->korzen = Wpom_p;
    else
    {
        if(Wpom_rodzic->lewy == Wezel_Gorny) Wpom_rodzic->lewy = Wpom_p;
        else Wpom_rodzic->prawy = Wpom_p;
    }

    if(Wpom_p->wr == 1) Wezel_Gorny->wr = -1;
    else Wezel_Gorny->wr = 0;

    if(Wpom_p->wr == -1) Wpom_l->wr = 1;
    else Wpom_l->wr = 0;

    Wpom_p->wr = 0;
}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Dodawani_Wezla(TYP_DANYCH nowa_wartosc)
{
    Wezel<TYP_DANYCH>* Wpom, *Wpom_rodz;
    Wezel<TYP_DANYCH>* pom = new Wezel<TYP_DANYCH>(nowa_wartosc);

    Wpom = this->korzen;

    if(Wpom == NULL) korzen = pom; //Dobrze ???
    else
    {
        //Dodawanie nowego wezla
        while(1)
        {
            /*if(Wpom->wartosc == nowa_wartosc)
            {
                cout<<"Taki wezel juz istnieje"<<endl;
                delete(pom);
                return;
            }else */if(Wpom->wartosc > nowa_wartosc)
            {
                if(Wpom->lewy == NULL)
                {
                    Wpom->lewy = pom;
                    break;
                }else
                {
                    Wpom = Wpom->lewy;
                }
            }else
            {
                if(Wpom->prawy == NULL)
                {
                    Wpom->prawy = pom;
                    break;
                }else
                {
                    Wpom = Wpom->prawy;
                }
            }
        }

        pom->rodzic = Wpom;

        //Rownowazenie drzewa
        if(Wpom->wr != 0) Wpom->wr = 0; // Jezeli wr rozne od zera (ma 1 galaz) to dodanie galezi powoduje rownowage
        else
        {
            //Sprawdza gdzie dodano galaz i zmienia odpowiednio wr
            if(Wpom->lewy == pom) Wpom->wr = 1;
            else Wpom->wr = -1;

            //Idac w strone korzenia zmienia wr
            Wpom_rodz = Wpom->rodzic;

            while(Wpom_rodz != NULL)
            {
                if(Wpom_rodz->wr == 0)
                {
                    //Jezeli wr bylo 0, to sprawdzamy z ktorej strony dodano galaz i zmieniamy wr.
                    if(Wpom_rodz->lewy == Wpom) Wpom_rodz->wr = 1;
                    else Wpom_rodz->wr = -1;

                }else if(Wpom_rodz->wr == 1) //posiada lewa galaz
                {
                    if(Wpom_rodz->prawy == Wpom) Wpom_rodz->wr = 0; //Jezeli dodano galaz z prawej strony to wr sie rownowazy
                    //Jezeli posiada galaz z lewej strony oraz wezel nizej ma galaz z prawej, nalezy zrobic rotacje LP
                    else if(Wpom->wr == -1) Rotacja_LP(Wpom_rodz); //LP();
                    //Jezeli posiada galaz z prawej strony oraz wezel nizej ma galaz z lewej, nalezy zrobic rotacje LL
                    else Rotacja_LL(Wpom_rodz); //LL();
                    break;

                }else //posiada prawa galaz
                {
                    if(Wpom_rodz->lewy == Wpom) Wpom_rodz->wr = 0; //Jezeli dodano galaz z lewej strony to wr sie rownowazy
                    //Jezeli posiada galaz z prawej strony oraz wezel nizej ma galaz z lewej, nalezy zrobic rotacje PL
                    else if(Wpom->wr == 1) Rotacja_PL(Wpom_rodz); //PL();
                    //Jezeli posiada galaz z prawej strony oraz wezel nizej ma galaz z prawej, nalezy zrobic rotacje PP
                    else Rotacja_PP(Wpom_rodz);//PP()
                    break;
                }


                Wpom = Wpom_rodz;
                Wpom_rodz = Wpom_rodz->rodzic;

            }

        }
    }
}

template<class TYP_DANYCH> TYP_DANYCH DrzewoAVL<TYP_DANYCH>::Usuwanie_Wezla(Wezel<TYP_DANYCH>* UWezel)
{
    Wezel<TYP_DANYCH>* Wpom, *Wpom_rodzic, *Wpom2, *Wpom3;
    TYP_DANYCH pom;

    //Jezeli wspaznik na wezel do usuniecia jest pusty
    if(UWezel == NULL)
    {
        cout<<"Wezel ktory chcesz usunac nie istnieje"<<endl;
        return -1;
    }
    if((UWezel->lewy != NULL) && (UWezel->prawy != NULL)) //Jezeli wezel do usuniecia ma 2 synow
    {
        //Najpierw przechodzi do prawego poddrzewa
        Wpom = UWezel->prawy;
        Wpom_rodzic = UWezel;

        //Potem szuka tak dlugo az znajdzie wezel o najmniejszej wartosci, bez 2 synow
        while((Wpom->lewy != NULL) && (Wpom->prawy != NULL))
        {
            Wpom = Wpom->lewy;
        }

        //Jezeli znaleziony wezel ma tylko prawego syna
        if(Wpom->prawy != NULL)
        {
            Wpom->wr = 0; //Wspolczynnik rownowagi znalezionego wezla zostaje wyzerowany

            //Ustawia wskazniki do pozniejszego rownowazenia drzewa
            Wpom_rodzic = Wpom->rodzic;
            Wpom2 = Wpom;

            //Zamienia wezel, ktory chcemy usunac z prawym synem znalezionego wezla
            Wpom = Wpom->prawy;
            Wpom->rodzic->prawy = NULL;


            Wpom->rodzic = UWezel->rodzic;
            if(UWezel->rodzic != NULL)
            {
                if(UWezel->rodzic->prawy == UWezel) UWezel->rodzic->prawy = Wpom;
                else UWezel->rodzic->lewy = Wpom;

            }else this->korzen = Wpom;

            Wpom->lewy = UWezel->lewy;
            if(UWezel->lewy != NULL)
            UWezel->lewy->rodzic = Wpom;

            Wpom->prawy = UWezel->prawy;
            if(UWezel->prawy != NULL)
            UWezel->prawy->rodzic = Wpom;

            Wpom->wr = UWezel->wr;
            Wpom_rodzic = Wpom;


        }else if(Wpom->lewy != NULL)//Jezeli znaleziony wezel ma tylko lewego syna
        {
            Wpom->wr = 0; //Wspolczynnik rownowagi znalezionego wezla zostaje wyzerowany

            //Ustawia wskazniki do pozniejszego rownowazenia drzewa
            Wpom_rodzic = Wpom->rodzic;
            Wpom2 = Wpom;

            //Zamienia wezel, ktory chcemy usunac z lewym synem znalezionego wezla
            Wpom = Wpom->lewy;
            Wpom->rodzic->lewy = NULL;

            Wpom->rodzic = UWezel->rodzic;
            if(UWezel->rodzic != NULL)
            {
                if(UWezel->rodzic->prawy == UWezel) UWezel->rodzic->prawy = Wpom;
                else UWezel->rodzic->lewy = Wpom;

            }else this->korzen = Wpom;

            Wpom->lewy = UWezel->lewy;
            if(UWezel->lewy != NULL)
            UWezel->lewy->rodzic = Wpom;

            Wpom->prawy = UWezel->prawy;
            if(UWezel->prawy != NULL)
            UWezel->prawy->rodzic = Wpom;

            Wpom->wr = UWezel->wr;
            Wpom_rodzic = Wpom;

        }else //Jezeli znaleziony wezel nie ma synow
        {

            Wpom_rodzic = Wpom->rodzic;

            //Jezeli znaleziony wezel byl lewym synem
            if(Wpom_rodzic->lewy == Wpom)
            {
                Wpom_rodzic->lewy = NULL;//Zeruje wskaznik na znaleziony wezel
                if(Wpom_rodzic->wr == 0) //Jezeli rodzic znalezionego wezla byl w rownowadze
                {
                    Wpom_rodzic->wr = -1; //Ustawia wspolczynnik rownowagi
                    Wpom_rodzic = NULL; //Przypisanie NULL powoduje, ze drzewo nie bedzie juz rownowazone

                }else //Jezeli rodzic znalezionego wezla ma ciezsze prawe poddrzewo
                {
                    Wpom2 = Wpom_rodzic->prawy; //Ustawia wskaznik do pozniejszego rownowazenia drzewa
                    Rotacja_PP(Wpom_rodzic);
                    Wpom_rodzic = Wpom2->rodzic; //Ustawia wskaznik do pozniejszego rownowazenia drzewa
                }


            }else //Jezeli znaleziony wezel byl prawym synem
            {
                Wpom2 = Wpom_rodzic->prawy; //Ustawia wskaznik do pozniejszego rownowazenia drzewa
                Wpom_rodzic->prawy = NULL; //Zeruje wskaznik na znaleziony wezel
                Wpom->wr = 1; //Ustawia wspolczynnik rownowagi
            }

            //Zamienia znaleziony wezel z wezlem do usuniecia
            Wpom->rodzic = UWezel->rodzic;
            if(UWezel->rodzic != NULL)
            {
                if(UWezel->rodzic->prawy == UWezel) UWezel->rodzic->prawy = Wpom;
                else UWezel->rodzic->lewy = Wpom;

            }else this->korzen = Wpom;

            Wpom->lewy = UWezel->lewy;
            if(UWezel->lewy != NULL)
            UWezel->lewy->rodzic = Wpom;

            if(UWezel->prawy != Wpom)
            {
                Wpom->prawy = UWezel->prawy;
                if(UWezel->prawy != NULL)
                    UWezel->prawy->rodzic = Wpom;
            }

        }

    }else //Jezeli wezel do usuniecia nie mial 2 synow
    {
        //Wezel do usuniecia ma tylko lewego syna
        if(UWezel->lewy != NULL)
        {
            Wpom_rodzic = UWezel->rodzic;

            //Zamienia lewego syna z wezlem do usuniecia
            Wpom = UWezel->lewy;
            UWezel->lewy = NULL;

            Wpom->rodzic = UWezel->rodzic;
            if(UWezel->rodzic != NULL)
            {
                if(UWezel->rodzic->lewy == UWezel) UWezel->rodzic->lewy = Wpom;
                else UWezel->rodzic->prawy = Wpom;

            }else this->korzen = Wpom;

            Wpom2 = Wpom;// Ustawia wskaznik do rownowarzenia drzewa

        }else if(UWezel->prawy != NULL)//Wezel do usuniecia ma tylko prawego syna
        {
            Wpom_rodzic = UWezel->rodzic;

            //Zamienia prawego syna z wezlem do usuniecia
            Wpom = UWezel->prawy;
            UWezel->prawy = NULL;

            Wpom->rodzic = UWezel->rodzic;
            if(UWezel->rodzic != NULL)
            {
                if(UWezel->rodzic->lewy == UWezel) UWezel->rodzic->lewy = Wpom;
                else UWezel->rodzic->prawy = Wpom;

            }else this->korzen = Wpom;

            Wpom2 = Wpom; //Ustawia wskaznik do rownowarzenia drzewa

        }else //Jezeli wezel do usuniecia nie ma synow
        {

            Wpom_rodzic = UWezel->rodzic;

            if(Wpom_rodzic != NULL)//Wezel do usuniecia nie jest korzeniem
            {
                if(Wpom_rodzic->wr == 0) //Jezeli rodzic wezla byl w rownowadze
                    if(Wpom_rodzic->prawy == UWezel) //Jezeli wezel do usuniecia byl prawym synem
                    {
                        Wpom_rodzic->wr = 1;
                        Wpom_rodzic->prawy = NULL;
                        Wpom_rodzic = NULL; //Przypisanie NULL powoduje, ze drzewo nie bedzie juz rownowazone

                    }
                    else //Jezeli wezel do usuniecia byl lewym synem
                    {
                        Wpom_rodzic->wr = -1;
                        Wpom_rodzic->lewy = NULL;
                        Wpom_rodzic = NULL; //Przypisanie NULL powoduje, ze drzewo nie bedzie juz rownowazone
                    }
                else //Jezeli rodzic wezla do usuniecia nie byl w rownowadze
                    if((Wpom_rodzic->wr == 1) && (Wpom_rodzic->lewy == UWezel)) //Poddrzewo z wezlem do usuniecia bylo wyzsze
                    {
                        Wpom_rodzic->wr = 0;
                        Wpom_rodzic->lewy = NULL;
                        Wpom2 = UWezel->rodzic; //Ustawia wskaznik do rownowarzenia drzewa
                        Wpom_rodzic = Wpom2->rodzic; //Ustawia wskaznik do rownowarzenia drzewa

                    }
                    else if((Wpom_rodzic->wr == -1) && (Wpom_rodzic->prawy == UWezel)) //Poddrzewo z wezlem do usuniecia bylo wyzsze
                    {
                        Wpom_rodzic->wr = 0;
                        Wpom_rodzic->prawy = NULL;
                        Wpom2 = UWezel->rodzic; //Ustawia wskaznik do rownowarzenia drzewa
                        Wpom_rodzic = Wpom2->rodzic; //Ustawia wskaznik do rownowarzenia drzewa

                    }
                    else if((Wpom_rodzic->wr == -1) && (Wpom_rodzic->lewy == UWezel)) //Poddrzewo z wezlem do usuniecia bylo nizsze
                    {
                        Wpom_rodzic->lewy = NULL;
                        Wpom2 = Wpom_rodzic->prawy; //Ustawia wskaznik do rownowarzenia drzewa

                        if(Wpom_rodzic->prawy->wr == -1) //Wyzsze poddrzewo (bez wezla do usuniecia) bylo niezrownowazone z prawej
                        {
                            Rotacja_PP(Wpom_rodzic);
                            Wpom_rodzic = Wpom2->rodzic; //Ustawia wskaznik do rownowarzenia drzewa

                        }else if(Wpom_rodzic->prawy->wr == 1)//Wyzsze poddrzewo (bez wezla do usuniecia) bylo niezrownowazone z lewej
                        {
                            Rotacja_PL(Wpom_rodzic);
                            Wpom2 = Wpom2->rodzic; //Ustawia wskaznik do rownowarzenia drzewa
                            Wpom_rodzic = Wpom2->rodzic; //Ustawia wskaznik do rownowarzenia drzewa

                        }else //Wyzsze poddrzewo (bez wezla do usuniecia) bylo zrownowazone
                        {
                            Rotacja_PP(Wpom_rodzic);
                            Wpom_rodzic = NULL; //Przypisanie NULL powoduje, ze drzewo nie bedzie juz rownowazone
                        }

                    }
                    else if((Wpom_rodzic->wr == 1) && (Wpom_rodzic->prawy == UWezel)) //Poddrzewo z wezlem do usuniecia bylo nizsze
                    {
                        Wpom_rodzic->prawy = NULL;
                        Wpom2 = Wpom_rodzic->lewy; //Ustawia wskaznik do rownowarzenia drzewa

                        if(Wpom_rodzic->lewy->wr == 1) //Wyzsze poddrzewo (bez wezla do usuniecia) bylo niezrownowazone z lewej
                        {
                            Rotacja_LL(Wpom_rodzic);
                            Wpom_rodzic = Wpom2->rodzic; //Ustawia wskaznik do rownowarzenia drzewa

                        }else if(Wpom_rodzic->lewy->wr == -1) //Wyzsze poddrzewo (bez wezla do usuniecia) bylo niezrownowazone z prawej
                        {
                            Rotacja_LP(Wpom_rodzic);
                            Wpom2 = Wpom2->rodzic; //Ustawia wskaznik do rownowarzenia drzewa
                            Wpom_rodzic = Wpom2->rodzic; //Ustawia wskaznik do rownowarzenia drzewa

                        }else //Wyzsze poddrzewo (bez wezla do usuniecia) bylo zrownowazone
                        {
                            Rotacja_LL(Wpom_rodzic);
                            Wpom_rodzic = NULL; //Przypisanie NULL powoduje, ze drzewo nie bedzie juz rownowazone
                        }

                    }


            }else
            {
                this->korzen = NULL;
            }

        }

        UWezel->wr = 0;

    }



    //Rownowazenie drzewa w strone korzenia
    while(Wpom_rodzic != NULL)
    {
        //Skrócenie galezi w jednym z poddrzew kiedy wezel byl w rownowadze, nie skraca wysokosci calosci
        if(Wpom_rodzic->wr == 0)
        {
            if(Wpom_rodzic->lewy == Wpom2) Wpom_rodzic->wr = -1;
            else Wpom_rodzic->wr = 1;
            break;

        }else
        {
            // Skracanie ciezszej galezi, rownowazy wezel, ale wyzej moze byc niezrownowazone
            if(((Wpom_rodzic->wr == 1) && (Wpom_rodzic->lewy == Wpom2)) || ((Wpom_rodzic->wr == -1) && (Wpom_rodzic->prawy == Wpom2)))
            {
                Wpom_rodzic->wr = 0;
                Wpom2 = Wpom_rodzic;
                Wpom_rodzic = Wpom_rodzic->rodzic;
            }else //Skrocenie lzejszego poddrzewa
            {
                //Przypisanie wskaznika ciezszej galezi do Wpom2
                if(Wpom_rodzic->lewy == Wpom2) Wpom3 = Wpom_rodzic->prawy;
                else Wpom3 = Wpom_rodzic->lewy;

                //Jezeli ciezsze poddrzewo jest w rownowadze, nalezy zrobic odpowiednia rotacje aby zrownowazyc drzewo
                if(Wpom3->wr == 0)
                {
                    if(Wpom_rodzic->wr == 1) Rotacja_LL(Wpom2);
                    else Rotacja_PP(Wpom2);
                    break;
                }else if(Wpom3->wr == Wpom_rodzic->wr) //Jezeli ciezsze poddrzewo ma taki sam wspolczynnik rownowagi, rotacja zmieni wysokosc
                {
                    if(Wpom_rodzic->wr == 1) Rotacja_LL(Wpom2);
                    else Rotacja_PP(Wpom2);
                    Wpom2 = Wpom3;
                    Wpom_rodzic = Wpom3->rodzic;
                }else //Jezeli wspolczynniki sa przeciwne
                {
                        //Po rotacji zmiejszy sie wysokosc poddrzewa
                    if(Wpom_rodzic->wr == 1) Rotacja_LP(Wpom2->rodzic);
                    else Rotacja_PL(Wpom2->rodzic);
                    Wpom2 = Wpom_rodzic->rodzic;
                    Wpom_rodzic = Wpom2->rodzic;
                }

            }
        }
    }

    pom = UWezel->wartosc;
    delete UWezel; // Czysci zaalakowana pamiec

    return pom; //Zwraca zawartosc wezla
}

//Funkcja sluzaca do wyswietlania wartosci poszczegulnych wezlow drzewa
template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Przegladaj_Drzewo()
{
    Wezel<TYP_DANYCH>* Wpom;
    char Cpom;

    Wpom = this->korzen;

    do
    {
        system("cls"); //Uzycie polecenia systemowego (Windows) do wyczyszczenia konsoli
        cout<<"\t Przegladanie drzewa"<<endl;
        cout<<endl;
        cout<<"Menu: "<<endl;
        cout<<"Przejscie do wezla rodzica: r"<<endl;
        cout<<"Przejscie do lewej galezi: l"<<endl;
        cout<<"Przejscie do prawej galezi: p"<<endl;
        cout<<"Koniec przegladania drzewa: q"<<endl;
        cout<<endl;

        Wpom->Wyswietl_Wezel();

        cout<<endl;
        cout<<"Podaj polecenie: "<<endl;
        cin>>Cpom;

        switch(Cpom)
        {
            case 'r' :

                if(Wpom != NULL)
                {
                    if(Wpom->rodzic != NULL) Wpom = Wpom->rodzic;
                    else
                    {
                        cout<<"To jest korzen, nie mozna przejsc wyzej"<<endl;
                        system("timeout 5");//Uzycie polecenia systemowego (Windows) do opoznienia aby mozna przeczytac komunikat
                    }
                }
            break;

            case 'l':
                if(Wpom != NULL)
                {
                    if(Wpom->lewy != NULL) Wpom = Wpom->lewy;
                    else
                    {
                        cout<<"Brak lewej galezi"<<endl;
                        system("timeout 5");//Uzycie polecenia systemowego (Windows) do opoznienia aby mozna przeczytac komunikat
                    }
                }
            break;

            case 'p':
                if(Wpom != NULL)
                {
                    if(Wpom->prawy != NULL) Wpom = Wpom->prawy;
                    else
                    {
                        cout<<"Brak prawej galezi"<<endl;
                        system("timeout 5");//Uzycie polecenia systemowego (Windows) do opoznienia aby mozna przeczytac komunikat
                    }
                }
            break;

            case 'q':
            break;

        }


    }while(Cpom != 'q');
}

//Wyszukuje wskaznik na wezel z szukana wartoscia
template<class TYP_DANYCH> Wezel<TYP_DANYCH>* DrzewoAVL<TYP_DANYCH>::ZnajdzWezel(TYP_DANYCH szukana_wartosc)
{
    Wezel<TYP_DANYCH>* Wpom = this->korzen;
    while((Wpom != NULL) && (Wpom->wartosc != szukana_wartosc))
    {
        if(szukana_wartosc < Wpom->wartosc) Wpom = Wpom->lewy;
        else Wpom = Wpom->prawy;
    }

    return Wpom;
}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Przejscie_Wzdluzne(Wezel<TYP_DANYCH>* wezel)
{
    if(wezel == NULL)return;
    cout<<wezel->wartosc<<" ";
    Przejscie_Wzdluzne(wezel->lewy);
    Przejscie_Wzdluzne(wezel->prawy);

}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Przejscie_Wsteczne(Wezel<TYP_DANYCH>* wezel)
{
    if(wezel == NULL)return;
    Przejscie_Wsteczne(wezel->lewy);
    Przejscie_Wsteczne(wezel->prawy);
    cout<<wezel->wartosc<<" ";

}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Przejscie_Poprzeczne(Wezel<TYP_DANYCH>* wezel)
{
    if(wezel == NULL)return;
    Przejscie_Poprzeczne(wezel->lewy);
    cout<<wezel->wartosc<<" ";
    Przejscie_Poprzeczne(wezel->prawy);

}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Wyswietl_Drzewo()
{
    cout<<"Przejscie wzdluzne (PRE-ORDER):"<<endl;
    Przejscie_Wzdluzne(korzen);
    cout<<endl<<"Przejscie wsteczne (POST-ORDER) :"<<endl;
    Przejscie_Wsteczne(korzen);
    cout<<endl<<"Przejscie poprzeczne (IN-ORDER) :"<<endl;
    Przejscie_Poprzeczne(korzen);
    cout<<endl;
}

template<class TYP_DANYCH> void DrzewoAVL<TYP_DANYCH>::Wyswietl_Wysokosc_Drzewa()
{
    Wezel<TYP_DANYCH>* Wpom = korzen;
    int wysokosc = 1;

    if(korzen == NULL)
    {
        cout<<"Drzewo jest puste"<<endl;
        return;
    }

    while(Wpom->lewy != NULL)
    {
        wysokosc += 1;
        Wpom = Wpom->lewy;
    }

    if(Wpom->prawy != NULL)
        wysokosc += 1;

    if(korzen->wr == -1)
        wysokosc += 1;

    cout<<"Wysokosc drzewa wynosi: "<<wysokosc<<endl;
}

#endif
