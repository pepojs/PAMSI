#include "Klasa_gra.hpp"
#include <ctime>

using namespace std;

int main()
{
    srand( time( NULL ) );

    int x, y, RozmiarPlanszy = 3, IleRzad;
    int fWygralX = 0, fWygralO = 0;
    int fGracz = 0;
    char menu = 0, menu2 = 0;
    Gra Kolko;
    cout<<"-----------Witamy w grze w kolko i krzyzyk-----------"<<endl;
    cout<<endl;
    cout<<endl;



    while(menu != 'k')
    {
        cout<<"    Menu    "<<endl;
        cout<<"s - rozpoczni gre"<<endl;
        cout<<"k - koniec gry"<<endl;
        cout<<"Jaki wybor ? "<<endl;

        cin >> menu;

        switch(menu)
        {
            case 's':
                cout<<"Podaj rozmiar planszy: (od 3 do 50)"<<endl;
                cin >> RozmiarPlanszy;
                if(RozmiarPlanszy > 50 || RozmiarPlanszy < 3)
                {
                    cout<<"Niewlasciwy rozmiar planszy, sprobuj jeszcze raz"<<endl;
                    system("timeout 5");
                    break;
                }

                Kolko.ZmienRozmiar(RozmiarPlanszy);

                if(RozmiarPlanszy == 3)
                {
                    cout<<"Dla planszy 3x3 domyslna ilosc elementow w jednej lini koniecznech do wygrania rowna 3"<<endl;
                    system("timeout 5");
                    IleRzad = 3;

                }else
                {
                    cout<<"Podaj ilosc elementow w jednej lini koniecznech do wygrania: (od 3 do 50)"<<endl;
                    cin >> IleRzad;
                    if((IleRzad > 50 || IleRzad < 3) || IleRzad > RozmiarPlanszy)
                    {
                        cout<<"Niewlasciwa ilosc elementow, sprobuj jeszcze raz"<<endl;
                        system("timeout 5");
                        break;
                    }
                }


                Kolko.ZmienRzad(IleRzad);

                menu2 = 0;
                fGracz = 0;
                while(menu2 != 'p')
                {
                    Kolko.RysujePoleGry();
                    if((fWygralX == 1 || fWygralO == 1) || (fWygralO == -1 || fWygralX == -1))break;

                    cout<<endl;
                    cout<<endl;

                    cout<<"Teraz kolej gracza: ";

                    if(fGracz == 0)
                    {
                        cout<<"X "<<endl;
                        cout<<"Opcje: "<<endl;
                        cout<<"w - wstaw znak w pole: "<<endl;
                        cout<<"p - poddaj sie :( "<<endl;
                        cout<<"Co zrobic ? "<<endl;

                        cin>> menu2;

                    }else if(fGracz == 1)
                    {
                        cout<<"O "<<endl;
                        menu2 = 'w';
                    }


                    switch(menu2)
                    {
                        case 'w':

                            if(fGracz == 0)
                            {
                                cout<<"Podaj kolumne pola gdzie chcesz postawic X: "<<endl;
                                cin>>x;
                                cout<<"Podaj wiersz pola gdzie chcesz postawic X: "<<endl;
                                cin>>y;

                                if((x > Kolko.ZwrocRozmiar() || y > Kolko.ZwrocRozmiar()) || (x < 1 || y < 1))
                                {
                                    cout<<"Nie ma takiego pola, sprobuj jeszcze raz"<<endl;
                                    system("timeout 5");
                                }

                                if(Kolko.WypelniPoleX(x-1,y-1))fGracz = 1;
                                fWygralX = Kolko.SprawdzanieStanuGryX(x-1,y-1);

                            }else if(fGracz == 1)
                            {
                                /*cout<<"Podaj kolumne pola gdzie chcesz postawic O: "<<endl;
                                cin>>x;
                                cout<<"Podaj wiersz pola gdzie chcesz postawic O: "<<endl;
                                cin>>y;

                                if((x > Kolko.ZwrocRozmiar() || y > Kolko.ZwrocRozmiar()) || (x < 1 || y < 1))
                                {
                                    cout<<"Nie ma takiego pola, sprobuj jeszcze raz"<<endl;
                                    system("timeout 5");
                                }

                                if(Kolko.WypelniPoleO(x-1,y-1))fGracz = 0;*/
                                Kolko.MinMax('O',0,-2*IleRzad,2*IleRzad,&fWygralO);
                                //Kolko.WypelniPoleO(x,y);
                                fGracz = 0;
                                //fWygralO = Kolko.SprawdzanieStanuGryO(x,y);
                            }


                        break;

                        case 'p':
                            cout<<"Poddajesz sie ?: (t - tak, n - nie)" <<endl;
                            cin >> menu2;

                            if(menu2 == 't') menu2 = 'p';

                        break;

                        default:
                            cout<<"Nie ma takiej opcji, sprobuj jeszcze raz"<<endl;
                        break;
                    }
                }

            break;

            case 'k':
            break;

            default:
                cout<<"Nieznane polecenie, sprobuje jeszcze raz"<<endl;
            break;
        }

        if(fWygralX == 1)
        {
            cout<<"Wygral gracz X. Gratulacje !!!"<<endl;
            system("timeout 5");
            fWygralX = 0;

        }else if(fWygralX == -1)
        {
            cout<<"Remis !!!"<<endl;
            system("timeout 5");
            fWygralX = 0;
        }

        if(fWygralO == 1)
        {
            cout<<"Wygral gracz O. Gratulacje !!!"<<endl;
            system("timeout 5");
            fWygralO = 0;

        }else if(fWygralO == -1)
        {
            cout<<"Remis !!!"<<endl;
            system("timeout 5");
            fWygralO = 0;
        }

        system("cls");
    }

    return 0;
}
