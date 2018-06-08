#include "Klasa_graf.hpp"

int main()
{
    char znak;
    Graf <int, char> graf;
    graf.TworzGraf('W', 'A', 'H');
    //graf.WyswietlGraf();
    cout<<endl<<"Start"<<endl;
    //graf.DFS('W', 'A', 'H');
    //graf.AGwiazdka('W', 'A', 'H');
    cout<<graf.FHeurystyczna('W', 'A');

    cin>>znak;
    return 0;
}
