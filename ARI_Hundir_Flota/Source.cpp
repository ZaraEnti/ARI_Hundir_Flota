#include<iostream>
#include<string>
#include <cstdlib>
#include <time.h>

//Inicialización 2 Tablas
const short tamaño = 10;

char tablero1[tamaño][tamaño];
char tablero2[tamaño][tamaño];

//No hace falta porque crearemos dos punteros
//Numero de la tabla para elejir la tabla en la que sequiere trabajar
short numTabla = 1;

//Inicialización de los punteros en sus respectivos matrices que pasaran como parámetro para las funciones
//Inicialiazación de punteros globales para las dos matrices
char* puntero = NULL;

//Función actualizar matriz
void actualizar(const short tamaño) {

	//Comprobar 
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

//Coididencia de barcos; numero tabla, fila, columna, puntero
bool coincidencia(short numTabla, short x, short y, char* puntero) {

	if (numTabla == 1) {//correción de los magic numbers
		puntero = &tablero1[x][y];
	}
	else {
		puntero = &tablero2[x][y];
	}

	//Para quitar la coicidencia de los barcos
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
	// Valores de la tablas por defeceto
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			tablero1[i][j] = '~';
			tablero2[i][j] = '~';
		}
	}

	imprimir(tamaño);

	//Parte 2: Barcos
	//Inicialización barcos
	const short barco3[3] = { '3','3','3' };
	const short barco4[4] = { '4','4','4','4' };
	const short barco5[5] = { '5','5','5','5','5' };
	const short barco6[6] = { '6','6','6','6','6','6' };

}