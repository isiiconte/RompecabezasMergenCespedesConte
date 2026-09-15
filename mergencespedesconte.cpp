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
bool mover(int tablero[5][5], int n, char tecla);
bool verificarVictoria(int tablero[5][5], int n);

int main()
{
    int opcion;
    int n = 0;
    int tablero[5][5];

    do
    {
        system("cls");

        cout << "================================" << endl;
        cout << "   ROMPECABEZAS NUMERICO" << endl;
        cout << "================================" << endl;
        cout << "Elegi la dificultad de tu rompecabezas (nxn)" << endl;
        cout << "1. Facil (3x3)" << endl;
        cout << "2. Normal (4x4)" << endl;
        cout << "3. Dificil (5x5)" << endl;
        cout << "4. Instrucciones" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";

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

        case 4:
            system("cls");

            cout << "========== INSTRUCCIONES ==========" << endl;
            cout << "El objetivo es ordenar todos los numeros de menor a mayor por filas, intercambiando el espacio en blanco con alguno de los numeros adyacentes." << endl;
            cout << endl;
            cout << "Controles:" << endl;
            cout << "W = Mover ficha hacia arriba" << endl;
            cout << "S = Mover ficha hacia abajo" << endl;
            cout << "A = Mover ficha hacia la izquierda" << endl;
            cout << "D = Mover ficha hacia la derecha" << endl;
            cout << "X = Salir del juego" << endl;
            cout << endl;

            system("pause");
            system("cls");
            break;
        case 5:
        cout << "Gracias por jugar!\n Creado por: Isabella Conte, Renzo Mergen y Anaclara Cespedes";
            break;
        default:
            cout << "Opcion invalida, por favor elija de nuevo." << endl;
            system("pause");
            system("cls");
            break;
        }
        if(opcion== 1 || opcion==2 || opcion==3)
        {
            inicializarTablero(tablero, n);
            mezclarTablero(tablero, n);

            int movimientos = 0;
            char tecla;

            dibujarTablero(tablero, n);

            cout << "Movimientos: " << movimientos << endl;
            cout << "Presiona W/A/S/D para mover | X para salir" << endl;



            do
            {
                tecla = _getch();


                if(tecla == 'x' || tecla == 'X')
                {
                    break;
                }


                if(mover(tablero, n, tecla))
                {
                    movimientos++;
                }

                dibujarTablero(tablero, n);

                cout << "Movimientos: " << movimientos << endl;
                cout << "Presiona W/A/S/D para mover | X para salir" << endl;



                if(verificarVictoria(tablero, n))
                {
                    cout << endl;
                    cout << "================================" << endl;
                    cout << "       GANASTE! FELICIDADES" << endl;
                    cout << "================================" << endl;
                    cout << "Movimientos realizados: "
                         << movimientos << endl;

                    system("pause");
                    break;
                }

            }
            while(tecla != 'x' && tecla != 'X');
        }
    }
    while(opcion != 5);
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

    int cantidadMovimientos = n * n * 100;

    for(int k = 0; k < cantidadMovimientos; k++)
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
        else
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




bool mover(int tablero[5][5], int n, char tecla)
{
    int nuevoX = vacioX;
    int nuevoY = vacioY;



    if(tecla == 'w' || tecla == 'W')
    {
        nuevoX = vacioX + 1;
    }


    else if(tecla == 's' || tecla == 'S')
    {
        nuevoX = vacioX - 1;
    }


    else if(tecla == 'a' || tecla == 'A')
    {
        nuevoY = vacioY + 1;
    }


    else if(tecla == 'd' || tecla == 'D')
    {
        nuevoY = vacioY - 1;
    }

    else
    {
        return false;
    }



    if(nuevoX >= 0 && nuevoX < n &&
            nuevoY >= 0 && nuevoY < n)
    {
        tablero[vacioX][vacioY] = tablero[nuevoX][nuevoY];
        tablero[nuevoX][nuevoY] = 0;

        vacioX = nuevoX;
        vacioY = nuevoY;

        return true;
    }

    return false;
}



bool verificarVictoria(int tablero[5][5], int n)
{
    int cont = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {

            if(i == n - 1 && j == n - 1)
            {
                return tablero[i][j] == 0;
            }


            if(tablero[i][j] != cont)
            {
                return false;
            }

            cont++;
        }
    }

    return true;
}




