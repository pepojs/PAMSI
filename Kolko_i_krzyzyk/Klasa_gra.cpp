#include "Klasa_gra.hpp"

using namespace std;

//Konstruktor domyślny
Gra::Gra()
{
    Rozmiar = 3; //Rozmiar planszy 3x3
    IleWRzedzie = 3; //3 znaki w rzedzie aby wygrac

    //Dynamiczna alokacja tablicy 2 wymiarowej 3x3
    Pole_gry = new char*[3];

    for(int i = 0; i < 3; i++)
    {
        Pole_gry[i] = new char[3];
        for(int j = 0; j < 3; j++)
        {
            Pole_gry[i][j] = ' ';//Wypelnienie tablicy "pustymi" polami
        }
    }

}

//Konstruktor pobierajacy rozmiar planszy
Gra::Gra(int rozmiar)
{
    Rozmiar = rozmiar;//Rozmiar planszy rowny rozmiarowi podanemu do konstruktora
    IleWRzedzie = 3; //Domyslnie potrzeba 3 znaki w rzedzie aby wygrac

    //Dynamiczna alokacja tablicy 2 wymiarowej rozmiar x rozmiar
    Pole_gry = new char*[rozmiar];

    for(int i = 0; i < rozmiar; i++)
    {
        Pole_gry[i] = new char[rozmiar];
        for(int j = 0; j < rozmiar; j++)
        {
            Pole_gry[i][j] = ' '; //Wypelnienie tablicy "pustymi" polami
        }
    }
}

//Destruktor
Gra::~Gra()
{
    //Zwolnienie zaalokowanej pamieci
    for(int i = 0; i < Rozmiar; i++)
    {
        delete[] Pole_gry[i];
    }

    delete[] Pole_gry;
    Pole_gry = NULL;
}

//Metoda pozwalajaca zmienic rozmiar planszy
void Gra::ZmienRozmiar(int rozmiar)
{
    //Zwalnianie pamieci starej planszy gry
    for(int i = 0; i < Rozmiar; i++)
    {
        delete[] Pole_gry[i];
    }

    delete[] Pole_gry;
    Pole_gry = NULL;

    Rozmiar = rozmiar; //Zmiana rozmiaru planszy

    //Alokacja planszy o nowym rozmiarze
    Pole_gry = new char*[rozmiar];

    for(int i = 0; i < rozmiar; i++)
    {
        Pole_gry[i] = new char[rozmiar];
        for(int j = 0; j < rozmiar; j++)
        {
            Pole_gry[i][j] = ' '; //Wypelnienie tablicy "pustymi" polami
        }
    }
}

//Metoda pozwalajaca zmienic ilosc znakow w rzedzie potrzebnych do wygrania
void Gra::ZmienRzad(int rzad)
{
    IleWRzedzie = rzad;
}

//Metoda wyswietlajaca plansze w konsoli
void Gra::RysujePoleGry()
{
    string Pole = "";
    stringstream ss; //Strumien do napisu

    system("cls"); //Czyszczenie konsoli poprzez wywolanie Windows-owej funkcji cls

    //Tworzenie stringu odpowiadajacego planszy
    //Numerownie kolumn
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

    //Tworzenie wierszy z odpowiednio wypelnionymi polami
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

//Metoda pozwalajaca wypelnic puste pole znakiem X
int Gra::WypelniPoleX(int x, int y)
{
    //Sprawdzenie czy pole o podanych wspolrzednych jest "puste"
    if((x < Rozmiar && y < Rozmiar) && (Pole_gry[y][x] == ' '))
    {
        Pole_gry[y][x] = 'X';
        return 1; //Zwraca 1 gdy udalo sie wypelnic pole

    }else return 0; //Zwraca 0 gdy pole jest zajete


}

//Metoda pozwalajaca wypelnic puste pole znakiem O
int Gra::WypelniPoleO(int x, int y)
{
    //Sprawdzenie czy pole o podanych wspolrzednych jest "puste"
    if((x < Rozmiar && y < Rozmiar) && (Pole_gry[y][x] == ' '))
    {
        Pole_gry[y][x] = 'O';
        return 1; //Zwraca 1 gdy udalo sie wypelnic pole

    }else return 0; //Zwraca 0 gdy pole jest zajete

}

//Metoda sprawdzajaca czy gracz X wygral/zremisowal;
//podajemy wspolrzedne pola ze znakiem X, ktore chcemy sprawdzic

int Gra::SprawdzanieStanuGryX(int x, int y)
{
    int rzad = 0, i, j, fpuste = 0;

    //Jezeli pola nie ma na planszy zwraca 0
    if((x >= Rozmiar || y >= Rozmiar) || (x < 0 || y < 0))return 0;

    if(Pole_gry[y][x] == 'X')
    {
        rzad = 1; // Zmienna przechowujaca ile jest takich samych znakow w rzedzie
        i = 1;
        j = 1;

        while(1)//Sparwdzenie gora - dol
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x] == 'X') //Sprawdzenie czy na polach powyzej jest znak X
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

            }else if(y+j <Rozmiar && j > 0) //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x] == 'X') //Sprawdzenie czy na polach ponizej jest znak X
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

            }else break;
        }

        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie w lewo-prawo
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(x+i < Rozmiar && i > 0)
            {
                if(Pole_gry[y][x+i] == 'X')//Sprawdzenie czy na polach po prawej jest znak X
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(x-j >= 0 && j > 0) //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y][x-j] == 'X') //Sprawdzenie czy na polach po lewej jest znak X
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;
        }

        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie po skosie /
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(x+i < Rozmiar && y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x+i] == 'X') //Sprawdzenie czy na polach powyzej i po prawej jest znak X
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(x-j >= 0 && y+j < Rozmiar && j > 0) //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x-j] == 'X') //Sprawdzenie czy na polach ponizej i po lewej jest znak X
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;

        }


        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie po skosie \ //
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(y-i >= 0 && x-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x-i] == 'X') //Sprawdzenie czy na polach powyzej i po lewej jest znak X
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(y+j < Rozmiar && x+j < Rozmiar && j > 0) //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x+j] == 'X') //Sprawdzenie czy na polach ponizej i po prawej jest znak X
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;

        }
    }


    //Sprawdzenie czy jest jeszcze jakies wolne pole
    for(i = 0; i < Rozmiar; i++)
    {
        for(j = 0; j < Rozmiar; j++)
            if(Pole_gry[i][j] == ' ')
            {
                fpuste = 1;
                break;
            }
    }

    //Jezeli nie ma wolnego pola to remis
    if(fpuste == 0)return -1; //Zwraca -1 gdy remis

    return 0; //Zwraca 0 jezeli gracz X nie wygral, ani nie zremisowal
}

//Metoda sprawdzajaca czy gracz O wygral/zremisowal;
//podajemy wspolrzedne pola ze znakiem O, ktore chcemy sprawdzic
int Gra::SprawdzanieStanuGryO(int x, int y)
{
    int rzad = 0, i, j, fpuste = 0;

    //Jezeli pola nie ma na planszy zwraca 0
    if((x >= Rozmiar || y >= Rozmiar) || (x < 0 || y < 0))return 0;

    if(Pole_gry[y][x] == 'O')
    {
        rzad = 1;// Zmienna przechowujaca ile jest takich samych znakow w rzedzie
        i = 1;
        j = 1;


        while(1)//Sparwdzenie gora - dol
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x] == 'O')//Sprawdzenie czy na polach powyzej jest znak O
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

            }else if(y+j <Rozmiar && j > 0)//Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x] == 'O') //Sprawdzenie czy na polach ponizej jest znak O
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

            }else break;
        }

        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie w lewo-prawo
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(x+i < Rozmiar && i > 0)
            {
                if(Pole_gry[y][x+i] == 'O') //Sprawdzenie czy na polach po prawej jest znak O
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(x-j >= 0 && j > 0)//Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y][x-j] == 'O') //Sprawdzenie czy na polach po lewej jest znak O
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;
        }

        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie po skosie /
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(x+i < Rozmiar && y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x+i] == 'O') //Sprawdzenie czy na polach powyzej i po prawej jest znak O
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(x-j >= 0 && y+j < Rozmiar && j > 0)//Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x-j] == 'O') //Sprawdzenie czy na polach ponizej i po lewej jest znak O
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;

        }


        rzad = 1;
        i = 1;
        j = 1;

        while(1)// Sprawdzenie po skosie \ //
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(y-i >= 0 && x-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x-i] == 'O') //Sprawdzenie czy na polach powyzej i po lewej jest znak O
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else i = -1;

            }else if(y+j < Rozmiar && x+j < Rozmiar && j > 0)//Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x+j] == 'O') //Sprawdzenie czy na polach ponizej i po prawej jest znak O
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow zwraca 1
                    if(rzad == IleWRzedzie)return 1;

                }else j = -1;

            }else break;

        }
    }


    //Sprawdzenie czy jest jeszcze jakies wolne pole
    for(i = 0; i < Rozmiar; i++)
    {
        for(j = 0; j < Rozmiar; j++)
            if(Pole_gry[i][j] == ' ')
            {
                fpuste = 1;
                break;
            }
    }

    //Jezeli nie ma wolnego pola to remis
    if(fpuste == 0)return -1; //Zwraca -1 gdy remis

    return 0;//Zwraca 0 jezeli gracz X nie wygral, ani nie zremisowal
}

//Funkcja heurystyczna;
//Podobna zasada dzialania jak metoda sprawdzajaca stan gry
int Gra::FHeurystyczna(char gracz, int x, int y)
{
    int rzad = 0, rzadmax = 0, i, j, wi, wj, fpuste = 0, fkoniec_rzedu = 0;

    if(Pole_gry[y][x] == gracz)
    {
        rzad = 1;
        i = 1;
        j = 1;
        wi = 0; //Ilosc wolnych pol na koncu rzedu
        wj = 0; //Ilosc wolnych pol na koncu rzedu
        fkoniec_rzedu = 0; //Zmienna okreslajaca czy sa wolne pola po obu stronach sprawdznego rzedu

        while(1)//Sparwdzenie gora - dol
        {

            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x] == gracz) //Sprawdzenie czy na polach powyzej jest znak gracza
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow
                    if(rzad == IleWRzedzie)
                    {
                        //Dla gracza O (przeciwnika) zwraca liczbe ujemna oznaczajaca jego wygrana
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie; //Dla gracza X liczbe dodatnia
                    }

                }else if(Pole_gry[y-i][x] != ' ') //Jezeli nie ma wolnego pola na koncu rzedu
                {
                    fkoniec_rzedu += 1;
                    i = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

                }else //Jezeli jest wolne pole na koncu rzedu
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }

            }else if(y+j <Rozmiar && j > 0) //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x] == gracz) //Sprawdzenie czy na polach ponizej jest znak gracza
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow
                    if(rzad == IleWRzedzie)
                    {
                        //Dla gracza O (przeciwnika) zwraca liczbe ujemna oznaczajaca jego wygrana
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie; //Dla gracza X liczbe dodatnia
                    }
                }else if(Pole_gry[y+j][x] != ' ') //Jezeli nie ma wolnego pola na koncu rzedu
                {
                    fkoniec_rzedu += 1;
                    j = -1;//Nie ma ciaglosci, wiec nie sprawdza wiecej tego warunku

                }else //Jezeli jest wolne pole na koncu rzedu
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else if(y-i < 0 && i > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                i = -1;

            }else if(y+j >= Rozmiar && j > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                j = -1;

            }else break;
        }

        //if(fkoniec_rzedu == 1) rzad -= 1;

        //Jezeli nie ma mozliwosci dalszego stawiania znaku w rzedzie ustawia rzad na 0
        if((rzad+wi+wj) < IleWRzedzie || fkoniec_rzedu >= 2) rzad = 0;

        //Jezeli jest wystarczajaco duzo wolnych pol na koncu rzedu aby wygrac
        if((rzad+wi+wj) >= IleWRzedzie) rzad += 1;

        //Koncowo zwraca najlepszy wynik jaki mozna uzyskac
        if(rzadmax < rzad) rzadmax = rzad;

        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie w lewo-prawo
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(x+i < Rozmiar && i > 0)
            {
                if(Pole_gry[y][x+i] == gracz) //Sprawdzenie czy na polach po prawej jest znak gracza
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow
                    if(rzad == IleWRzedzie)
                    {
                        //Dla gracza O (przeciwnika) zwraca liczbe ujemna oznaczajaca jego wygrana
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie; //Dla gracza X liczbe dodatnia
                    }

                }else if(Pole_gry[y][x+i] != ' ') //Jezeli nie ma wolnego pola na koncu rzedu
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else //Jezeli jest wolne pole na koncu rzedu
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }


            }else if(x-j >= 0 && j > 0) //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y][x-j] == gracz) //Sprawdzenie czy na polach po lewej jest znak gracza
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow
                    if(rzad == IleWRzedzie)
                    {
                        //Dla gracza O (przeciwnika) zwraca liczbe ujemna oznaczajaca jego wygrana
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie; //Dla gracza X liczbe dodatnia
                    }
                }else if(Pole_gry[y][x-j] != ' ') //Jezeli nie ma wolnego pola na koncu rzedu
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else //Jezeli jest wolne pole na koncu rzedu
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else if(x+i >= Rozmiar && i > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                i = -1;

            }else if(x-j < 0 && j > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                j = -1;

            }else break;
        }


        //if(fkoniec_rzedu == 1) rzad -= 1;

        //Jezeli nie ma mozliwosci dalszego stawiania znaku w rzedzie ustawia rzad na 0
        if((rzad+wi+wj) < IleWRzedzie || fkoniec_rzedu >= 2) rzad = 0;

        //Jezeli jest wystarczajaco duzo wolnych pol na koncu rzedu aby wygrac
        if((rzad+wi+wj) >= IleWRzedzie) rzad += 1;

        //Koncowo zwraca najlepszy wynik jaki mozna uzyskac
        if(rzadmax < rzad) rzadmax = rzad;

        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie po skosie /
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(x+i < Rozmiar && y-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x+i] == gracz) //Sprawdzenie czy na polach powyzej i po prawej jest znak gracza
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow
                    if(rzad == IleWRzedzie)
                    {
                        //Dla gracza O (przeciwnika) zwraca liczbe ujemna oznaczajaca jego wygrana
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie; //Dla gracza X liczbe dodatnia
                    }

                }else if(Pole_gry[y-i][x+i] != ' ') //Jezeli nie ma wolnego pola na koncu rzedu
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else //Jezeli jest wolne pole na koncu rzedu
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }

            }else if(x-j >= 0 && y+j < Rozmiar && j > 0) //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x-j] == gracz) //Sprawdzenie czy na polach ponizej i po lewej jest znak gracza
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow
                    if(rzad == IleWRzedzie)
                    {
                        //Dla gracza O (przeciwnika) zwraca liczbe ujemna oznaczajaca jego wygrana
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie; //Dla gracza X liczbe dodatnia
                    }

                }else if(Pole_gry[y+j][x-j] != ' ') //Jezeli nie ma wolnego pola na koncu rzedu
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else //Jezeli jest wolne pole na koncu rzedu
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else if(x+i >= Rozmiar && y-i < 0 && i > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                i = -1;

            }else if(x-j < 0 && y+j >= Rozmiar && j > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                j = -1;

            }else break;

        }

        //if(fkoniec_rzedu == 1) rzad -= 1;

        //Jezeli nie ma mozliwosci dalszego stawiania znaku w rzedzie ustawia rzad na 0
        if((rzad+wi+wj) < IleWRzedzie || fkoniec_rzedu >= 2) rzad = 0;

        //Jezeli jest wystarczajaco duzo wolnych pol na koncu rzedu aby wygrac
        if((rzad+wi+wj) >= IleWRzedzie) rzad += 1;

        //Koncowo zwraca najlepszy wynik jaki mozna uzyskac
        if(rzadmax < rzad) rzadmax = rzad;

        rzad = 1;
        i = 1;
        j = 1;
        wi = 0;
        wj = 0;
        fkoniec_rzedu = 0;

        while(1)// Sprawdzenie po skosie \ //
        {
            //Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            if(y-i >= 0 && x-i >= 0 && i > 0)
            {
                if(Pole_gry[y-i][x-i] == gracz) //Sprawdzenie czy na polach powyzej i po lewej jest znak gracza
                {
                    i++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow
                    if(rzad == IleWRzedzie)
                    {
                        //Dla gracza O (przeciwnika) zwraca liczbe ujemna oznaczajaca jego wygrana
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie; //Dla gracza X liczbe dodatnia
                    }
                }else if(Pole_gry[y-i][x-i] != ' ') //Jezeli nie ma wolnego pola na koncu rzedu
                {
                    fkoniec_rzedu += 1;
                    i = -1;

                }else //Jezeli jest wolne pole na koncu rzedu
                {
                    i++;
                    wi += 1;
                    if(i >= IleWRzedzie)i = -1;
                }

            }else if(y+j < Rozmiar && x+j < Rozmiar && j > 0)//Sprawdzenie czy nie przekroczono rozmiaru tablicy i czy zachowano ciaglosc znakow
            {
                if(Pole_gry[y+j][x+j] == gracz) //Sprawdzenie czy na polach ponizej i po prawej jest znak gracza
                {
                    j++;
                    rzad+=1;

                    //Jezeli w rzedzie jest wystarczajaco duzo takich samych znakow
                    if(rzad == IleWRzedzie)
                    {
                        //Dla gracza O (przeciwnika) zwraca liczbe ujemna oznaczajaca jego wygrana
                        if(gracz == 'O')return -1*IleWRzedzie;
                        else return IleWRzedzie; //Dla gracza X liczbe dodatnia
                    }
                }else if(Pole_gry[y+j][x+j] != ' ') //Jezeli nie ma wolnego pola na koncu rzedu
                {
                    fkoniec_rzedu += 1;
                    j = -1;

                }else //Jezeli jest wolne pole na koncu rzedu
                {
                    j++;
                    wj += 1;
                    if(j >= IleWRzedzie)j = -1;
                }

            }else if(y-i < 0 && x-i < 0 && i > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                i = -1;

            }else if(y+j >= Rozmiar && x+j >= Rozmiar && j > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                j = -1;

            }else break;

        }

        //if(fkoniec_rzedu == 1) rzad -= 1;

        //Jezeli nie ma mozliwosci dalszego stawiania znaku w rzedzie ustawia rzad na 0
        if((rzad+wi+wj) < IleWRzedzie || fkoniec_rzedu >= 2) rzad = 0;

        //Jezeli jest wystarczajaco duzo wolnych pol na koncu rzedu aby wygrac
        if((rzad+wi+wj) >= IleWRzedzie) rzad += 1;

        //Koncowo zwraca najlepszy wynik jaki mozna uzyskac
        if(rzadmax < rzad) rzadmax = rzad;

    }

    //Sprawdza czy jest jeszcze wolne pole na planszy
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

    //Jezeli nie ma pustego pola to remis
    if(fpuste == 0)return 0;

    //Ustawia ujemna wartosc dla gracza O (przeciwnika)
    if(gracz == 'O')rzadmax = -1*rzadmax;
    return rzadmax; //Dodatnia wartosc dla gracza X

}

//Druga funkcja heurystyczna (innaczej szacuje koncowy wynik)
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

            }else if(y-i < 0 && i > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                i = -1;

            }else if(y+j >= Rozmiar && j > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                j = -1;

            }else break;
        }

        //if(fkoniec_rzedu == 1) rzad -= 1;

        //Jezeli na koncach rzedu nie mozna dopisac znaku
        if((rzad+wi+wj) < IleWRzedzie && fkoniec_rzedu >= 2) rzad_tab[0] = 0;

        //Jezeli ilosc wolnych miejsc po bokach jest zbyt mala aby wygrac
        else if((rzad+wi+wj) < IleWRzedzie) rzad_tab[0] = rzad;

        //Jezeli ilosc wolnych miejsc po bokach jest wystarczajaca aby wygrac, ale z jednej strony nie mozna postawic znaku
        else if((rzad+wi+wj) >= IleWRzedzie && fkoniec_rzedu == 1) rzad_tab[0] = 2*rzad - 2;

        //Jezeli ilosc wolnych miejsc po bokach jest wystarczajaca aby wygrac
        else if((rzad+wi+wj) >= IleWRzedzie) rzad_tab[0] = 2*rzad;

        //Dodaje do koncowego wyniku wynik osiagniety z sprawdzania jednego kierunku
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

            }else if(x+i >= Rozmiar && i > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                i = -1;

            }else if(x-j < 0 && j > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                j = -1;

            }else break;
        }


        //if(fkoniec_rzedu == 1) rzad -= 1;

        //Jezeli na koncach rzedu nie mozna dopisac znaku
        if((rzad+wi+wj) < IleWRzedzie && fkoniec_rzedu >= 2) rzad_tab[1] = 0;

        //Jezeli ilosc wolnych miejsc po bokach jest zbyt mala aby wygrac
        else if((rzad+wi+wj) < IleWRzedzie) rzad_tab[1] = rzad;

        //Jezeli ilosc wolnych miejsc po bokach jest wystarczajaca aby wygrac, ale z jednej strony nie mozna postawic znaku
        else if((rzad+wi+wj) >= IleWRzedzie && fkoniec_rzedu == 1) rzad_tab[1] = 2*rzad - 2;

        //Jezeli ilosc wolnych miejsc po bokach jest wystarczajaca aby wygrac
        else if((rzad+wi+wj) >= IleWRzedzie) rzad_tab[1] = 2*rzad;

        //Dodaje do koncowego wyniku wynik osiagniety z sprawdzania jednego kierunku
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

            }else if(x+i >= Rozmiar && y-i < 0 && i > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                i = -1;

            }else if(x-j < 0 && y+j >= Rozmiar && j > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                j = -1;

            }else break;

        }

        //if(fkoniec_rzedu == 1) rzad -= 1;

        //Jezeli na koncach rzedu nie mozna dopisac znaku
        if((rzad+wi+wj) < IleWRzedzie && fkoniec_rzedu >= 2) rzad_tab[2] = 0;

        //Jezeli ilosc wolnych miejsc po bokach jest zbyt mala aby wygrac
        else if((rzad+wi+wj) < IleWRzedzie) rzad_tab[2] = rzad;

        //Jezeli ilosc wolnych miejsc po bokach jest wystarczajaca aby wygrac, ale z jednej strony nie mozna postawic znaku
        else if((rzad+wi+wj) >= IleWRzedzie && fkoniec_rzedu == 1) rzad_tab[2] = 2*rzad - 2;

        //Jezeli ilosc wolnych miejsc po bokach jest wystarczajaca aby wygrac
        else if((rzad+wi+wj) >= IleWRzedzie) rzad_tab[2] = 2*rzad;

        //Dodaje do koncowego wyniku wynik osiagniety z sprawdzania jednego kierunku
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

            }else if(y-i < 0 && x-i < 0 && i > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                i = -1;

            }else if(y+j >= Rozmiar && x+j >= Rozmiar && j > 0)//Jezeli w danym kierunku sprawdzania nie ma juz pol planszy
            {
                fkoniec_rzedu += 1;
                j = -1;

            }else break;

        }

        //if(fkoniec_rzedu == 1) rzad -= 1;

        //Jezeli na koncach rzedu nie mozna dopisac znaku
        if((rzad+wi+wj) < IleWRzedzie && fkoniec_rzedu >= 2) rzad_tab[3] = 0;

        //Jezeli ilosc wolnych miejsc po bokach jest zbyt mala aby wygrac
        else if((rzad+wi+wj) < IleWRzedzie) rzad_tab[3] = rzad;

        //Jezeli ilosc wolnych miejsc po bokach jest wystarczajaca aby wygrac, ale z jednej strony nie mozna postawic znaku
        else if((rzad+wi+wj) >= IleWRzedzie && fkoniec_rzedu == 1) rzad_tab[3] = 2*rzad - 2;

        //Jezeli ilosc wolnych miejsc po bokach jest wystarczajaca aby wygrac
        else if((rzad+wi+wj) >= IleWRzedzie) rzad_tab[3] = 2*rzad;

        //Dodaje do koncowego wyniku wynik osiagniety z sprawdzania jednego kierunku
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

//Metoda MinMax
int Gra::MinMax(char gracz, int zaglebienie, int alfa, int beta, int* f, int funkcja)
{
    int m, mm, pom, k = -1, w = -1;
    int zag;

    //Jezeli rozmiar nie przekracza 11x11 to maksymalna ilosc zaglebienia rekurencji odczytywana jest z tabliczy
    if(Rozmiar <= 11)zag = max_zag[Rozmiar];
    else if(Rozmiar <= 16) zag = 4; //Jezeli rozmiar planszy wynosi od 12 do 16
    else zag = 3;

    //Ustawia poczatkowosc wartosc w zaleznosci od gracza
    if(gracz == 'X') mm = -9*IleWRzedzie;
    else if(gracz == 'O') mm = 9*IleWRzedzie;

    //Petla, w ktorej szuka sie wolne pole na planszy
    for(int i = 0; i < Rozmiar; i++)
    {
        for(int j = 0; j < Rozmiar; j++)
        {
            if(Pole_gry[i][j] == ' ')
            {

                //Jezeli aktualnym graczem jest X
                if(gracz == 'X')
                {
                    Pole_gry[i][j] = 'X'; //Ustawia znak X na znalezionym wolnym polu
                    pom = SprawdzanieStanuGryX(j, i);//Po ustawieniu znaku sprawdza sie czy nie nastapilo zwyciestwo/remis

                    //Sprawdza czy zaglebienie rekurencji nie przekracza maksymalne wartosci
                    if(zaglebienie >= zag)
                    {
                        //Jezeli przekracza, wartosc jest obliczana przy pomocy funkcji heurystycznej
                        //Mozna wybrac, ktora funkcje uzyc
                        if(funkcja == 0)m = FHeurystyczna('X', j, i);
                        else m = FHeurystyczna2('X', j, i);

                        Pole_gry[i][j] = ' '; //Przywraca poprzedni stan planszy gry
                        return m;
                    }

                    //Jezeli nastapilo zwyciestwo
                    if(pom == 1)
                    {
                        //Jezeli zaglebienie jest rozne od 0 to przywraca poprzedni stan planszy gry
                        if(zaglebienie)Pole_gry[i][j] = ' ';
                        return IleWRzedzie;

                    }else if(pom == -1) //Jezeli nastapil remis
                    {
                        //Jezeli zaglebienie jest rozne od 0 to przywraca poprzedni stan planszy gry
                        if(zaglebienie)Pole_gry[i][j] = ' ';
                        return 0;

                    }else m = MinMax('O', zaglebienie+1, alfa, beta, NULL, 0); //Rekurencyjne wywolanie funkcji MinMax, zmienia gracza

                    //Przywraca plansze do poczatkowego stanu
                    Pole_gry[i][j] = ' ';

                    //Obciecie alfa-beta
                    alfa = max(alfa, m);
                    if(zaglebienie)
                        if(alfa >= beta) return beta;

                    if(alfa > mm)
                    {
                      mm = alfa;
                      //Miejsce, w ktorym najlepiej postawic znak
                      w = i;
                      k = j;
                    }

                }else if(gracz == 'O') //Jezeli aktualnym graczem jest O
                {
                    Pole_gry[i][j] = 'O'; //Ustawia znak O na znalezionym wolnym pol
                    pom = SprawdzanieStanuGryO(j, i);//Po ustawieniu znaku sprawdza sie czy nie nastapilo zwyciestwo/remis

                    //Sprawdza czy zaglebienie rekurencji nie przekracza maksymalne wartosci
                    if(zaglebienie >= zag)
                    {
                        //Jezeli przekracza, wartosc jest obliczana przy pomocy funkcji heurystycznej
                        //Mozna wybrac, ktora funkcje uzyc
                        if(funkcja == 0)m = FHeurystyczna('X', j, i);
                        else m = FHeurystyczna2('X', j, i);

                        Pole_gry[i][j] = ' '; //Przywraca poprzedni stan planszy gry
                        return m;
                    }

                    //Jezeli nastapilo zwyciestwo
                    if(pom == 1)
                    {
                        //Jezeli zaglebienie jest rozne od 0 to przywraca poprzedni stan planszy gry
                        if(zaglebienie)Pole_gry[i][j] = ' ';
                        else *f = pom; //Zmienna sygnalizujaca ze gracz O wygral
                        return -1*IleWRzedzie;

                    }else if(pom == -1) //Jezeli nastapil remis
                    {
                        //Jezeli zaglebienie jest rozne od 0 to przywraca poprzedni stan planszy gry
                        if(zaglebienie)Pole_gry[i][j] = ' ';
                        else *f = pom; //Zmienna sygnalizujaca ze gracz O zremisowal
                        return 0;

                    }else m = MinMax('X', zaglebienie+1, alfa, beta, NULL, 0); //Rekurencyjne wywolanie funkcji MinMax, zmienia gracza

                    //Przywraca plansze do poczatkowego stanu
                    Pole_gry[i][j] = ' ';

                    //Obciecie alfa-beta
                    beta = min(beta, m);
                    if(zaglebienie)
                        if(alfa >= beta) return alfa;

                    if(beta < mm)
                    {
                      mm = beta;
                      //Miejsce, w ktorym najlepiej postawic znak
                      w = i;
                      k = j;
                    }

                }

            }
        }
    }

    //Jezeli zaglebienie jest rowne 0
    if(!zaglebienie)
    {
        //Jezeli nie wybrano gdzie ustawic znak zwraca 0
        if(w == -1 || k == -1)return 0;
        Pole_gry[w][k] = gracz; //Ustawia znak w wybranym miejscu

    }
    return mm;
}
