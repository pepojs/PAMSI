#include "Klasa_graf.hpp"

int main()
{
    char znak;
    Graf <int, char> graf;
    graf.TworzGraf('W', 'A', 'H');
    cout<<"Start"<<endl;
    graf.DFS('W', 'A', 'H');
    graf.AGwiazdka('W', 'A', 'H');


    cin>>znak;
    return 0;
}
