#include<iostream>
#include<string>
#include <time.h>

//Inicialización 2 Tablas
const short tamaño = 10;
char tablero1[tamaño][tamaño];
char tablero2[tamaño][tamaño];


//Función actualizar matriz
void actualizar(const short tamaño) {

	//Comprobar 
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {


		}
	}
}
//Función imprimir
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
//Función de verificación de los barcos antes de insertar
void verificar() {

}

//Coididencia de barcos
bool coicidencia(short x, short y) {

	//Iniciar puntero
	char* punteroTabla;

	//Para quitar la coicidencia de los barcos
	punteroTabla = &tablero1[x][y];//asignar dirrección
	if (*punteroTabla != '~') {
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
	char barco[2];

	//convertimos los números aleatorios en char
	barco[0] = (char)randNum();
	barco[1] = (char)randNum();
	//orientación TRUE para Horizontal
	if (randOrientacion()) {

	}
	else {//false para la orietacion vertival

	}

}

//Insertar de manera horizontal
void modoH(char nomTablero, short* posicionBarco, short* nombreBarco, short tamaño) {
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			if (i == posicionBarco[i] && j == i == posicionBarco[j]) {

			}

		}
	}
}

//Insertar de la manera vertical
void modoV(short* posicionBarco, short* nombreBarco) {
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			tablero1[i][j] = '~';
			tablero2[i][j] = '~';
		}
	}
}

void main() {
	// Valores de la tablas por defecto
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

}