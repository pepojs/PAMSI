#include <iostream>
#include "Klasa_drzewo.hpp"

int main()
{
    DrzewoAVL<int> drzewo(1);

    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(1));
    int wezel;
    char menu = 0;
    while(menu != 'q')
    {
        system("cls");//Uzycie polecenia systemowego (Windows) do wyczyszczenia konsoli
        cout<<"     MENU     "<<endl;
        cout<<"d - dodaj nowy wezel"<<endl;
        cout<<"u - usun wezel o danej wartosci"<<endl;
        cout<<"p - przegladaj drzewo"<<endl;
        cout<<"w - wyswieta drzewo"<<endl;
        cout<<"q - koniec programu"<<endl;
        cout<<"Podaj opcje: "<<endl;
        cin>> menu;
        switch(menu)
        {
            case 'd':

                cout<<"Podaj wartosc wezla do dodania: "<<endl;
                cin>>wezel;
                if(cin.fail()) // Zabezpieczenie przed wprowadzeniem niewlasciwych danych
                {
                    cin.clear();
                    cin.ignore(1000,'\n');

                    cout<<"Niewlasciwa wartosc dla wartosci wezla"<<endl;
                    system("timeout 5");//Uzycie polecenia systemowego (Windows) do opoznienia aby mozna przeczytac komunikat
                    continue;
                }

                drzewo.Dodawani_Wezla(wezel);

            break;

            case 'u':
                cout<<"Podaj wartosc wezla do usuniecia"<<endl;
                cin>>wezel;

                if(cin.fail()) // Zabezpieczenie przed wprowadzeniem niewlasciwych danych
                {
                    cin.clear();
                    cin.ignore(1000,'\n');

                    cout<<"Niewlasciwa wartosc dla wartosci wezla"<<endl;
                    system("timeout 5"); //Uzycie polecenia systemowego (Windows) do opoznienia aby mozna przeczytac komunikat
                    continue;
                }


                drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(wezel));

            break;

            case 'p':
                drzewo.Przegladaj_Drzewo();

            break;

            case 'w':
                drzewo.Wyswietl_Drzewo();
                system("timeout 5");//Uzycie polecenia systemowego (Windows) do opoznienia aby mozna przeczytac komunikat

            break;

            case 'q':
            break;

            default:
                cout<<"Nieznana opcja, sprobuj jeszcze raz"<<endl;

            break;
        }
    }
    /*DrzewoAVL<int> drzewo(1);

    drzewo.Dodawani_Wezla(10);
    drzewo.Dodawani_Wezla(20);
    drzewo.Dodawani_Wezla(15);
    drzewo.Dodawani_Wezla(30);
    drzewo.Dodawani_Wezla(25);
    drzewo.Dodawani_Wezla(40);
    drzewo.Dodawani_Wezla(24);

    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(24));
    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(1));
    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(10));
    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(40));
    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(25));
    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(15));
    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(20));
    drzewo.Przegladaj_Drzewo();
    drzewo.Usuwanie_Wezla(drzewo.ZnajdzWezel(1));
    drzewo.Przegladaj_Drzewo();*/

    return 0;
}
