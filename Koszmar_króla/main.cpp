#include <stdlib.h>
#include "Klasa_graf.hpp"

void RysujPlansze(char kon, char wierza, char krol);

int main()
{
    char kon = 0, wierza = 0, krol = 0, menu = 0;
    int nowa = 0;
    Graf <int, char> graf;

    cout<<endl<<"\t Koszmar krola"<<endl<<endl;
    RysujPlansze(kon, wierza, krol);

    while(menu != 'k')
    {
        if(nowa == 0)
        {
            cout<<"Menu: "<<endl;
            cout<<"n - start"<<endl;
            cout<<"k - koniec"<<endl;
            cin>>menu;

            nowa = 1;
            switch(menu)
            {
                case 'n':

                    do
                    {
                        cout<<"Podaj pozycje konia (od A do Y): "<<endl;
                        cin>>kon;

                    }while(!((kon >= 'A') && (kon <= 'Y')));

                    do
                    {
                        cout<<"Podaj pozycje wierzy (od A do Y): "<<endl;
                        cin>>wierza;

                    }while(!(wierza >= 'A' && wierza <= 'Y' && wierza != kon));

                    do
                    {
                        cout<<"Podaj pozycje krola (od A do Y): "<<endl;
                        cin>>krol;

                    }while(!(krol >= 'A' && krol <= 'Y' && krol != kon && krol != wierza));

                    system("cls");
                    RysujPlansze(kon, wierza, krol);

                    graf.TworzGraf(kon, wierza, krol);
                    graf.DFS(kon, wierza, krol);
                    graf.AGwiazdka(kon, wierza, krol);



                break;

                case 'k':
                break;

                default:
                break;
            }

        }else
        {

            cout<<"Menu: "<<endl;
            cout<<"q - zmiana pozycji konia"<<endl;
            cout<<"w - zmiana pozycji wierzy"<<endl;
            cout<<"e - zmiana pozycji krol"<<endl;
            cout<<"k - koniec"<<endl;
            cin>>menu;

            switch(menu)
            {
                case 'q':
                    do
                    {
                        cout<<"Podaj pozycje konia (od A do Y): "<<endl;
                        cin>>kon;

                    }while(!(kon >= 'A' && kon <= 'Y' && kon != krol && kon != wierza));
                    system("cls");
                    RysujPlansze(kon, wierza, krol);

                    graf.DFS(kon, wierza, krol);
                    graf.AGwiazdka(kon, wierza, krol);

                break;

                case 'w':
                    do
                    {
                        cout<<"Podaj pozycje wierzy (od A do Y): "<<endl;
                        cin>>wierza;

                    }while(!(wierza >= 'A' && wierza <= 'Y' && wierza != kon && wierza != krol));
                    system("cls");
                    RysujPlansze(kon, wierza, krol);

                    graf.TworzGraf(kon, wierza, krol);
                    graf.DFS(kon, wierza, krol);
                    graf.AGwiazdka(kon, wierza, krol);

                break;

                case 'e':
                    do
                    {
                        cout<<"Podaj pozycje krola (od A do Y): "<<endl;
                        cin>>krol;

                    }while(!(krol >= 'A' && krol <= 'Y' && krol != kon && krol != wierza));
                    system("cls");
                    RysujPlansze(kon, wierza, krol);

                    graf.DFS(kon, wierza, krol);
                    graf.AGwiazdka(kon, wierza, krol);

                break;

                case 'k':
                break;

                default:
                break;
            }
        }

    }

    return 0;
}

void RysujPlansze(char kon, char wierza, char krol)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(65+j+5*i == kon)
                cout<<"| "<<1<<" ";
            else if(65+j+5*i == wierza)
                cout<<"| "<<2<<" ";
            else if(65+j+5*i == krol)
                cout<<"| "<<3<<" ";
            else
                cout<<"| "<<char(65+j+5*i)<<" ";

        }cout<<endl;

    }

    cout<<"Kon oznaczony 1, wierza 2, krol 3"<<endl;
}
