#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
using namespace std;

#define maxiju 15
#define maxix 100
#define maxiy 100
/** juan pablo sanchez gaitan**/
void datos (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug);

void mapa(char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);
//movimientos para la ficha 1
void movimientojug1f1 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);

void movimientojug2f1 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);

void movimientojug3f1 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);

void movimientojug4f1 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);

//movimientos para la ficha 2
void movimientojug1f2 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);

void movimientojug2f2 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);

void movimientojug3f2 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);

void movimientojug4f2 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);
//reglas del juego
void reglas (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy);
//el juego
void juego (char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);
//vista del mapa
void vista (char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);


struct parques
{
    string nombre;
    int nux;
    int nuy;
    int fichasfinales=0;
    int movfich = 0;
    int salidax=0,saliday=0;
    int llegadax=0,llegaday=0;
    int ficha1x,ficha1y;
    int x1,y1,x2,y2;
    int basex=0,basey=0;
    int contador1=0;
    int totalcontador1=0;
    int lanzamientos = 4;
    int cambiox,cambioy;
    int cambioy2,cambiox2;
    int basefantasma;
    char base;
    bool fichas1 =false;
    bool finalista = false;
    bool fichas2 =false;
    bool todas=false;
    bool ganador = false;
    bool salio = false;
    bool nu2 =true;
    bool nu3 =true;
    bool nu4 =true;
    bool nu5 =true;
    bool nu6 =true;
};

int main()
{
    struct parques jugadores [maxiju];
    int numjug=0,opcion=0,tamtabx=0,tamtaby=0;
    int opmapa=0;
    srand(time(NULL));
    char tablero [maxix][maxiy];
    int tablerofantasma [maxix][maxiy];
    cout<<"####### #     # ###  #####     ###  #####     #       #     # ######  ####### #     #    ####### ### #     # #######"<<endl;
    cout<<"   #    #     #  #  #     #     #  #     #    #       #     # #     # #     #  #   #        #     #  ##   ## #       "<<endl;
    cout<<"   #    #     #  #  #           #  #          #       #     # #     # #     #   # #         #     #  # # # # #       "<<endl;
    cout<<"   #    #######  #   #####      #   #####     #       #     # #     # #     #    #          #     #  #  #  # #####   "<<endl;
    cout<<"   #    #     #  #        #     #        #    #       #     # #     # #     #   # #         #     #  #     # #       "<<endl;
    cout<<"   #    #     #  #  #     #     #  #     #    #       #     # #     # #     #  #   #        #     #  #     # #       "<<endl;
    cout<<"   #    #     # ###  #####     ###  #####     #######  #####  ######  ####### #     #       #    ### #     # ####### "<<endl;
    cout<<endl;
    do
    {
        cout<<"MENU"<<endl;
        cout<<"1. JUGAR"<<endl;
        cout<<"2. REGLAS"<<endl;
        cout<<"3. SALIR"<<endl;
        cin>>opcion;
        if (opcion == 1)
        {
            cout<<"Cuantos jugadores van a jugar?"<<endl;
            cin>>numjug;
            cout<<"Que tipo de mapa escoges?"<<endl;
            cout<<"1. Normal"<<endl;
            cout<<"2. Personalizado"<<endl;
            cin>>opmapa;

            if (opmapa == 1)
            {
                tamtabx = 10;
                tamtaby = 10;
                if(numjug == 1 )
                {
                    cout<<"No puedes jugar solo, consiguete a alguien"<<endl;
                    cout<<"Vas a jugar contra la maquina en difultad normal"<<endl;
                    system("cls");

                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (tablero,jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    // juegoconlamaquina (tablero,jugadores,numjug,tamtab);
                }
                if(numjug >= 2)
                {
                    system("cls");
                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (tablero,jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);

                }

            }
            if (opmapa == 2)
            {
                cout<<"Digite el numero de filas"<<endl;
                cin>>tamtabx;
                cout<<"Digite el numero de columnas"<<endl;
                cin>>tamtaby;
                if(numjug == 1 )
                {
                    system("cls");
                    cout<<"No puedes jugar solo, consiguete a alguien"<<endl;
                    cout<<"Vas a jugar contra la maquina en difultad normal"<<endl;

                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (tablero,jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    // juegoconlamaquina (tablero,jugadores,numjug,tamtab);
                }
                if(numjug >= 2)
                {
                    system("cls");
                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (tablero,jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);

                }

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
void mapa(char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
{
    int mitadx=0;
    int mitady=0,nojuegox1=0,nojuegox2=0;
    mitadx=tamtabx/2;
    mitady=tamtaby/2;
    for(int i = 0; i < tamtabx; i++)
    {
        for(int j = 0; j < tamtaby; j++)
        {
            tablerofantasma[i][j]=0;
        }
    }
    jugadores[0].salidax=0;
    jugadores[0].saliday=1;
    jugadores[0].llegadax=mitadx-1;
    jugadores[0].llegaday=mitady-1;
    jugadores[0].basefantasma=1;
    jugadores[0].basex=0;
    jugadores[0].basey=0;
    jugadores[0].limite1 = 9;
    jugadores[0].limite2 = 16;
    jugadores[0].limite3 = 25;
    jugadores[0].limite4 = 31;
    jugadores[0].posx1 = 9;
    jugadores[0].posx2 = 0;
    jugadores[0].posy1 = 1;
    jugadores[0].posy2 = 8;


//jugador 2
    jugadores[1].salidax=tamtabx-1;
    jugadores[1].saliday=1;
    jugadores[1].llegadax=mitadx;
    jugadores[1].llegaday=mitady-1;
    jugadores[1].basefantasma=2;
    jugadores[1].basex=tamtabx-1;
    jugadores[1].basey=0;
    jugadores[1].cambiox = tamtabx - 1;
    jugadores[1].cambioy = tamtaby - 2;
    jugadores[1].cambiox2 = 0;
    jugadores[1].cambioy2 = 1;

//jugador 3
    jugadores[2].salidax=tamtabx-1;
    jugadores[2].saliday=tamtaby-2;
    jugadores[2].llegadax=mitadx;
    jugadores[2].llegaday=mitady;
    jugadores[2].basefantasma=3;
    jugadores[2].basex=tamtabx-1;
    jugadores[2].basey=tamtaby-1;
    //jugador 4
    jugadores[3].salidax=0;
    jugadores[3].saliday=tamtaby-2;
    jugadores[3].llegadax=mitadx-1;
    jugadores[3].llegaday=mitady;
    jugadores[3].basefantasma=4;
    jugadores[3].basex=0;
    jugadores[3].basey=tamtaby-1;
    //no juego 1
    nojuegox1=jugadores[0].basex;
    nojuegox2=jugadores[3].basex;
    for(int x = 0; x < tamtabx; x++)
    {
        for(int y = 0; y < tamtaby; y++)
        {
            tablero[x][y]='-';
            if (tablero[x][y] == tablero[nojuegox1][0])
            {
                tablero[x][y]='x';
                nojuegox1=nojuegox1+1;
            }
            if (tablero[x][y] == tablero[nojuegox2][tamtaby-1])
            {
                tablero[x][y]='x';
                nojuegox2=nojuegox2+1;
            }
        }
    }
    for(int i=0; i<4; i++)
    {

        tablerofantasma[jugadores[i].basex][jugadores[i].basey]=jugadores[i].basefantasma;
    }
}
void datos (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug)
{
    bool f1=false;
    bool f2=false;
    bool f3=false;
    bool f4=false;
    for(int i =0; i<numjug; i++)
    {
        cout<<"jugador No."<<i+1<<endl;
        cout<<"Nombre"<<endl;
        cin>>jugadores[i].nombre;
        cout<<"Escoje como quieres las fichas "<<endl;
        if (f1== false)
            cout<<" @ "<<endl;
        if(f2 == false)
            cout<<" # "<<endl;
        if(f3 == false)
            cout<<" & "<<endl;
        if(f4 == false)
            cout <<" % "<<endl;
        cin>>jugadores[i].base;
        if (jugadores[i].base == '@')
            f1=true;
        if (jugadores[i].base == '#')
            f2=true;
        if (jugadores[i].base == '&')
            f3=true;
        if (jugadores[i].base == '%')
            f4=true;

        tablero[jugadores[i].basex][jugadores[i].basey]=jugadores[i].base;
        tablero[jugadores[i].llegadax][jugadores[i].llegaday]=jugadores[i].base;

    }
    system("cls");


}
void vista (char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
{

    for(int i = 0; i < tamtabx; i++)
    {
        for(int j = 0; j < tamtaby; j++)
        {
            cout<<setw(3.5)<<tablero[i][j]<<'|';
        }
        cout<<endl;
    }
}
void juego (char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
{
    int turno=0,i=0,respu=0,contador=1,fichmov=0;
    int dadox=0,dadoy=0;
    bool movi = false;
    cout<<"RECUERDEN SUS FICHAS JUGADORES "<<endl;
    for (int u=0; u<numjug; u++)
    {

        cout<<"JUGADOR # "<<u+1<<endl;
        cout<<"SUS FICHAS SON ESTAS: "<<jugadores[u].base<<endl;
    }

    do
    {
        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
        cout<<"Turno #"<<turno<<endl;
        cout<<"Juega "<<jugadores[i].nombre<<endl;
        cout<<"Tirar dados? 1.si"<<endl;
        cin>>respu;
        if (respu == 1)
        {
            do
            {
                cout<<"Lanzamiento #"<<contador<<endl;
                dadox = rand() % 6 + 1;
                dadoy = rand() % 6 + 1;
                cout<<dadox<<","<<dadoy<<endl;

                if (jugadores[i].fichas1==true || jugadores[i].fichas2==true )
                {
                    if (turno > 0)
                    {
                        jugadores[i].salio=true;
                    }
                }
                if (jugadores[i].fichas1 == false || jugadores[i].fichas2 == false)
                {
                    if(dadox==1)
                    {
                        if(dadoy==1)
                        {
                            if (jugadores[i].fichas1 == false || jugadores[i].fichas2 == false)
                            {
                                if (jugadores[i].fichas1 == false)
                                {
                                    cout<<"SALE 1 FICHA"<<endl;
                                    jugadores[i].ficha1x=jugadores[i].salidax;
                                    jugadores[i].ficha1y=jugadores[i].saliday;

                                    tablero[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].base;
                                    tablerofantasma[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].basefantasma;
                                    jugadores[i].lanzamientos =1;
                                    jugadores[i].fichas1=true;
                                    jugadores[i].salio=true;
                                }

                            }
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
                            if (jugadores[i].fichas1 == false || jugadores[i].fichas2==false)
                            {
                                if (jugadores[i].fichas1==false)
                                {
                                    jugadores[i].ficha1x=jugadores[i].salidax;
                                    jugadores[i].ficha1y=jugadores[i].saliday;
                                    cout<<"SALE 1 FICHA"<<endl;
                                    tablero[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].base;
                                    tablerofantasma[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].basefantasma;
                                    jugadores[i].lanzamientos =1;
                                    jugadores[i].fichas1=true;
                                    jugadores[i].salio=true;
                                }
                                if(jugadores[i].fichas2==false)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].salio=true;
                                }
                            }
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
                            if (jugadores[i].fichas1 == false || jugadores[i].fichas2==false)
                            {
                                if (jugadores[i].fichas1==false)
                                {
                                    jugadores[i].ficha1x=jugadores[i].salidax;
                                    jugadores[i].ficha1y=jugadores[i].saliday;
                                    cout<<"SALE 1 FICHA"<<endl;
                                    tablero[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].base;
                                    tablerofantasma[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].basefantasma;
                                    jugadores[i].lanzamientos =1;
                                    jugadores[i].fichas1=true;
                                    jugadores[i].salio=true;
                                }
                                if(jugadores[i].fichas2==false)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].salio=true;
                                }
                            }
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
                            if (jugadores[i].fichas1 == false || jugadores[i].fichas2==false)
                            {

                                if (jugadores[i].fichas1==false)
                                {
                                    jugadores[i].ficha1x=jugadores[i].salidax;
                                    jugadores[i].ficha1y=jugadores[i].saliday;
                                    cout<<"SALE 1 FICHA"<<endl;
                                    tablero[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].base;
                                    tablerofantasma[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].basefantasma;
                                    jugadores[i].lanzamientos =1;
                                    jugadores[i].fichas1=true;
                                    jugadores[i].salio=true;
                                }
                                if(jugadores[i].fichas2==false)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].salio=true;
                                }
                            }
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
                            if (jugadores[i].fichas1 == false || jugadores[i].fichas2==false)
                            {
                                if (jugadores[i].fichas1==false)
                                {
                                    cout<<"SALE 1 FICHA"<<endl;
                                    jugadores[i].ficha1x=jugadores[i].salidax;
                                    jugadores[i].ficha1y=jugadores[i].saliday;
                                    tablero[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].base;
                                    tablerofantasma[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].basefantasma;

                                    jugadores[i].lanzamientos =1;
                                    jugadores[i].fichas1=true;
                                    jugadores[i].salio=true;
                                }
                                if(jugadores[i].fichas2==false)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].salio=true;
                                }
                            }
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
                            if(jugadores[i].fichas1== false || jugadores[i].fichas2 == false)
                            {
                                if (jugadores[i].fichas1 == false)
                                {
                                    cout<<"SALEN 1 FICHA"<<endl;
                                    jugadores[i].ficha1x=jugadores[i].salidax;
                                    jugadores[i].ficha1y=jugadores[i].saliday;

                                    tablero[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].base;
                                    tablerofantasma[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].basefantasma;
                                    jugadores[i].lanzamientos =1;
                                    jugadores[i].fichas1=true;
                                    jugadores[i].salio=true;
                                }

                            }
                        }
                        if(dadoy != 6)
                        {
                            contador++;
                        }
                    }
                    if (contador == jugadores[i].lanzamientos)
                    {
                        jugadores[i].salio = true;
                        contador = 0;
                    }
                }
            }
            while (jugadores[i].salio == false);
            if (turno == 3)
            {
                jugadores[i].lanzamientos =1;
                jugadores[i].fichas1=true;
            }
            if (turno > 0)
            {
                if (jugadores[i].fichas1 == true)
                {

                    if (jugadores[i].fichas1 == true)
                    {
                        cout<<"que fichas quieres mover?: "<<endl;
                        cout<<"1. ficha 1"<<endl;
                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]=jugadores[i].base;
                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=jugadores[i].basefantasma;
                    }
                    cin>>fichmov;

                    if(fichmov == 1)
                    {

                        cout<<"cuantas casillas quieres mover la ficha?"<<endl;
                        cout<<"Op 1 "<<dadox<<" posiciones"<<endl;
                        cout<<"Op 2 "<<dadoy<<" posiciones"<<endl;
                        cin>>jugadores[i].movfich;
                        if (jugadores[i].movfich == 1)
                        {
                            if (jugadores[i].nombre == jugadores[0].nombre)
                            {
                                movimientojug1f1 (tablero,jugadores,numjug,tamtabx,tamtaby,dadox,dadoy);
                            }
                            if (jugadores[i].nombre == jugadores[1].nombre)
                            {
                                // movimientojug2f1(tablero,jugadores,numjug,tamtabx,tamtaby,dadox,dadoy);
                            }
                            if (jugadores[i].nombre == jugadores[2].nombre)
                            {
                                // movimientojug3f1(tablero,jugadores,numjug,tamtabx,tamtaby,dadox,dadoy);
                            }
                            if (jugadores[i].nombre == jugadores[3].nombre)
                            {
                                // movimientojug4f1(tablero,jugadores,numjug,tamtabx,tamtaby,dadox,dadoy);
                            }
                        }

                    }

                }
            }
            i++;
            movi = false;


            if(i == numjug)
            {
                i=0;
                turno++;
                jugadores[i].salio = false;
            }
            if (jugadores[i].fichas1 == false)
            {

                jugadores[i].salio = false;

                jugadores[i].lanzamientos = 4;
                contador =1;
            }

        }
        /**
        Sleep(2000);
        system("cls");**/
    }
    while(jugadores[i].finalista == false);
}
void movimientojug1f1 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy)
{
    int suma=0;
    if (jugadores[0].movfich == 1)
    {
        if (jugadores[0].contador1 <=jugadores[0].limite1)
        {
            jugadores[0].ficha1y = jugadores[0].posy1;
            jugadores[0].ficha1x = jugadores[0].ficha1x +dadox;
        }
        if (jugadores[0].contador1 > jugadores[0].limite1 && jugadores[0].contador1 <=jugadores[0].limite2)
        {
            jugadores[0].ficha1x = jugadores[0].posx1;
            suma = jugadores[0].limite1 - jugadores[0].contador1;
            jugadores[0].ficha1y = jugadores[0].ficha1y + suma;
        }
        if (jugadores[0].contador1 >jugadores[0].limite2 && jugadores[0].contador1 <=jugadores[0].limite3)
        {
            jugadores[0].ficha1y = jugadores[0].posy2;
            suma = jugadores[0].limite3 - jugadores[0].contador1;
            jugadores[0].ficha1x = jugadores[0].ficha1x - suma;
        }
        if (jugadores[0].contador1 >jugadores[0].limite3 && jugadores[0].contador1 <=jugadores[0].limite4)
        {
            jugadores[0].ficha1x = jugadores[0].posx2;
            suma = jugadores[0].limite1 - jugadores[0].contador1;
            jugadores[0].ficha1y = jugadores[0].ficha1y - suma;
        }
        if (jugadores[0].contador1 >jugadores[0].limite3)
        {
            
        }
    }
}
void ganador ()
{
    cout<<"has ganado felicidades jugador"<<endl;
}
