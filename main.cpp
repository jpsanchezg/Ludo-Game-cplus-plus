#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define maxiju 15
/** juan pablo sanchez gaitan**/
void datos (struct parques jugadores [maxiju],int numjug);
struct parques
{
    char nombre[30];
    int dado1,dado2;

};
using namespace std;

int main()
{
    struct parques jugadores [maxiju];
    int numjug=0,opcion=0;
    cout<<"Bienvenido al juego parques"<<endl;
    do
    {
        cout<<"MENU"<<endl;
        cout<<"1. JUGAR"<<endl;
        cout<<"2. REGLAS"<<endl;
        cout<<"3. SALIR"<<endl;
        cin>>opcion;
        if (opcion == 1)
        {
            cout<<"cuantos jugadores van a jugar?"<<endl;
            cin>>numjug;
            datos (jugadores,numjug);

        }
        if (opcion == 2)
        {
            cout<<"Las reglas son: "<<endl;
            cout<<endl;
            cout<<"Regla No1. "<<endl;
        }
        if (opcion == 3)
        {
            system("cls");
        }
    }while(opcion !=3);
}
void datos (struct parques jugadores [maxiju],int numjug)
{
    for(int i =0;i<numjug;i++)
    {
        cout<<"jugador No."<<i<<endl;
        cout<<"Nombre"<<endl;
        cin>>jugadores[i].nombre;
    }
}
