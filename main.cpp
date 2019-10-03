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

void juegoconlamaquina (int tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);

void juego (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);

void vista (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);


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
    int salidax=0,saliday=0;
    int ficha1x=0,ficha1y=0;
    int ficha2x=0,ficha2y=0;
};
using namespace std;

int main()
{
    struct parques jugadores [maxiju];
    int numjug=0,opcion=0,tamtabx=0,tamtaby=0;
    srand(time(NULL));
    char tablero [maxix][maxiy];
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
                tamtabx = 6;
                tamtaby = 4;
                datos (jugadores,numjug);
                vista(tablero,jugadores,numjug,tamtabx,tamtaby);
                juego(tablero,jugadores,numjug,tamtabx,tamtaby);
                // juegoconlamaquina (tablero,jugadores,numjug,tamtab);
            }
            /** si es de doble espacio para mover es de 2 el tamano minimo es de 9, si el espacio para moverse es de 1 el tamano minimo es 7**/
            if(numjug >= 2)
            {
                tamtabx = 6;
                tamtaby = 4;
                datos (jugadores,numjug);
                vista(tablero,jugadores,numjug,tamtabx,tamtaby);
                juego(tablero,jugadores,numjug,tamtabx,tamtaby);

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
void vista (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
{
    tablero[0][0]='@';
    tablero[0][1]='@';
    tablero[2][0]='#';
    tablero[3][0]='#';
    tablero[5][0]='$';
    tablero[5][1]='$';
    tablero[5][2]='&';
    tablero[5][3]='&';


    for(int i = 0; i < tamtabx; i++)
    {
        for(int j = 0; j < tamtaby; j++)
        {
            cout<<setw(3.5)<<tablero[i][j]<<'|';
        }
        cout<<endl;
    }

}
void juego (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
{
    int turno=0,i=0,respu=0,contador=0,lanzamientos=3,fichmov=0;
    int dadox=0,dadoy=0,suma=0;
    bool salio =false;
    bool finalista = false;
    jugadores[0].salidax=0;
    jugadores[0].saliday=1;
    jugadores[1].salidax=3;
    jugadores[1].saliday=1;
    jugadores[2].salidax=3;
    jugadores[2].saliday=4;
    jugadores[3].salidax=6;
    jugadores[3].saliday=4;
    do
    {
        if(i == numjug)
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
                jugadores[i].ficha1x=jugadores[i].salidax;
                jugadores[i].ficha1y=jugadores[i].saliday;
                if (jugadores[i].todas == true)
                {
                    cout<<"2. ficha 2"<<endl;
                    jugadores[i].ficha2x=jugadores[i].salidax;
                    jugadores[i].ficha2y=jugadores[i].saliday;
                }
                cin>>fichmov;
                if(fichmov == 1)
                {
                    cout<<"cuantas casillas quieres mover la ficha?"<<endl;
                    suma = dadox+dadoy;
                    cout<<"Op 1 "<<dadox<<" posiciones"<<endl;
                    cout<<"Op 2 "<<dadoy<<" posiciones"<<endl;
                    cout<<"Op 3 "<<suma<<" posiciones"<<endl;
                    cin>>jugadores[i].movfich;
                    if (jugadores[i].movfich == 1)
                    {
                        if (i == 0)
                        {
                            if (dadox == 1)
                            {
                                jugadores[i].ficha1y = jugadores[i].ficha1y + 1;
                                if (jugadores[i].ficha1y >= tamtaby)
                                {
                                    jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                    jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='J';
                                    vista(tablero,jugadores,numjug,tamtab);
                                }
                                if (jugadores[i].ficha1x < 5)
                                {
                                    jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='J';
                                    vista(tablero,jugadores,numjug,tamtab);
                                }
                                if (jugadores[i].ficha1y < -1)
                                {
                                    jugadores[i].ficha1y = jugadores[i].ficha1y + 1;
                                    jugadores[i].ficha1x = jugadores[i].ficha1x - 1;
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='J';
                                    vista(tablero,jugadores,numjug,tamtab);
                                }
                            }
                            if (dadox == 2)
                            {
                                jugadores[i].ficha1y = jugadores[i].ficha1y + 2;
                                if (jugadores[i].ficha1y >= tamtaby)
                                {
                                    jugadores[i].ficha1y = jugadores[i].ficha1y - 2;
                                    jugadores[i].ficha1y = jugadores[i].ficha1y + 1;
                                    jugadores[i].ficha1y = jugadores[i].ficha1y + 1;
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='J';
                                    vista(tablero,jugadores,numjug,tamtab);
                                }
                                if (jugadores[i].ficha1y < tamtaby)
                                {
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='J';
                                    vista(tablero,jugadores,numjug,tamtab);
                                }
                            }
                            if (dadox == 3)
                            {
                                jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                jugadores[i].ficha1y = jugadores[i].ficha1y -2;
                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='A1';
                                vista(tablero,jugadores,numjug,tamtab);
                            }
                            if (dadox == 4)
                            {
                                jugadores[i].ficha1x = jugadores[i].ficha1x + 2;
                                jugadores[i].ficha1y = jugadores[i].ficha1y -2;
                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='A1';
                                vista(tablero,jugadores,numjug,tamtab);
                            }
                            if (dadox == 5)
                            {
                                jugadores[i].ficha1x = jugadores[i].ficha1x + 3;
                                jugadores[i].ficha1y = jugadores[i].ficha1y -2;
                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='A1';
                                vista(tablero,jugadores,numjug,tamtab);
                            }
                            if (dadox == 6)
                            {
                                jugadores[i].ficha1x = jugadores[i].ficha1x + 4;
                                jugadores[i].ficha1y = jugadores[i].ficha1y -2;
                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='A1';
                                vista(tablero,jugadores,numjug,tamtab);
                            }
                        }
                    }
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
