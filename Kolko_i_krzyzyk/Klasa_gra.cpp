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

    if(Pole_gry[y][x] == 'X')
    {
        rzad = 1;
        i = 1;
        j = 1;

        while(1)//Sparwdzenie gora - dol
        {
            if(y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x] == 'X')
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;
                }else i = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

            }else if(y+j <Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x] == 'X')
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;
                }else j = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

            }else break;
        }

        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie w lewo-prawo
        {
            if(x+i < Rozmiar && i > 0)
            {
                if(Pole_gry[y][x+i] == 'X')
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(x-j >= 0 && j > 0)
            {
                if(Pole_gry[y][x-j] == 'X')
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;
        }

        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie po skosie /
        {
            if(x+i < Rozmiar && y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x+i] == 'X')
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(x-j >= 0 && y+j < Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x-j] == 'X')
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;

        }


        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie po skosie \//
        {
            if(y-i >= 0 && x-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x-i] == 'X')
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(y+j < Rozmiar && x+j < Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x+j] == 'X')
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;

        }
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

    if(Pole_gry[y][x] == 'O')
    {
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
                if(Pole_gry[y][x-j] == 'O')
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
            if(y-i >= 0 && x-i >= 0)
            {
                if(Pole_gry[y-i][x-i] == 'O')
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;

                }else i = 100;

            }else if(y+j < Rozmiar && x+j < Rozmiar)
            {
                if(Pole_gry[y+j][x+j] == 'O')
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)return 1;

                }else j = 100;

            }else break;

        }
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

int Gra::FHeurystyczna(char gracz, int x, int y)
{
    int rzad = 0, rzadmax = 0, i, j, wi, wj, fpuste = 0, fkoniec_rzedu = 0;

    if(Pole_gry[y][x] == gracz)
    {
        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)//Sparwdzenie gora - dol
        {
            if(y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x] == gracz)
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie;
                    }

                }else if(Pole_gry[y-i][x] != ' ')
                {
                    fkoniec_rzedu += 1;
                    i = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

                }else
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }


            }else if(y+j <Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x] == gracz)
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie;
                    }
                }else if(Pole_gry[y+j][x] != ' ')
                {
                    fkoniec_rzedu += 1;
                    j = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

                }else
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else
            {
                fkoniec_rzedu += 1;
                break;
            }
        }

        //if(fkoniec_rzedu == 1) rzad -= 1;
        if((rzad+wi+wj) < IleWRzedzie || fkoniec_rzedu >= 2) rzad = 0;
        if((rzad+wi+wj) >= IleWRzedzie) rzad += 1;
        if(rzadmax < rzad) rzadmax = rzad;

        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie w lewo-prawo
        {
            if(x+i < Rozmiar && i > 0)
            {
                if(Pole_gry[y][x+i] == gracz)
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie;
                    }

                }else if(Pole_gry[y][x+i] != ' ')
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }


            }else if(x-j >= 0 && j > 0)
            {
                if(Pole_gry[y][x-j] == gracz)
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie;
                    }
                }else if(Pole_gry[y][x-j] != ' ')
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else
            {
                fkoniec_rzedu += 1;
                break;
            }
        }


        //if(fkoniec_rzedu == 1) rzad -= 1;
        if((rzad+wi+wj) < IleWRzedzie || fkoniec_rzedu >= 2) rzad = 0;
        if((rzad+wi+wj) >= IleWRzedzie) rzad += 1;
        if(rzadmax < rzad) rzadmax = rzad;

        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie po skosie /
        {
            if(x+i < Rozmiar && y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x+i] == gracz)
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie;
                    }

                }else if(Pole_gry[y-i][x+i] != ' ')
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }

            }else if(x-j >= 0 && y+j < Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x-j] == gracz)
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie;
                    }

                }else if(Pole_gry[y+j][x-j] != ' ')
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else
            {
                fkoniec_rzedu += 1;
                break;
            }

        }

        //if(fkoniec_rzedu == 1) rzad -= 1;
        if((rzad+wi+wj) < IleWRzedzie || fkoniec_rzedu >= 2) rzad = 0;
        if((rzad+wi+wj) >= IleWRzedzie) rzad += 1;
        if(rzadmax < rzad) rzadmax = rzad;

        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie po skosie \//
        {
            if(y-i >= 0 && x-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x-i] == gracz)
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie;
                    }
                }else if(Pole_gry[y-i][x-i] != ' ')
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }

            }else if(y+j < Rozmiar && x+j < Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x+j] == gracz)
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie;
                    }
                }else if(Pole_gry[y+j][x+j] != ' ')
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else
            {
                fkoniec_rzedu += 1;
                break;
            }

        }

        //if(fkoniec_rzedu == 1) rzad -= 1;
        if((rzad+wi+wj) < IleWRzedzie || fkoniec_rzedu >= 2) rzad = 0;
        if((rzad+wi+wj) >= IleWRzedzie) rzad += 1;
        if(rzadmax < rzad) rzadmax = rzad;

    }

    for(i = 0; i < Rozmiar; i++)
    {
        for(j = 0; j < Rozmiar; j++)
        {
            if(Pole_gry[i][j] == ' ')
            {
                fpuste = 1;
                break;
            }
        }

        if(fpuste)break;
    }

    if(fpuste == 0)return 0; // Remis

    if(gracz == 'O')rzadmax = -1*rzadmax;
    return rzadmax;

}

int Gra::FHeurystyczna2(char gracz, int x, int y)
{
    int rzad = 0, rzadmax = 0, i, j, wi, wj, fpuste = 0, fkoniec_rzedu = 0;
    int rzad_tab[4];

    if(Pole_gry[y][x] == gracz)
    {
        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)//Sparwdzenie gora - dol
        {
            if(y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x] == gracz)
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -8*IleWRzedzie;
                        else return 8*IleWRzedzie;
                    }


                }else if(Pole_gry[y-i][x] != ' ')
                {
                    fkoniec_rzedu += 1;
                    i = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

                }else
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }


            }else if(y+j <Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x] == gracz)
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -8*IleWRzedzie;
                        else return 8*IleWRzedzie;
                    }

                }else if(Pole_gry[y+j][x] != ' ')
                {
                    fkoniec_rzedu += 1;
                    j = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

                }else
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else
            {
                fkoniec_rzedu += 1;
                break;
            }
        }

        //if(fkoniec_rzedu == 1) rzad -= 1;
        if((rzad+wi+wj) < IleWRzedzie && fkoniec_rzedu >= 2) rzad_tab[0] = 0;
        else if((rzad+wi+wj) < IleWRzedzie) rzad_tab[0] = rzad;
        else if((rzad+wi+wj) >= IleWRzedzie && fkoniec_rzedu == 1) rzad_tab[0] = 2*rzad - 2;
        else if((rzad+wi+wj) >= IleWRzedzie) rzad_tab[0] = 2*rzad;
        rzadmax += rzad_tab[0];

        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie w lewo-prawo
        {
            if(x+i < Rozmiar && i > 0)
            {
                if(Pole_gry[y][x+i] == gracz)
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -8*IleWRzedzie;
                        else return 8*IleWRzedzie;
                    }
                }else if(Pole_gry[y][x+i] != ' ')
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }


            }else if(x-j >= 0 && j > 0)
            {
                if(Pole_gry[y][x-j] == gracz)
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -8*IleWRzedzie;
                        else return 8*IleWRzedzie;
                    }

                }else if(Pole_gry[y][x-j] != ' ')
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else
            {
                fkoniec_rzedu += 1;
                break;
            }
        }


        //if(fkoniec_rzedu == 1) rzad -= 1;
        if((rzad+wi+wj) < IleWRzedzie && fkoniec_rzedu >= 2) rzad_tab[1] = 0;
        else if((rzad+wi+wj) < IleWRzedzie) rzad_tab[1] = rzad;
        else if((rzad+wi+wj) >= IleWRzedzie && fkoniec_rzedu == 1) rzad_tab[1] = 2*rzad - 2;
        else if((rzad+wi+wj) >= IleWRzedzie) rzad_tab[1] = 2*rzad;
        rzadmax += rzad_tab[1];


        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie po skosie /
        {
            if(x+i < Rozmiar && y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x+i] == gracz)
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -8*IleWRzedzie;
                        else return 8*IleWRzedzie;
                    }

                }else if(Pole_gry[y-i][x+i] != ' ')
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }

            }else if(x-j >= 0 && y+j < Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x-j] == gracz)
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -8*IleWRzedzie;
                        else return 8*IleWRzedzie;
                    }
                }else if(Pole_gry[y+j][x-j] != ' ')
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else
            {
                fkoniec_rzedu += 1;
                break;
            }

        }

        //if(fkoniec_rzedu == 1) rzad -= 1;
        if((rzad+wi+wj) < IleWRzedzie && fkoniec_rzedu >= 2) rzad_tab[2] = 0;
        else if((rzad+wi+wj) < IleWRzedzie) rzad_tab[2] = rzad;
        else if((rzad+wi+wj) >= IleWRzedzie && fkoniec_rzedu == 1) rzad_tab[2] = 2*rzad - 2;
        else if((rzad+wi+wj) >= IleWRzedzie) rzad_tab[2] = 2*rzad;
        rzadmax += rzad_tab[2];


        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie po skosie \//
        {
            if(y-i >= 0 && x-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x-i] == gracz)
                {
                    i++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -8*IleWRzedzie;
                        else return 8*IleWRzedzie;
                    }

                }else if(Pole_gry[y-i][x-i] != ' ')
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }

            }else if(y+j < Rozmiar && x+j < Rozmiar && j > 0)
            {
                if(Pole_gry[y+j][x+j] == gracz)
                {
                    j++;
                    rzad+=1;
                    if(rzad == IleWRzedzie)
                    {
                        if(gracz == 'O')return -8*IleWRzedzie;
                        else return 8*IleWRzedzie;
                    }

                }else if(Pole_gry[y+j][x+j] != ' ')
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else
            {
                fkoniec_rzedu += 1;
                break;
            }

        }

        //if(fkoniec_rzedu == 1) rzad -= 1;
        if((rzad+wi+wj) < IleWRzedzie && fkoniec_rzedu >= 2) rzad_tab[3] = 0;
        else if((rzad+wi+wj) < IleWRzedzie) rzad_tab[3] = rzad;
        else if((rzad+wi+wj) >= IleWRzedzie && fkoniec_rzedu == 1) rzad_tab[3] = 2*rzad - 2;
        else if((rzad+wi+wj) >= IleWRzedzie) rzad_tab[3] = 2*rzad;
        rzadmax += rzad_tab[3];


    }

    for(i = 0; i < Rozmiar; i++)
    {
        for(j = 0; j < Rozmiar; j++)
        {
            if(Pole_gry[i][j] == ' ')
            {
                fpuste = 1;
                break;
            }
        }

        if(fpuste)break;
    }

    if(fpuste == 0)return 0; // Remis

    if(gracz == 'O')rzadmax = -1*rzadmax;
    return rzadmax;

}


int Gra::MinMax(char gracz, int zaglebienie, int alfa, int beta, int* f)
{
    int m, mm, pom, k = -1, w = -1;
    int zag;

    if(Rozmiar <= 11)zag = max_zag[Rozmiar];
    else if(Rozmiar <= 16) zag = 4;
    else zag = 3;

    if(gracz == 'X') mm = -9*IleWRzedzie;
    else if(gracz == 'O') mm = 9*IleWRzedzie;

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

                    if(zaglebienie >= zag)
                    {
                        m = FHeurystyczna2('X', j, i);
                        Pole_gry[i][j] = ' ';
                        return m;
                    }

                    if(pom == 1)
                    {
                        if(zaglebienie)Pole_gry[i][j] = ' ';
                        return IleWRzedzie;

                    }else if(pom == -1)
                    {
                        if(zaglebienie)Pole_gry[i][j] = ' ';
                        return 0;

                    }else m = MinMax('O', zaglebienie+1, alfa, beta, NULL);

                    Pole_gry[i][j] = ' ';

                    alfa = max(alfa, m);
                    if(zaglebienie)
                        if(alfa >= beta) return beta;

                    if(alfa > mm)
                    {
                      mm = alfa;
                      w = i;
                      k = j;
                    }

                }else if(gracz == 'O')
                {
                    Pole_gry[i][j] = 'O';
                    pom = SprawdzanieStanuGryO(j, i);

                    if(zaglebienie >= zag)
                    {
                        m = FHeurystyczna2('O', j, i);
                        Pole_gry[i][j] = ' ';
                        return m;
                    }

                    if(pom == 1)
                    {
                        if(zaglebienie)Pole_gry[i][j] = ' ';
                        else *f = pom;
                        return -1*IleWRzedzie;

                    }else if(pom == -1)
                    {
                        if(zaglebienie)Pole_gry[i][j] = ' ';
                        else *f = pom;
                        return 0;

                    }else m = MinMax('X', zaglebienie+1, alfa, beta, NULL);

                    Pole_gry[i][j] = ' ';

                    beta = min(beta, m);
                    if(zaglebienie)
                        if(alfa >= beta) return alfa;

                    if(beta < mm)
                    {
                      mm = beta;
                      w = i;
                      k = j;
                    }

                }

            }
        }
    }

    if(!zaglebienie)
    {
        if(w == -1 || k == -1)return 0;
        Pole_gry[w][k] = gracz;

    }
    return mm;
}
