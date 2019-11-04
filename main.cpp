#include <iostream>
#include <iomanip>
#include <fstream>
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

void mapatodoslosjugadores(char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);

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
    int ficha2x,ficha2y;
    int x1,y1,x2,y2;
    int basex=0,basey=0;
    int contador1=0;
    int contador2=0;
    int totalcontador1=0;
    int lanzamientos = 4;
    int limite1,limite2;
    int limite3,limite4,limite5;
    int posx1,posx2,posy1,posy2;
    int basefantasma;
    char base;
    bool fichas1 =false;
    bool ficha1final = false;
    bool ficha2final = false;
    bool fichas2 =false;
    bool todas=false;
    bool ganador = false;
    bool salio = false;
};

int main()
{
    struct parques jugadores [maxiju];
    int numjug=0,opcion=0,tamtabx=0,tamtaby=0;
    string texto;
    int opmapa=0;
    ifstream archi;

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
            tamtabx = 10;
            tamtaby = 10;
            if(numjug == 1 )
            {
                cout<<"No puedes jugar solo, consiguete a alguien"<<endl;
                cout<<"Vas a jugar contra la maquina en difultad normal"<<endl;
                system("cls");

                mapatodoslosjugadores(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                datos (tablero,jugadores,numjug);
                juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                // juegoconlamaquina (tablero,jugadores,numjug,tamtab);
            }
            if(numjug >= 2)
            {
                system("cls");
                mapatodoslosjugadores(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                datos (tablero,jugadores,numjug);
                juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);

            }
        }
        if (opcion == 2)
        {
            archi.open("reglas.txt",ios::in);
            while(!archi.eof())
            {
                getline(archi,texto);
                cout<<texto<<endl;
            }
        }
        if (opcion == 3)
        {
            system("cls");
        }
    }
    while(opcion !=3);
}
void mapatodoslosjugadores(char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
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
    jugadores[0].basex= 0;
    jugadores[0].basey= 0;
    jugadores[0].limite1 = 9;
    jugadores[0].limite2 = 16;
    jugadores[0].limite3 = 25;
    jugadores[0].limite4 = 32;
    jugadores[0].limite5 = 39;
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
    jugadores[1].limite1 = 9;
    jugadores[1].limite2 = 16;
    jugadores[1].limite3 = 25;
    jugadores[1].limite4 = 31;

//jugador 3
    jugadores[2].salidax=tamtabx-1;
    jugadores[2].saliday=tamtaby-2;
    jugadores[2].llegadax=mitadx;
    jugadores[2].llegaday=mitady;
    jugadores[2].basefantasma=3;
    jugadores[2].basex=tamtabx-1;
    jugadores[2].basey=tamtaby-1;
    jugadores[2].limite1 = 9;
    jugadores[2].limite2 = 16;
    jugadores[2].limite3 = 25;
    jugadores[2].limite4 = 31;
    //jugador 4
    jugadores[3].salidax=0;
    jugadores[3].saliday=tamtaby-2;
    jugadores[3].llegadax=mitadx-1;
    jugadores[3].llegaday=mitady;
    jugadores[3].basefantasma=4;
    jugadores[3].basex=0;
    jugadores[3].basey=tamtaby-1;
    jugadores[3].limite1 = 9;
    jugadores[3].limite2 = 16;
    jugadores[3].limite3 = 25;
    jugadores[3].limite4 = 31;


    //no juego 1
    nojuegox1=jugadores[0].basex;
    nojuegox2=jugadores[3].basex;
    for (int i=0; i<tamtabx; i++)
    {
        tablero[i][0]='x';
        tablero[i][tamtaby-1]='x';
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
        if (i == 0)
        {
            for (int x=2; x<jugadores[i].llegaday; x++)
            {
                tablero[jugadores[i].llegadax][x]='+';
            }
            tablero[jugadores[i].basex][jugadores[i].basey]=jugadores[i].base;
            tablero[jugadores[i].llegadax][jugadores[i].llegaday]=jugadores[i].base;
        }
        if (i == 1)
        {
            for (int x=8; x>jugadores[i].llegadax; x--)
            {
                tablero[x][jugadores[i].llegaday]='+';
            }
            tablero[jugadores[i].basex][jugadores[i].basey]=jugadores[i].base;
            tablero[jugadores[i].llegadax][jugadores[i].llegaday]=jugadores[i].base;
        }

        if (i == 2)
        {
            for (int x=7; x>jugadores[i].llegaday; x--)
            {
                tablero[jugadores[i].llegaday][x]='+';
            }
            tablero[jugadores[i].basex][jugadores[i].basey]=jugadores[i].base;
            tablero[jugadores[i].llegadax][jugadores[i].llegaday]=jugadores[i].base;
        }

        if (i == 3)
        {
            for (int x=1; x<jugadores[i].llegadax; x++)
            {
                tablero[x][jugadores[i].llegaday]='+';
            }
            tablero[jugadores[i].basex][jugadores[i].basey]=jugadores[i].base;
            tablero[jugadores[i].llegadax][jugadores[i].llegaday]=jugadores[i].base;
        }

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
        cout<<"Turno #"<<turno<<endl;
        cout<<"Juega "<<jugadores[i].nombre<<endl;
        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
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
                                if(jugadores[i].fichas1==true)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].ficha2x=jugadores[i].salidax;
                                    jugadores[i].ficha2y=jugadores[i].saliday;
                                    jugadores[i].salio=true;
                                }
                                if (jugadores[i].fichas1 == false)
                                {
                                    cout<<"SALE 1 FICHA"<<endl;
                                    jugadores[i].ficha1x=jugadores[i].salidax;
                                    jugadores[i].ficha1y=jugadores[i].saliday;
                                    jugadores[i].fichas2=true;
                                    jugadores[i].ficha2x=jugadores[i].salidax;
                                    jugadores[i].ficha2y=jugadores[i].saliday;
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
                                if(jugadores[i].fichas1==true)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].ficha2x=jugadores[i].salidax;
                                    jugadores[i].ficha2y=jugadores[i].saliday;
                                    jugadores[i].salio=true;
                                }
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
                                if(jugadores[i].fichas1==true)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].ficha2x=jugadores[i].salidax;
                                    jugadores[i].ficha2y=jugadores[i].saliday;
                                    jugadores[i].salio=true;
                                }
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
                                if(jugadores[i].fichas1==true)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].ficha2x=jugadores[i].salidax;
                                    jugadores[i].ficha2y=jugadores[i].saliday;
                                    jugadores[i].salio=true;
                                }
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
                                if(jugadores[i].fichas1==true)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].ficha2x=jugadores[i].salidax;
                                    jugadores[i].ficha2y=jugadores[i].saliday;
                                    jugadores[i].salio=true;
                                }
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
                                if(jugadores[i].fichas1==true)
                                {
                                    jugadores[i].fichas2=true;
                                    jugadores[i].ficha2x=jugadores[i].salidax;
                                    jugadores[i].ficha2y=jugadores[i].saliday;
                                    jugadores[i].salio=true;
                                }
                                if (jugadores[i].fichas1 == false)
                                {
                                    cout<<"SALEN 1 FICHA"<<endl;
                                    jugadores[i].ficha1x=jugadores[i].salidax;
                                    jugadores[i].ficha1y=jugadores[i].saliday;
                                    jugadores[i].ficha2x=jugadores[i].salidax;
                                    jugadores[i].ficha2y=jugadores[i].saliday;
                                    tablero[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].base;
                                    tablerofantasma[jugadores[i].salidax][jugadores[i].saliday]=jugadores[i].basefantasma;
                                    jugadores[i].lanzamientos =1;
                                    jugadores[i].fichas1=true;
                                    jugadores[i].fichas2=true;
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
                if (jugadores[i].fichas1 == true || jugadores[i].fichas2 == true )
                {
                    cout<<"que fichas quieres mover?: "<<endl;

                    if (jugadores[i].fichas1 == true )
                    {
                        if (jugadores[i].ficha1final == false)
                        {
                            cout<<"1. ficha 1"<<endl;
                        }
                    }
                    if (jugadores[i].fichas2 == true)
                    {
                        if (jugadores[i].ficha2final == false)
                        {
                            cout<<"2. ficha 2"<<endl;
                        }
                    }
                    cin>>fichmov;
                    cout<<"cuantas casillas quieres mover la ficha?"<<endl;
                    cout<<"Op 1 "<<dadox<<" posiciones"<<endl;
                    cout<<"Op 2 "<<dadoy<<" posiciones"<<endl;
                    cin>>jugadores[i].movfich;
                    if(fichmov == 1)
                    {
                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]=' ';
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

                    if (fichmov == 2)
                    {
                        tablero[jugadores[i].ficha2x][jugadores[i].ficha2y]=' ';
                        if (jugadores[i].nombre == jugadores[0].nombre)
                        {
                            movimientojug1f2 (tablero,jugadores,numjug,tamtabx,tamtaby,dadox,dadoy);
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
        Sleep(2000);
        system("cls");
    }
    while(jugadores[i].ganador == false);
}
void movimientojug1f1 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy)
{
    int suma=0;
    int dado = 0;
    int tamx = tamtabx-2;
    if (jugadores[0].movfich == 1)
    {
        dado=dadox;
    }
    if (jugadores[0].movfich == 2)
    {
        dado=dadoy;
    }
    jugadores[0].contador1 = jugadores[0].contador1 + dado;
    if (jugadores[0].contador1 <=jugadores[0].limite1)
    {
        jugadores[0].ficha1y = jugadores[0].posy1;
        jugadores[0].ficha1x = jugadores[0].ficha1x +dado;
        if ( jugadores[0].ficha1x > jugadores[0].posx1)
        {
            suma = jugadores[0].limite1 - jugadores[0].ficha1x;
            jugadores[0].ficha1y = jugadores[0].ficha1y + suma;
            tablero[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].base;
            jugadores[0].ficha1x = jugadores[0].posx1;
        }
        tablero[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].base;

        //tablerofantasma[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].basefantasma;
    }
    if (jugadores[0].contador1 > jugadores[0].limite1 && jugadores[0].contador1 <jugadores[0].limite2)
    {
        jugadores[0].ficha1x = jugadores[0].posx1;
        suma = jugadores[0].contador1 - tamx;
        jugadores[0].ficha1y = suma;
        tablero[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].base;
        // tablerofantasma[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].basefantasma;
    }
    if (jugadores[0].contador1 >= jugadores[0].limite2 && jugadores[0].contador1 <=jugadores[0].limite3)
    {
        jugadores[0].ficha1y = jugadores[0].posy2;
        suma = jugadores[0].limite3 - jugadores[0].contador1 ;
        jugadores[0].ficha1x = suma;
        tablero[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].base;
        // tablerofantasma[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].basefantasma;
    }
    if (jugadores[0].contador1 > jugadores[0].limite3 && jugadores[0].contador1 <=jugadores[0].limite4)
    {
        if(jugadores[0].contador1== jugadores[0].limite3 +1)
        {
            jugadores[0].ficha1x = jugadores[0].salidax;
            jugadores[0].ficha1y = tamtaby -3;
        }
        if(jugadores[0].contador1== jugadores[0].limite3 +2)
        {
            jugadores[0].ficha1x = jugadores[0].salidax;
            jugadores[0].ficha1y = tamtaby -4 ;
        }
        if(jugadores[0].contador1== jugadores[0].limite3 +3)
        {
            jugadores[0].ficha1x = jugadores[0].salidax;
            jugadores[0].ficha1y = tamtaby -5;
        }
        if(jugadores[0].contador1== jugadores[0].limite3 +4)
        {
            jugadores[0].ficha1x = jugadores[0].salidax;
            jugadores[0].ficha1y = tamtaby -6;
        }
        if(jugadores[0].contador1== jugadores[0].limite3 +5)
        {
            jugadores[0].ficha1x = jugadores[0].salidax;
            jugadores[0].ficha1y =tamtaby -7;
        }
        if(jugadores[0].contador1== jugadores[0].limite3 +6)
        {
            jugadores[0].ficha1x = jugadores[0].salidax;
            jugadores[0].ficha1y = tamtaby -8;
        }
        if(jugadores[0].contador1== jugadores[0].limite4)
        {
            jugadores[0].ficha1x = jugadores[0].salidax;
            jugadores[0].ficha1y = tamtaby -9;
        }
        tablero[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].base;
    }
    if (jugadores[0].contador1 > jugadores[0].limite4 && jugadores[0].contador1 <=jugadores[0].limite5)
    {
        jugadores[0].ficha1y = jugadores[0].saliday;
        if (jugadores[0].contador1 == jugadores[0].limite4+1)
        {
            jugadores[0].ficha1x =jugadores[0].salidax+1;

        }
        if (jugadores[0].contador1 == jugadores[0].limite4+2)
        {
            jugadores[0].ficha1x = jugadores[0].salidax+2;

        }
        if (jugadores[0].contador1 == jugadores[0].limite4+3)
        {
            jugadores[0].ficha1x = jugadores[0].salidax+3;

        }
        if (jugadores[0].contador1 == jugadores[0].limite4+4)
        {
            jugadores[0].ficha1x = jugadores[0].salidax+4;

        }
        if (jugadores[0].contador1 == jugadores[0].limite4+5)
        {
            jugadores[0].ficha1x = jugadores[0].salidax+4;
            jugadores[0].ficha1y = jugadores[0].saliday+1;
        }
        if (jugadores[0].contador1 == jugadores[0].limite4+6)
        {
            jugadores[0].ficha1x = jugadores[0].salidax+4;
            jugadores[0].ficha1y = jugadores[0].saliday+2;
        }
        if (jugadores[0].contador1 == jugadores[0].limite5)
        {
            jugadores[0].ficha1x = jugadores[0].salidax+4;
            jugadores[0].ficha1y = jugadores[0].saliday+3;
            cout<<"La ficha llego al final"<<endl;
            jugadores[0].fichasfinales = jugadores[0].fichasfinales + 1;
            jugadores[0].ficha1final =true;

        }
        tablero[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].base;

    }
    if (jugadores[0].contador1 > jugadores[0].limite5)
    {
        cout<<"No puedes mover la ficha"<<endl;
        jugadores[0].contador1 = jugadores[0].contador1 -dado;
        tablero[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].base;
    }



}
void movimientojug1f2 (char tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby,int dadox,int dadoy)
{
    int suma=0;
    int dado = 0;
    int tamx = tamtabx-2;
    if (jugadores[0].movfich == 1)
    {
        dado=dadox;
    }
    if (jugadores[0].movfich == 2)
    {
        dado=dadoy;
    }
    jugadores[0].contador2 = jugadores[0].contador2 + dado;
    if (jugadores[0].contador2 <=jugadores[0].limite1)
    {
        jugadores[0].ficha2y = jugadores[0].posy1;
        jugadores[0].ficha2x = jugadores[0].ficha2x +dado;
        if ( jugadores[0].ficha1x > jugadores[0].posx1)
        {
            suma = jugadores[0].limite1 - jugadores[0].ficha2x;
            jugadores[0].ficha2y = jugadores[0].ficha2y + suma;
            tablero[jugadores[0].ficha2x][jugadores[0].ficha2y]=jugadores[0].base;
            jugadores[0].ficha2x = jugadores[0].posx1;
        }
        tablero[jugadores[0].ficha2x][jugadores[0].ficha2y]=jugadores[0].base;

        //tablerofantasma[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].basefantasma;
    }
    if (jugadores[0].contador2 > jugadores[0].limite1 && jugadores[0].contador2 <jugadores[0].limite2)
    {
        jugadores[0].ficha2x = jugadores[0].posx1;
        suma = jugadores[0].contador2 - tamx;
        jugadores[0].ficha2y = suma;
        tablero[jugadores[0].ficha2x][jugadores[0].ficha2y]=jugadores[0].base;
        cout<<"h2"<<endl;
        // tablerofantasma[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].basefantasma;
    }
    if (jugadores[0].contador2 >= jugadores[0].limite2 && jugadores[0].contador2 <=jugadores[0].limite3)
    {
        jugadores[0].ficha2y = jugadores[0].posy2;
        suma = jugadores[0].limite3 - jugadores[0].contador2 ;
        jugadores[0].ficha2x = suma;
        tablero[jugadores[0].ficha2x][jugadores[0].ficha2y]=jugadores[0].base;
        cout<<"h3"<<endl;
        // tablerofantasma[jugadores[0].ficha1x][jugadores[0].ficha1y]=jugadores[0].basefantasma;
    }
    if (jugadores[0].contador2 > jugadores[0].limite3 && jugadores[0].contador2 <=jugadores[0].limite4)
    {
        if(jugadores[0].contador2== jugadores[0].limite3 +1)
        {
            jugadores[0].ficha2x = jugadores[0].salidax;
            jugadores[0].ficha2y = tamtaby -3;
        }
        if(jugadores[0].contador2== jugadores[0].limite3 +2)
        {
            jugadores[0].ficha2x = jugadores[0].salidax;
            jugadores[0].ficha2y = tamtaby -4 ;
        }
        if(jugadores[0].contador2== jugadores[0].limite3 +3)
        {
            jugadores[0].ficha2x = jugadores[0].salidax;
            jugadores[0].ficha2y = tamtaby -5;
        }
        if(jugadores[0].contador2== jugadores[0].limite3 +4)
        {
            jugadores[0].ficha2x = jugadores[0].salidax;
            jugadores[0].ficha2y = tamtaby -6;
        }
        if(jugadores[0].contador2== jugadores[0].limite3 +5)
        {
            jugadores[0].ficha2x = jugadores[0].salidax;
            jugadores[0].ficha2y =tamtaby -7;
        }
        if(jugadores[0].contador2== jugadores[0].limite3 +6)
        {
            jugadores[0].ficha2x = jugadores[0].salidax;
            jugadores[0].ficha2y = tamtaby -8;
        }
        if(jugadores[0].contador2== jugadores[0].limite4)
        {
            jugadores[0].ficha2x = jugadores[0].salidax;
            jugadores[0].ficha2y = tamtaby -9;
        }
        tablero[jugadores[0].ficha2x][jugadores[0].ficha2y]=jugadores[0].base;
    }
    if (jugadores[0].contador2 > jugadores[0].limite4 && jugadores[0].contador2 <=jugadores[0].limite5)
    {
        jugadores[0].ficha2y = jugadores[0].saliday;
        if (jugadores[0].contador2 == jugadores[0].limite4+1)
        {
            jugadores[0].ficha2x =jugadores[0].salidax+1;

        }
        if (jugadores[0].contador2 == jugadores[0].limite4+2)
        {
            jugadores[0].ficha2x = jugadores[0].salidax+2;

        }
        if (jugadores[0].contador2 == jugadores[0].limite4+3)
        {
            jugadores[0].ficha2x = jugadores[0].salidax+3;

        }
        if (jugadores[0].contador2 == jugadores[0].limite4+4)
        {
            jugadores[0].ficha2x = jugadores[0].salidax+4;

        }
        if (jugadores[0].contador2 == jugadores[0].limite4+5)
        {
            jugadores[0].ficha2x = jugadores[0].salidax+4;
            jugadores[0].ficha2y = jugadores[0].saliday+1;
        }
        if (jugadores[0].contador2 == jugadores[0].limite4+6)
        {
            jugadores[0].ficha2x = jugadores[0].salidax+4;
            jugadores[0].ficha2y = jugadores[0].saliday+2;
        }
        if (jugadores[0].contador2 == jugadores[0].limite5)
        {
            jugadores[0].ficha2x = jugadores[0].salidax+4;
            jugadores[0].ficha2y = jugadores[0].saliday+3;
            cout<<"La ficha llego al final"<<endl;
            jugadores[0].fichasfinales = jugadores[0].fichasfinales + 1;
            jugadores[0].ficha2final =true;

        }
        tablero[jugadores[0].ficha2x][jugadores[0].ficha2y]=jugadores[0].base;

    }
    if (jugadores[0].contador2 > jugadores[0].limite5)
    {
        cout<<"No puedes mover la ficha"<<endl;
        jugadores[0].contador2 = jugadores[0].contador2 -dado;
        tablero[jugadores[0].ficha2x][jugadores[0].ficha2y]=jugadores[0].base;
    }



}
void ganador ()
{
    cout<<"has ganado felicidades jugador"<<endl;
}
