#include<iostream>
#include<string>
#include <cstdlib>
#include <time.h>

//Inicialización 2 Tablas
const short tamaño = 10;

char tablero1[tamaño][tamaño];
char tablero2[tamaño][tamaño];

//Función actualizar matriz
void actualizar(const short tamaño) {

	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {

		}
	}
}

//Función imprimir tableros
void imprimir(const short tamaño) {
	std::cout << "Tablero jugador 1" << std::endl;
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			std::cout << " " << tablero1[i][j];

		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Tablero jugador 2" << std::endl;
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			std::cout << " " << tablero2[i][j];

		}
		std::cout << std::endl;
	}
}

//Función coididencia de 1 casilla si es '~' o no. Fila, columna y nombre del tablero
bool coincidencia(short x, short y, std::string nombreTablero) {

	//Inicialización de puntero
	char* puntero = NULL;

	//Comprobar que tablero del jugador apunta
	if (nombreTablero == "tablero1") {//correción de los magic numbers
		puntero = &tablero1[x][y];
	}
	else if(nombreTablero == "tablero2") {
		puntero = &tablero2[x][y];
	}
	else {//Si el nombre del tablero es diferente (Añadir otro jugador por ejemplo)
		std::cout << "No hay este tablero" << std::endl;
	}

	//Comprovación de la casilla
	if (*puntero != '~') {
		return true;
	}
	else {
		return false;
	}
}

//Función para verificar
void verificar(short x, short y, char* puntero) {

}

//función número random
short randNum() {
	srand(time(NULL));
	short num = rand() % 10;//rango 0 a 9

	return num;
}

//función random orientación
bool randOrientacion() {
	srand(time(NULL));
	bool num = rand() % 1;//rango 0 a 1

	return num;
}

//función insetar barcos
void insertarBarcos() {
	char posicionInicial[2];

	//convertimos los números aleatorios en char
	posicionInicial[0] = (char)randNum();
	posicionInicial[1] = (char)randNum();

	//orientación TRUE para Horizontal
	if (randOrientacion()) {

	}
	else {//false para la orietacion vertival

	}

}

//Modo Horizontal
void modoH(char nombreTabla[tamaño][tamaño]) {
	char* puntero;

	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			puntero = &nombreTabla[i][j];

		}
	}
}

//Modo Vertical
void modoV(char nombreTabla[tamaño][tamaño]) {
	char* puntero;

	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			puntero = &nombreTabla[i][j];
			j = tamaño - 1;//saltarse las filas
		}
	}
}

void main() {
	//Parte 1: Tablero
	// Valores de la tablas por defecto
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			tablero1[i][j] = '~';
			tablero2[i][j] = '~';
		}
	}
	//Mostrar tablero
	imprimir(tamaño);

	//Parte 2: Barcos
	//Inicialización barcos
	const short barco3[3] = { '3','3','3' };
	const short barco4[4] = { '4','4','4','4' };
	const short barco5[5] = { '5','5','5','5','5' };
	const short barco6[6] = { '6','6','6','6','6','6' };

	std::cout<<coincidencia(2, 3, "tablero1");
}