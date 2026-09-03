// ranking de mejores tiempos
//mejroar menu
//max movimientos
//ranking menos movimientos



#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int vacioX, vacioY;

void inicializarTablero(int tablero[5][5], int n);
void mezclarTablero(int tablero[5][5], int n);
void dibujarTablero(int tablero[5][5], int n);
void mover(int tablero[5][5], int n, char tecla);
bool verificarVictoria(int tablero[5][5], int n);

int main()
{
    int opcion;
    int n=0;
    int tablero[5][5];
    do
    {
        cout << "Elegi la dificultad de tu rompecabezas (nxn)" << endl;
        cout << "1. Facil (3x3)\n2. Normal (4x4)\n3. Dificil (5x5)"<<endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            n = 3;
            break;
        case 2:
            n = 4;
            break;
        case 3:
            n = 5;
            break;
        default:
            cout << "Opcion invalida, porfavor elija de nuevo." << endl;
            break;
        }
        if(opcion != 1 && opcion!= 2 && opcion!= 3 )
        {
            system("pause");
            system("cls");
        }
    }
    while (opcion!= 1 && opcion!= 2 && opcion != 3);
    inicializarTablero(tablero, n);
    mezclarTablero(tablero, n);
    dibujarTablero(tablero, n);

    char tecla;

    do
    {
        tecla = _getch();

        mover(tablero, n, tecla);

        dibujarTablero(tablero, n);

    }
    while(tecla != 'x' && tecla != 'X');


    return 0;
}












void inicializarTablero(int tablero[5][5], int n)
{
    int contador = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tablero[i][j] = contador;
            contador++;
        }
    }
    tablero[n - 1][n - 1] = 0;

    vacioX = n - 1;
    vacioY = n - 1;
}

void mezclarTablero(int tablero[5][5], int n)
{
    srand(time(NULL));

    int movimientos = n * n * 100;

    for(int k = 0; k < movimientos; k++)
    {
        int direccion = rand() % 4;

        int nuevoX = vacioX;
        int nuevoY = vacioY;

        if(direccion == 0)
        {
            nuevoX = vacioX - 1;
        }
        else if(direccion == 1)
        {
            nuevoX = vacioX + 1;
        }
        else if(direccion == 2)
        {
            nuevoY = vacioY - 1;
        }
        else if(direccion == 3)
        {
            nuevoY = vacioY + 1;
        }

        if(nuevoX >= 0 && nuevoX < n &&
                nuevoY >= 0 && nuevoY < n)
        {
            tablero[vacioX][vacioY] = tablero[nuevoX][nuevoY];
            tablero[nuevoX][nuevoY] = 0;

            vacioX = nuevoX;
            vacioY = nuevoY;
        }
    }
}

void dibujarTablero(int tablero[5][5], int n)
{
    system("cls");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(tablero[i][j] == 0)
            {
                cout << setw(4) << " ";
            }
            else
            {
                cout << setw(4) << tablero[i][j];
            }
        }

        cout << endl;
    }
}

void mover(int tablero[5][5], int n, char tecla)
{
    int nuevoX = vacioX;
    int nuevoY = vacioY;

    if(tecla == 'w' || tecla == 'W')
    {
        nuevoX = vacioX - 1;
    }
    else if(tecla == 's' || tecla == 'S')
    {
        nuevoX = vacioX + 1;
    }
    else if(tecla == 'a' || tecla == 'A')
    {
        nuevoY = vacioY - 1;
    }
    else if(tecla == 'd' || tecla == 'D')
    {
        nuevoY = vacioY + 1;
    }

    if(nuevoX >= 0 && nuevoX < n &&
            nuevoY >= 0 && nuevoY < n)
    {
        tablero[vacioX][vacioY] = tablero[nuevoX][nuevoY];
        tablero[nuevoX][nuevoY] = 0;

        vacioX = nuevoX;
        vacioY = nuevoY;
    }
}
bool verificarVictoria(int tablero[5][5], int n)
{

        int cont = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (i == n - 1 && j == n - 1)
                {
                    return tablero[i][j] == 0;
                }
                if (tablero[i][j] != cont++)
                {
                    return false;
                }
            }
        }
        return true;



}


