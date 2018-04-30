#include "Klasa_gra.hpp"

using namespace std;

Gra::Gra()
{
    Rozmiar = 3;
    IleWRzedzie = 3;
    Pole_gry = new char*[3];

    for(int i = 0; i < 3; i++)
    {
        Pole_gry[i] = new char[3];
        for(int j = 0; j < 3; j++)
        {
            Pole_gry[i][j] = ' ';
        }
    }

}

Gra::Gra(int rozmiar)
{
    Rozmiar = rozmiar;
    IleWRzedzie = 3;

    Pole_gry = new char*[rozmiar];

    for(int i = 0; i < rozmiar; i++)
    {
        Pole_gry[i] = new char[rozmiar];
        for(int j = 0; j < rozmiar; j++)
        {
            Pole_gry[i][j] = ' ';
        }
    }
}

Gra::~Gra()
{
    for(int i = 0; i < Rozmiar; i++)
    {
        delete[] Pole_gry[i];
    }

    delete[] Pole_gry;
    Pole_gry = NULL;
}

void Gra::ZmienRozmiar(int rozmiar)
{
    for(int i = 0; i < Rozmiar; i++)
    {
        delete[] Pole_gry[i];
    }

    delete[] Pole_gry;
    Pole_gry = NULL;

    Rozmiar = rozmiar;
    Pole_gry = new char*[rozmiar];

    for(int i = 0; i < rozmiar; i++)
    {
        Pole_gry[i] = new char[rozmiar];
        for(int j = 0; j < rozmiar; j++)
        {
            Pole_gry[i][j] = ' ';
        }
    }
}

void Gra::ZmienRzad(int rzad)
{
    IleWRzedzie = rzad;
}

void Gra::RysujePoleGry()
{
    string Pole = "";
    stringstream ss; //Strumien do napisu

    system("cls");

    Pole += "   ";
    if(Rozmiar >= 9) Pole += " ";
    for(int i = 0; i < Rozmiar; i++)
    {
        ss.str("");
        ss.clear();
        ss << i+1;
        Pole += ss.str();
        if(i < 8)Pole += "   ";
        else Pole += "  ";
    }

    Pole += "\n";

    for(int i = 0; i < Rozmiar; i++)
    {
        //Numeruje rzedy
        ss.str("");
        ss.clear();
        ss << i+1;
        Pole += ss.str();

        if(Rozmiar >= 9 && i < 9)Pole += " ";

        for(int j = 0; j < Rozmiar; j++)
        {

            Pole += "| ";
            Pole += Pole_gry[i][j];
            Pole += " ";
        }

        Pole += "|\n";

    }

    cout<<Pole;
}

int Gra::WypelniPoleX(int x, int y)
{
    if((x < Rozmiar && y < Rozmiar) && (Pole_gry[y][x] == ' '))
    {
        Pole_gry[y][x] = 'X';
        return 1;

    }else return 0;


}

int Gra::WypelniPoleO(int x, int y)
{
    if((x < Rozmiar && y < Rozmiar) && (Pole_gry[y][x] == ' '))
    {
        Pole_gry[y][x] = 'O';
        return 1;

    }else return 0;

}

int Gra::SprawdzanieStanuGryX(int x, int y)
{
    int rzad = 0, i, j, fpuste = 0;
    if((x >= Rozmiar || y >= Rozmiar) || (x < 0 || y < 0))return 0;

    rzad = 1;
    i = 1;
    j = 1;

    while(1)//Sparwdzenie gora - dol
    {
        if(y-i >= 0)
        {
            if(Pole_gry[y-i][x] == 'X')
            {
                i++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;
            }else i = 100;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

        }else if(y+j <Rozmiar)
        {
            if(Pole_gry[y+j][x] == 'X')
            {
                j++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;
            }else j = 100;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

        }else break;
    }

    rzad = 1;
    i = 1;
    j = 1;

    while(1)// Sprawdzenie w lewo-prawo
    {
        if(x+i < Rozmiar)
        {
            if(Pole_gry[y][x+i] == 'X')
            {
                i++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else i = 100;

        }else if(x-j >= 0)
        {
            if(Pole_gry[y][x-i] == 'X')
            {
                j++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else j = 100;

        }else break;
    }

    rzad = 1;
    i = 1;
    j = 1;

    while(1)// Sprawdzenie po skosie /
    {
        if(x+i < Rozmiar && y-i >= 0)
        {
            if(Pole_gry[y-i][x+i] == 'X')
            {
                i++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else i = 100;

        }else if(x-j >= 0 && y+j < Rozmiar)
        {
            if(Pole_gry[y+j][x-j] == 'X')
            {
                j++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else j = 100;

        }else break;

    }


    rzad = 1;
    i = 1;
    j = 1;

    while(1)// Sprawdzenie po skosie \//
    {
        if(y+i < Rozmiar && x-i >= 0)
        {
            if(Pole_gry[y+i][x-i] == 'X')
            {
                i++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else i = 100;

        }else if(y-j >= 0 && x+j < Rozmiar)
        {
            if(Pole_gry[y-j][x+j] == 'X')
            {
                j++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else j = 100;

        }else break;

    }

    for(i = 0; i < Rozmiar; i++)
    {
        for(j = 0; j < Rozmiar; j++)
            if(Pole_gry[i][j] == ' ')
            {
                fpuste = 1;
                break;
            }
    }

    if(fpuste == 0)return -1; // Remis
    return 0;
}

int Gra::SprawdzanieStanuGryO(int x, int y)
{
    int rzad = 0, i, j, fpuste = 0;
    if((x >= Rozmiar || y >= Rozmiar) || (x < 0 || y < 0))return 0;

    rzad = 1;
    i = 1;
    j = 1;

    while(1)//Sparwdzenie gora - dol
    {
        if(y-i >= 0)
        {
            if(Pole_gry[y-i][x] == 'O')
            {
                i++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;
            }else i = 100;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

        }else if(y+j <Rozmiar)
        {
            if(Pole_gry[y+j][x] == 'O')
            {
                j++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;
            }else j = 100;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

        }else break;
    }

    rzad = 1;
    i = 1;
    j = 1;

    while(1)// Sprawdzenie w lewo-prawo
    {
        if(x+i < Rozmiar)
        {
            if(Pole_gry[y][x+i] == 'O')
            {
                i++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else i = 100;

        }else if(x-j >= 0)
        {
            if(Pole_gry[y][x-i] == 'O')
            {
                j++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else j = 100;

        }else break;
    }

    rzad = 1;
    i = 1;
    j = 1;

    while(1)// Sprawdzenie po skosie /
    {
        if(x+i < Rozmiar && y-i >= 0)
        {
            if(Pole_gry[y-i][x+i] == 'O')
            {
                i++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else i = 100;

        }else if(x-j >= 0 && y+j < Rozmiar)
        {
            if(Pole_gry[y+j][x-j] == 'O')
            {
                j++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else j = 100;

        }else break;

    }


    rzad = 1;
    i = 1;
    j = 1;

    while(1)// Sprawdzenie po skosie \//
    {
        if(y+i < Rozmiar && x-i >= 0)
        {
            if(Pole_gry[y+i][x-i] == 'O')
            {
                i++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else i = 100;

        }else if(y-j >= 0 && x+j < Rozmiar)
        {
            if(Pole_gry[y-j][x+j] == 'O')
            {
                j++;
                rzad+=1;
                if(rzad == IleWRzedzie)return 1;

            }else j = 100;

        }else break;

    }

    for(i = 0; i < Rozmiar; i++)
    {
        for(j = 0; j < Rozmiar; j++)
            if(Pole_gry[i][j] == ' ')
            {
                fpuste = 1;
                break;
            }
    }

    if(fpuste == 0)return -1; // Remis

    return 0;
}

int Gra::MinMax(char gracz, int zaglebienie, int alfa, int beta)
{
    int m, minmax, pom, k, w;

    if(gracz == 'X') minmax = 2;
    else if(gracz == 'O') minmax = -2;

    for(int i = 0; i < Rozmiar; i++)
    {
        for(int j = 0; j < Rozmiar; j++)
        {
            if(Pole_gry[i][j] == ' ')
            {
                if(gracz == 'X')
                {
                    Pole_gry[i][j] = 'X';
                    pom = SprawdzanieStanuGryX(j, i);
                    if(pom == 1) return 1;
                    else if(pom == -1)return 0;
                    else m = MinMax('O', zaglebienie+1, alfa, beta);

                    Pole_gry[i][j] = ' ';

                    if(m < minmax)
                    {
                      minmax = m;
                      w = i;
                      k = j;
                    }

                }else if(gracz == 'O')
                {
                    Pole_gry[i][j] = 'O';
                    pom = SprawdzanieStanuGryO(j, i);
                    if(pom == 1) return -1;
                    else if(pom == -1)return 0;
                    else m = MinMax('X', zaglebienie+1, alfa, beta);

                    Pole_gry[i][j] = ' ';

                    if(m > minmax)
                    {
                      minmax = m;
                      w = i;
                      k = j;
                    }
                }
            }
        }
    }

    if(!zaglebienie)Pole_gry[w][k] = gracz;
    return minmax;
}
