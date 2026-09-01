#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int vacioX, vacioY;

void inicializarTablero(vector<vector<int>>& tablero, int n);
void mezclarTablero(vector<vector<int>>& tablero, int n);
void dibujarTablero(const vector<vector<int>>& tablero, int n);

int main()
{
    int opcion;
    int n=0;
    do{cout << "Elegi tamaño de tu rompecabezas (nxn)" << endl;
    cout << "1. 3x3\n2. 4x4\n3. 5x5"<<endl;
    cin >> opcion;

    switch(opcion){
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
    }
            if(opcion != 1 && opcion!= 2 && opcion!= 3 )
        {
            system("pause");
            system("cls");
        }
    }while (opcion!= 1 && opcion!= 2 && opcion != 3);
    return 0;
}

/*#include #include #include // Para _getch() (captura de teclas en Windows)
#include // Para rand() y srand()
#include // Para time()

using namespace std;

const int TAMANO = 4;
int tablero[TAMANO][TAMANO];
int vacioX = 3, vacioY = 3; // Coordenadas iniciales del espacio vacío (0)

// Inicializa el tablero de forma ordenada
void inicializarTablero() {
int cont = 1;
for (int i = 0; i < TAMANO; i++) {
for (int j = 0; j < TAMANO; j++) {
tablero[i][j] = cont++;
}
}
tablero[TAMANO - 1][TAMANO - 1] = 0; // El 0 representa el espacio vacío
vacioX = TAMANO - 1;
vacioY = TAMANO - 1;
}

// Mueve las piezas intercambiándolas con el espacio vacío (0)
bool mover(char direccion) {
int nX = vacioX;
int nY = vacioY;

// Determina qué pieza se moverá hacia el espacio vacío
if (direccion == 'w' || direccion == 'W') nX++; // Mueve la pieza de abajo hacia arriba
else if (direccion == 's' || direccion == 'S') nX--; // Mueve la pieza de arriba hacia abajo
else if (direccion == 'a' || direccion == 'A') nY++; // Mueve la pieza de la derecha a la izquierda
else if (direccion == 'd' || direccion == 'D') nY--; // Mueve la pieza de la izquierda a la derecha
else return false; // Tecla no válida

// Verifica que el movimiento esté dentro de los límites de la matriz
if (nX >= 0 && nX < TAMANO && nY >= 0 && nY < TAMANO) {
swap(tablero[vacioX][vacioY], tablero[nX][nY]);
vacioX = nX;
vacioY = nY;
return true;
}
return false;
}

// Mezcla el tablero realizando 200 movimientos aleatorios reales para asegurar que tenga solución
void mezclarTablero() {
char movimientos[] = {'W', 'A', 'S', 'D'};
int movimientosRealizados = 0;

while (movimientosRealizados < 200) {
char mov = movimientos[rand() % 4];
if (mover(mov)) {
movimientosRealizados++;
}
}
}

// Dibuja el tablero en la consola de forma alineada
void dibujarTablero() {
system("cls"); // Limpia la pantalla en Windows
cout << "=======================================" << endl;
cout << " ROMPECABEZAS DEL 15 " << endl;
cout << "=======================================" << endl;
cout << " Controles: W (Arriba) | S (Abajo)" << endl;
cout << " A (Izquierda) | D (Derecha)" << endl;
cout << "=======================================" << endl << endl;

for (int i = 0; i < TAMANO; i++) {
for (int j = 0; j < TAMANO; j++) {
if (tablero[i][j] == 0) {
cout << setw(5) << " "; // Imprime espacio en blanco para el 0
} else {
cout << setw(5) << tablero[i][j];
}
}
cout << endl << endl;
}
}

// Verifica si los números están ordenados del 1 al 15
bool verificarVictoria() {
int cont = 1;
for (int i = 0; i < TAMANO; i++) {
for (int j = 0; j < TAMANO; j++) {
// Si llegamos a la última casilla, debe estar el espacio vacío (0)
if (i == TAMANO - 1 && j == TAMANO - 1) {
return tablero[i][j] == 0;
}
if (tablero[i][j] != cont++) {
return false;
}
}
}
return true;
}

int main() {
srand(time(0)); // Genera una semilla aleatoria real basada en el tiempo

inicializarTablero();
mezclarTablero(); // Mezclado intensivo corregido

while (true) {
dibujarTablero();

if (verificarVictoria()) {
cout << "¡Felicidades! Has ordenado el rompecabezas de manera exitosa." << endl;
break;
}

// Lee la tecla del usuario al instante sin requerir la tecla Enter
char tecla = _getch();
mover(tecla);
}

return 0;
}

OTRA FORMA MAD LINDA
int TAMANO;
vector> tablero;
int vacioX, vacioY;

// Inicializa el tablero de forma ordenada
void inicializarTablero() {
tablero.resize(TAMANO, vector(TAMANO));

int cont = 1;

for (int i = 0; i < TAMANO; i++) {
for (int j = 0; j < TAMANO; j++) {
tablero[i][j] = cont++;
}
}

// El 0 representa el espacio vacío
tablero[TAMANO - 1][TAMANO - 1] = 0;

vacioX = TAMANO - 1;
vacioY = TAMANO - 1;
}

// Mueve una pieza hacia el espacio vacío
bool mover(char direccion) {
int nX = vacioX;
int nY = vacioY;

if (direccion == 'w' || direccion == 'W')
nX++; // Pieza de abajo sube

else if (direccion == 's' || direccion == 'S')
nX--; // Pieza de arriba baja

else if (direccion == 'a' || direccion == 'A')
nY++; // Pieza de la derecha va a la izquierda

else if (direccion == 'd' || direccion == 'D')
nY--; // Pieza de la izquierda va a la derecha

else
return false;

// Verifica límites
if (nX >= 0 && nX < TAMANO && nY >= 0 && nY < TAMANO) {

swap(tablero[vacioX][vacioY], tablero[nX][nY]);

vacioX = nX;
vacioY = nY;

return true;
}

return false;
}

// Mezcla el tablero mediante movimientos válidos
void mezclarTablero() {
char movimientos[] = {'W', 'A', 'S', 'D'};

int movimientosRealizados = 0;

// Mientras más grande el tablero, más movimientos
int cantidadMovimientos = TAMANO * TAMANO * 20;

while (movimientosRealizados < cantidadMovimientos) {

char mov = movimientos[rand() % 4];

if (mover(mov)) {
movimientosRealizados++;
}
}
}

// Dibuja el tablero
void dibujarTablero() {

system("cls");

cout << "=======================================" << endl;
cout << " ROMPECABEZAS " << TAMANO << "x" << TAMANO << endl;
cout << "=======================================" << endl;

cout << " Controles: W (Arriba) | S (Abajo)" << endl;
cout << " A (Izquierda) | D (Derecha)" << endl;

cout << "=======================================" << endl << endl;

for (int i = 0; i < TAMANO; i++) {

for (int j = 0; j < TAMANO; j++) {

if (tablero[i][j] == 0) {
cout << setw(5) << " ";
}
else {
cout << setw(5) << tablero[i][j];
}
}

cout << endl << endl;
}
}

// Verifica si el tablero está ordenado
bool verificarVictoria() {

int cont = 1;

for (int i = 0; i < TAMANO; i++) {

for (int j = 0; j < TAMANO; j++) {

// Última posición debe ser 0
if (i == TAMANO - 1 && j == TAMANO - 1) {
return tablero[i][j] == 0;
}

if (tablero[i][j] != cont++) {
return false;
}
}
}

return true;
}

int main() {

srand(time(0));

// ==============================
// ELECCIÓN DEL TAMAÑO
// ==============================

cout << "=======================================" << endl;
cout << " ROMPECABEZAS DESLIZANTE" << endl;
cout << "=======================================" << endl;

cout << endl;
cout << "Elige el tamano del rompecabezas." << endl;
cout << "Por ejemplo:" << endl;
cout << "3 = rompecabezas 3x3" << endl;
cout << "4 = rompecabezas 4x4" << endl;
cout << "5 = rompecabezas 5x5" << endl;
cout << endl;

do {
cout << "Ingresa el tamano (minimo 3): ";
cin >> TAMANO;

if (TAMANO < 3) {
cout << "El tamano debe ser 3 o mayor." << endl;
}

} while (TAMANO < 3);

// Inicializar y mezclar
inicializarTablero();
mezclarTablero();

// ==============================
// JUEGO
// ==============================

while (true) {

dibujarTablero();

if (verificarVictoria()) {
*/
#include // Para rand() y srand()
#include // Para time()

using namespace std;

const int TAMANO = 4;
int tablero[TAMANO][TAMANO];
int vacioX = 3, vacioY = 3; // Coordenadas iniciales del espacio vacío (0)

// Inicializa el tablero de forma ordenada
void inicializarTablero() {
int cont = 1;
for (int i = 0; i < TAMANO; i++) {
for (int j = 0; j < TAMANO; j++) {
tablero[i][j] = cont++;
}
}
tablero[TAMANO - 1][TAMANO - 1] = 0; // El 0 representa el espacio vacío
vacioX = TAMANO - 1;
vacioY = TAMANO - 1;
}

// Mueve las piezas intercambiándolas con el espacio vacío (0)
bool mover(char direccion) {
int nX = vacioX;
int nY = vacioY;

// Determina qué pieza se moverá hacia el espacio vacío
if (direccion == 'w' || direccion == 'W') nX++; // Mueve la pieza de abajo hacia arriba
else if (direccion == 's' || direccion == 'S') nX--; // Mueve la pieza de arriba hacia abajo
else if (direccion == 'a' || direccion == 'A') nY++; // Mueve la pieza de la derecha a la izquierda
else if (direccion == 'd' || direccion == 'D') nY--; // Mueve la pieza de la izquierda a la derecha
else return false; // Tecla no válida

// Verifica que el movimiento esté dentro de los límites de la matriz
if (nX >= 0 && nX < TAMANO && nY >= 0 && nY < TAMANO) {
swap(tablero[vacioX][vacioY], tablero[nX][nY]);
vacioX = nX;
vacioY = nY;
return true;
}
return false;
}

// Mezcla el tablero realizando 200 movimientos aleatorios reales para asegurar que tenga solución
void mezclarTablero() {
char movimientos[] = {'W', 'A', 'S', 'D'};
int movimientosRealizados = 0;

while (movimientosRealizados < 200) {
char mov = movimientos[rand() % 4];
if (mover(mov)) {
movimientosRealizados++;
}
}
}

// Dibuja el tablero en la consola de forma alineada
void dibujarTablero() {
system("cls"); // Limpia la pantalla en Windows
cout << "=======================================" << endl;
cout << " ROMPECABEZAS DEL 15 " << endl;
cout << "=======================================" << endl;
cout << " Controles: W (Arriba) | S (Abajo)" << endl;
cout << " A (Izquierda) | D (Derecha)" << endl;
cout << "=======================================" << endl << endl;

for (int i = 0; i < TAMANO; i++) {
for (int j = 0; j < TAMANO; j++) {
if (tablero[i][j] == 0) {
cout << setw(5) << " "; // Imprime espacio en blanco para el 0
} else {
cout << setw(5) << tablero[i][j];
}
}
cout << endl << endl;
}
}

// Verifica si los números están ordenados del 1 al 15
bool verificarVictoria() {
int cont = 1;
for (int i = 0; i < TAMANO; i++) {
for (int j = 0; j < TAMANO; j++) {
// Si llegamos a la última casilla, debe estar el espacio vacío (0)
if (i == TAMANO - 1 && j == TAMANO - 1) {
return tablero[i][j] == 0;
}
if (tablero[i][j] != cont++) {
return false;
}
}
}
return true;
}

int main() {
srand(time(0)); // Genera una semilla aleatoria real basada en el tiempo

inicializarTablero();
mezclarTablero(); // Mezclado intensivo corregido

while (true) {
dibujarTablero();

if (verificarVictoria()) {
cout << "¡Felicidades! Has ordenado el rompecabezas de manera exitosa." << endl;
break;
}

// Lee la tecla del usuario al instante sin requerir la tecla Enter
char tecla = _getch();
mover(tecla);
}

return 0;
}*/
