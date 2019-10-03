#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>

#define maxiju 15
#define maxix 100
#define maxiy 100
/** juan pablo sanchez gaitan**/
void datos (struct parques jugadores [maxiju],int numjug);
void juegoconlamaquina (int tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtab);
void juego (int tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtab);

void vista (int tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtab);


struct parques
{
    char nombre[30];
    int dadox=0;
    int dadoy=0;
    int pos=0;
    int movfich = 0;
    bool fichas =false;
    bool todas;
    bool ganador = false;
    int ficha1x=0,ficha1y=0;
    int ficha2x=0,ficha2y=0;
    int ficha3x=0,ficha3y=0;
    int ficha4x=0,ficha4y=0;

};
using namespace std;

int main()
{
    struct parques jugadores [maxiju];
    int numjug=0,opcion=0,tamtab=0;
    srand(time(NULL));
    int tablero [maxix][maxiy];
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
            if(numjug == 1 )
            {
                cout<<"No puedes jugar solo, consiguete a alguien"<<endl;
                cout<<"Vas a jugar contra la maquina en difultad normal"<<endl;
                tamtab = 9;
                datos (jugadores,numjug);
                // juegoconlamaquina (tablero,jugadores,numjug,tamtab);
            }
            /** si es de doble espacio para mover es de 2 el tamano minimo es de 9, si el espacio para moverse es de 1 el tamano minimo es 7**/
            if(numjug >= 2)
            {
                cout<<"Que tan grande quieres el mapa el minimo es 7"<<endl;
                cin>>tamtab;
                if (tamtab<7)
                {
                    cout<<"Pusiste un valor incorrecto te vamos a poner el valor minimo"<<endl;
                    tamtab=7;
                }
                datos (jugadores,numjug);
                vista(tablero,jugadores,numjug,tamtab);
                juego(tablero,jugadores,numjug,tamtab);

            }
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
    }
    while(opcion !=3);
}
void datos (struct parques jugadores [maxiju],int numjug)
{
    for(int i =0; i<numjug; i++)
    {
        cout<<"jugador No."<<i<<endl;
        cout<<"Nombre"<<endl;
        cin>>jugadores[i].nombre;
    }

}
void vista (int tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtab)
{
    for(int i=0; i<tamtab; i++)
    {
        for(int j=0; j<tamtab; j++)
        {

            cout<<setw(3.5)<<'|';
        }
        cout<<endl;
    }

}
void juego (int tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtab)
{
    int turno=0,i=0,respu=0,contador=0,lanzamientos=3,fichmov=0;
    int dadox=0,dadoy=0,suma=0;
    bool salio =false;
    bool finalista = false;
    do
    {
        if(i==2)
        {
            i=0;
            turno++;
        }
        cout<<"Turno #"<<turno<<endl;
        cout<<"Juega "<<jugadores[i].nombre<<endl;
        cout<<"Tirar dados? 1.si"<<endl;
        cin>>respu;
        if (respu == 1)
        {
            do
            {
                cout<<"Lanzamiento #"<<contador+1<<endl;
                dadox = rand() % 6 + 1;
                dadoy = rand() % 6 + 1;
                cout<<dadox<<","<<dadoy<<endl;
                if (jugadores[i].fichas == false)
                {
                    if(dadox==1)
                    {
                        if(dadoy==1)
                        {
                            cout<<"SALEN TODAS LAS FICHAS"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].todas=true;
                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 1)
                        {
                            contador++;
                        }
                    }
                    if(dadox==2)
                    {
                        if(dadoy==2)
                        {
                            cout<<"SALEN 2 FICHAS"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 2)
                        {
                            contador++;
                        }
                    }
                    if(dadox==3)
                    {
                        if(dadoy==3)
                        {
                            cout<<"SALEN 2 FICHAS"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 3)
                        {
                            contador++;
                        }
                    }
                    if(dadox==4)
                    {
                        if(dadoy==4)
                        {
                            cout<<"SALEN 2 FICHAS"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 4)
                        {
                            contador++;
                        }
                    }
                    if(dadox==5)
                    {
                        if(dadoy==5)
                        {
                            cout<<"SALEN 2 FICHAS"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 5)
                        {
                            contador++;
                        }
                    }
                    if(dadox==6)
                    {
                        if(dadoy==6)
                        {
                            cout<<"SALEN TODAS LAS FICHAS"<<endl;
                            salio=true;
                            lanzamientos =1;
                            jugadores[i].todas=true;
                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 6)
                        {
                            contador++;
                        }
                    }
                    if (contador == lanzamientos)
                    {
                        salio = true;
                    }
                }
                if (jugadores[i].fichas==true)
                {
                    if (turno>0)
                    {
                        salio=true;
                    }
                }
            }
            while (salio == false);
        }
        if (turno >0)
        {
            if (jugadores[i].fichas == true)
            {
                cout<<"que fichas quieres mover?: "<<endl;
                cout<<"1. ficha 1"<<endl;
                cout<<"2. ficha 2"<<endl;
                if (jugadores[i].todas == true)
                {
                    cout<<"3. ficha 3"<<endl;
                    cout<<"4. ficha 4"<<endl;
                }
                cin>>fichmov;
                if(fichmov == 1)
                {
                    cout<<"cuantas casillas quieres mover la ficha?"<<endl;
                    suma = dadox+dadoy;
                    cout<<dadox<<" posiciones"<<endl;
                    cout<<dadoy<<" posiciones"<<endl;
                    cout<<suma<<" posiciones"<<endl;
                    cin>>jugadores[i].movfich;
                }
            }
        }
        salio = false;
        contador = 0;
        i++;
         if (jugadores[i].fichas == false)
        {
            lanzamientos = 3;
            contador =0;
        }
    }
    while(finalista == false);
}
