#include "Klasa_drzewo.hpp"

using namespace std;

DrzewoAVL::DrzewoAVL()
{
    rodzic = NULL;
    lewy = NULL;
    prawy = NULL;
    wartosc = 0;
    wr = 0;
}

DrzewoAVL::DrzewoAVL(TYP_DANYCH pocz_wartosc)
{
    rodzic = NULL;
    lewy = NULL;
    prawy = NULL;
    wartosc = pocz_wartosc;
    wr = 0;
}

void DrzewoAVL::Rotacja_PP(DrzewoAVL* &korzen, DrzewoAVL* Wezel_Gorny)
{
    DrzewoAVL* temp;
    DrzewoAVL* ojciecW;

    temp = Wezel_Gorny->prawy;
    ojciecW = Wezel_Gorny->rodzic;

    Wezel_Gorny->prawy = temp->lewy;

    if(Wezel_Gorny->prawy != NULL) Wezel_Gorny->prawy->rodzic = Wezel_Gorny;

    temp->lewy = Wezel_Gorny;
    temp->rodzic = ojciecW;
    Wezel_Gorny->rodzic = temp;

    if(ojciecW == NULL) korzen = temp;
    else if(ojciecW->lewy == Wezel_Gorny) ojciecW->lewy = temp;
    else ojciecW->prawy = temp;

    if(temp->wr == -1)
    {
        Wezel_Gorny->wr = 0;
        temp->wr = 0;
    }else
    {
        Wezel_Gorny->wr = -1;
        temp->wr = 1;
    }
}

void DrzewoAVL::Dodawani_Wezla(TYP_DANYCH nowa_wartosc)
{
    DrzewoAVL* Wpom, *Wpom_rodz;
    DrzewoAVL* pom = new DrzewoAVL(nowa_wartosc);

    Wpom = this;

    if(Wpom == NULL) Wpom = pom; //Dobrze ???
    else
    {
        //Dodawanie nowego wezla
        while(1)
        {
            if(Wpom->wartosc == nowa_wartosc)
            {
                cout<<"Taki wezel juz istnieje"<<endl;
                delete(pom);
                return;
            }else if(Wpom->wartosc > nowa_wartosc)
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
                    if(Wpom_rodz->lewy = Wpom) Wpom_rodz->wr = 1;
                    else Wpom_rodz->wr = -1;

                }else if(Wpom_rodz->wr == 1) //posiada lewa galaz
                {
                    if(Wpom_rodz->prawy == Wpom) Wpom_rodz->wr = 0; //Jezeli dodano galaz z prawej strony to wr sie rownowazy
                    //Jezeli posiada galaz z lewej strony oraz wezel nizej ma galaz z prawej, nalezy zrobic rotacje LR
                    else if(Wpom->wr == -1); //LR();
                    //Jezeli posiada galaz z prawej strony oraz wezel nizej ma galaz z lewej, nalezy zrobic rotacje LL
                    else; //LL();
                    break;

                }else //posiada prawa galaz
                {
                    if(Wpom_rodz->lewy == Wpom) Wpom_rodz = 0; //Jezeli dodano galaz z lewej strony to wr sie rownowazy
                    //Jezeli posiada galaz z prawej strony oraz wezel nizej ma galaz z lewej, nalezy zrobic rotacje RL
                    else if(Wpom->wr == 1); //RL();
                    //Jezeli posiada galaz z prawej strony oraz wezel nizej ma galaz z prawej, nalezy zrobic rotacje RR
                    else ;//RR()
                    break;
                }


                Wpom = Wpom_rodz;
                Wpom_rodz = Wpom_rodz->rodzic;

            }

        }
    }
}

void DrzewoAVL::Wyswietl_Wezel(DrzewoAVL* wezel)
{
    if(wezel->rodzic == NULL)
        cout<<"To jest korzen"<<endl;
    else
        cout<<"Wartosc wezla rodzica: "<<wezel->rodzic->wartosc<<endl;

    cout<<"Wartosc wezla: "<<wezel->wartosc<<endl;

    if(wezel->lewy == NULL)
        cout<<"Brak lewej galezi"<<endl;
    else
        cout<<"Wartosc lewej galezi: "<<wezel->lewy->wartosc<<endl;

    if(wezel->prawy == NULL)
        cout<<"Brak prawej galezi"<<endl;
    else
        cout<<"Wartosc prawej galezi: "<<wezel->prawy->wartosc<<endl;

    cout<<"Wspolczynnik rownowagi wezla: "<<wezel->wr<<endl;
}

void DrzewoAVL::Przegladaj_Drzewo()
{
    DrzewoAVL* Wpom;
    char Cpom;

    Wpom = this;

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

        this->Wyswietl_Wezel(Wpom);

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




