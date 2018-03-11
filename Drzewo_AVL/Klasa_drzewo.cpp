#include "Klasa_drzewo.hpp"

using namespace std;

DrzewoAVL::DrzewoAVL()
{
    korzen = new Wezel();
}

DrzewoAVL::DrzewoAVL(TYP_DANYCH pocz_wartosc)
{
    korzen = new Wezel(pocz_wartosc);
}

DrzewoAVL::~DrzewoAVL()
{
    delete(korzen);
}

void DrzewoAVL::Rotacja_PP(Wezel* Wezel_Gorny)
{
    Wezel* Wpom;
    Wezel* Wpom_rodzic;

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

void DrzewoAVL::Rotacja_LL(Wezel* Wezel_Gorny)
{
    Wezel* Wpom;
    Wezel* Wpom_rodzic;

    Wpom = Wezel_Gorny->lewy;
    Wpom_rodzic = Wezel_Gorny->rodzic;

    Wezel_Gorny->lewy = Wezel_Gorny->prawy;

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

void DrzewoAVL::Rotacja_PL(Wezel* Wezel_Gorny)
{
    Wezel* Wpom_l, *Wpom_p;
    Wezel* Wpom_rodzic;

    Wpom_p = Wezel_Gorny->prawy;
    Wpom_l = Wpom_p->lewy;

    Wpom_rodzic = Wezel_Gorny->rodzic;

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
void DrzewoAVL::Rotacja_LP(Wezel* Wezel_Gorny)
{
    Wezel* Wpom_l, *Wpom_p;
    Wezel* Wpom_rodzic;

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

void DrzewoAVL::Dodawani_Wezla(TYP_DANYCH nowa_wartosc)
{
    Wezel* Wpom, *Wpom_rodz;
    Wezel* pom = new Wezel(nowa_wartosc);

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

TYP_DANYCH DrzewoAVL::Usuwanie_Wezla(Wezel* UWezel)
{
    Wezel* Wpom, *Wpom_rodzic, *Wpom2, *Wpom3;

    if((UWezel->lewy != NULL) && (UWezel->prawy != NULL))
    {
        Wpom = UWezel->prawy;
        //UWezel->prawy = NULL;
        //Wpom_lewy = UWezel->lewy;
        Wpom_rodzic = UWezel;

        if((Wpom->lewy != NULL) && (Wpom->prawy != NULL))
        {

            /*Wpom->rodzic = Wpom_rodzic->rodzic;
            if(Wpom_rodzic->rodzic != NULL)
            {
                if(Wpom_rodzic->rodzic->prawy == Wpom_rodzic) Wpom_rodzic->rodzic->prawy = Wpom;
                else Wpom_rodzic->rodzic->lewy = Wpom;

            }else this->korzen = Wpom;*/

            while((Wpom->lewy != NULL) && (Wpom->prawy != NULL))
            {
                /*Wpom2 = Wpom->lewy; //Zapamientuje lewa galaz
                Wpom->lewy = Wpom_lewy; //Podmienia lewa galaz lewa galezia rodzica
                Wpom_lewy->rodzic = Wpom;

                Wpom_rodzic = Wpom;
                Wpom_lewy = Wpom2;

                Wpom->wr = 0;*/

                Wpom = Wpom->lewy;

            }
        }

        if(Wpom->prawy != NULL)
        {
            /*Wpom->lewy = Wpom_lewy; //Podmienia lewa galaz lewa galezia rodzica
            Wpom_lewy->rodzic = Wpom;*/


            Wpom_rodzic = Wpom->rodzic;
            Wpom2 = Wpom->prawy;

            Wpom->rodzic->lewy = Wpom->prawy;
            Wpom->prawy->rodzic = Wpom->rodzic;


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

            //Wpom->wr = 0;

        }else if(Wpom->lewy != NULL)
        {
            /*Wpom2 = Wpom->lewy;
            Wpom->lewy = NULL;

            Wpom2->rodzic = Wpom->rodzic;
            Wpom->rodzic->prawy = Wpom2;

            Wpom->rodzic = Wpom2;
            Wpom2->prawy = Wpom;

            Wpom2->lewy = Wpom_lewy;
            Wpom_lewy->rodzic = Wpom2;

            Wpom2->wr = 0;
            Wpom->wr = 0;*/

            Wpom->wr = 0;

            Wpom_rodzic = Wpom->rodzic;
            Wpom2 = Wpom;

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

        }else
        {
            /*Wpom->lewy = Wpom_lewy;
            Wpom_lewy->rodzic = Wpom;

            Wpom->wr = 1;*/

            Wpom_rodzic = Wpom->rodzic;

            if(Wpom_rodzic->lewy == Wpom)
            {
                Wpom2 = Wpom_rodzic->lewy;
                Wpom_rodzic->lewy = NULL;

            }else
            {
                Wpom2 = Wpom_rodzic->prawy;
                Wpom_rodzic->prawy = NULL;
            }


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

    }else
    {
        if(UWezel->lewy != NULL)
        {
            Wpom_rodzic = UWezel->rodzic;

            Wpom = UWezel->lewy;
            UWezel->lewy = NULL;

            Wpom->rodzic = UWezel->rodzic;
            if(UWezel->rodzic != NULL)
            {
                if(UWezel->rodzic->lewy == UWezel) UWezel->rodzic->lewy = Wpom;
                else UWezel->rodzic->prawy = Wpom;

            }else this->korzen = Wpom;

            Wpom2 = Wpom;

        }else
        {
            Wpom_rodzic = UWezel->rodzic;

            Wpom = UWezel->prawy;
            UWezel->prawy = NULL;

            Wpom->rodzic = UWezel->rodzic;
            if(UWezel->rodzic != NULL)
            {
                if(UWezel->rodzic->lewy == UWezel) UWezel->rodzic->lewy = Wpom;
                else UWezel->rodzic->prawy = Wpom;

            }else this->korzen = Wpom;

            Wpom2 = Wpom;
        }

        UWezel->wr = 0;

    }




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
                    if(Wpom_rodzic->wr == 1) Rotacja_LP(Wpom2);
                    else Rotacja_PL(Wpom2);
                    Wpom2 = Wpom_rodzic->rodzic;
                    Wpom_rodzic = Wpom2->rodzic;
                }

            }
        }
    }


    return UWezel->wartosc;
}


void DrzewoAVL::Przegladaj_Drzewo()
{
    Wezel* Wpom;
    char Cpom;

    Wpom = this->korzen;

    do
    {
        system("cls");
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
        cin>>Cpom; // Zabezpieczyc !!!!!

        switch(Cpom)
        {
            case 'r' :
                if(Wpom->rodzic != NULL) Wpom = Wpom->rodzic;
                else cout<<"To jest korzen, nie mozna przejsc wyzej"<<endl;
                break;

            case 'l':
                if(Wpom->lewy != NULL) Wpom = Wpom->lewy;
                else cout<<"Brak lewej galezi"<<endl;
                break;

            case 'p':
                if(Wpom->prawy != NULL) Wpom = Wpom->prawy;
                else cout<<"Brak prawej galezi"<<endl;
                break;

            case 'q':
                break;

        }


    }while(Cpom != 'q');
}

Wezel* DrzewoAVL::ZnajdzWezel(TYP_DANYCH szukana_wartosc)
{
    Wezel* Wpom = this->korzen;
    while((Wpom != NULL) && (Wpom->wartosc != szukana_wartosc))
    {
        if(szukana_wartosc < Wpom->wartosc) Wpom = Wpom->lewy;
        else Wpom = Wpom->prawy;
    }

    return Wpom;
}


