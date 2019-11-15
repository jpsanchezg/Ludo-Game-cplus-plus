#ifndef WINNER_H_INCLUDED
#define WINNER_H_INCLUDED
#include <iostream>
using namespace std;
namespace winner
{
void ganador (int i)
{
    ifstream achr;
    char respu;
    string texto;
    achr.open("ganador/felicidades.txt",ios::in);
    while(!achr.eof())
    {
        getline(achr,texto);
        cout<<texto<<endl;
    }
    achr.close();
    cout<<endl;
    cout<<endl;
    if (i == 0)
    {
        achr.open("ganador/jugador1.txt",ios::in);
        while(!achr.eof())
        {
            getline(achr,texto);
            cout<<texto<<endl;
        }
        achr.close();

    }
    if (i == 1)
    {
        achr.open("ganador/jugador2.txt",ios::in);
        while(!achr.eof())
        {
            getline(achr,texto);
            cout<<texto<<endl;
        }
        achr.close();

    }
    if (i == 2)
    {
        achr.open("ganador/jugador3.txt",ios::in);
        while(!achr.eof())
        {
            getline(achr,texto);
            cout<<texto<<endl;
        }
        achr.close();

    }
    if (i == 3)
    {
        achr.open("ganador/jugador4.txt",ios::in);
        while(!achr.eof())
        {
            getline(achr,texto);
            cout<<texto<<endl;
        }
        achr.close();
    }
    cout<<endl;
    cout<<endl;
    achr.open("ganador/winner.txt",ios::in);
    while(!achr.eof())
    {
        getline(achr,texto);
        cout<<texto<<endl;
    }
    achr.close();
    cout<<endl;
    cout<<"Quieres salir?? y/n"<<endl;
    cin>>respu;
    if (respu == 'y')
    {
        system("cls");
    }
}


}


#endif // WINNER_H_INCLUDED
