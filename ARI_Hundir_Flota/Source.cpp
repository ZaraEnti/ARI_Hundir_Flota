#include<iostream>
#include<string>
#include <cstdlib>
#include <time.h>

//Inicializaci�n 2 Tablas
const short tama�o = 10;

char tablero1[tama�o][tama�o];
char tablero2[tama�o][tama�o];

//No hace falta porque crearemos dos punteros
//Numero de la tabla para elejir la tabla en la que sequiere trabajar
short numTabla = 1;

//Inicializaci�n de los punteros en sus respectivos matrices que pasaran como par�metro para las funciones
//Inicialiazaci�n de punteros globales para las dos matrices
char* puntero = NULL;

//Funci�n actualizar matriz
void actualizar(const short tama�o) {

	//Comprobar 
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {


		}
	}
}

//Funci�n imprimir tableros
void imprimir(const short tama�o) {
	std::cout << "Tablero jugador 1" << std::endl;
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			std::cout << " " << tablero1[i][j];

		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Tablero jugador 2" << std::endl;
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			std::cout << " " << tablero2[i][j];

		}
		std::cout << std::endl;
	}
}

//Coididencia de barcos; numero tabla, fila, columna, puntero
bool coincidencia(short numTabla, short x, short y, char* puntero) {

	if (numTabla == 1) {//correci�n de los magic numbers
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

//Funci�n para verificar
void verificar(short x, short y, char* puntero) {

}

//funci�n n�mero random
short randNum() {
	srand(time(NULL));
	short num = rand() % 10;//rango 0 a 9

	return num;
}

//funci�n random orientaci�n
bool randOrientacion() {
	srand(time(NULL));
	bool num = rand() % 1;//rango 0 a 1

	return num;
}

//funci�n insetar barcos
void insertarBarcos() {
	char posicionInicial[2];

	//convertimos los n�meros aleatorios en char
	posicionInicial[0] = (char)randNum();
	posicionInicial[1] = (char)randNum();

	//orientaci�n TRUE para Horizontal
	if (randOrientacion()) {

	}
	else {//false para la orietacion vertival

	}

}

//Modo Horizontal
void modoH(char nombreTabla[tama�o][tama�o]) {
	char* puntero;

	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			puntero = &nombreTabla[i][j];

		}
	}
}

//Modo Vertical
void modoV(char nombreTabla[tama�o][tama�o]) {
	char* puntero;

	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			puntero = &nombreTabla[i][j];
			j = tama�o - 1;//saltarse las filas
		}
	}
}

void main() {
	//Parte 1: Tablero
	// Valores de la tablas por defeceto
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			tablero1[i][j] = '~';
			tablero2[i][j] = '~';
		}
	}

	imprimir(tama�o);

	//Parte 2: Barcos
	//Inicializaci�n barcos
	const short barco3[3] = { '3','3','3' };
	const short barco4[4] = { '4','4','4','4' };
	const short barco5[5] = { '5','5','5','5','5' };
	const short barco6[6] = { '6','6','6','6','6','6' };

}