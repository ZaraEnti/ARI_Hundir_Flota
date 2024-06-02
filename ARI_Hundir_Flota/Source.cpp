#include<iostream>
#include<string>
#include <stdlib.h> 
#include <time.h>

//Inicialización 2 Tablas
const short tamaño = 10;

char tablero1[tamaño][tamaño];
char tablero2[tamaño][tamaño];

//Numero de la tabla para elejir la tabla en la que sequiere trabajar
short numTabla;

//Inicialiazación de punteros globales para las dos matrices
char* puntero=NULL;


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
bool coincidencia(short numTabla, short x, short y, char *puntero) {
	
	if (numTabla == 1) {
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
			j = tamaño-1;//saltarse las filas
		}
	}
}

void main() {
	// Valores de la tablas por defeceto
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			tablero1[i][j] = '~';
			tablero2[i][j] = '~';
		}
	}

	imprimir(tamaño);

	//Inicialización barcos
	const short barco3[3] = { '3','3','3' };
	const short barco4[4] = { '4','4','4','4' };
	const short barco5[5] = { '5','5','5','5','5' };
	const short barco6[6] = { '6','6','6','6','6','6' };
	
	std::cout << coincidencia(1,2,6, puntero);
}