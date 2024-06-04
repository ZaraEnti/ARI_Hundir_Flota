#include<iostream>
#include<string>
#include <cstdlib>
#include <time.h>

//Inicializaci�n 2 Tablas
const short tama�o = 10;

char tablero1[tama�o][tama�o];
char tablero2[tama�o][tama�o];

//Funci�n actualizar matriz
void actualizar(const short tama�o) {

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

//Funci�n coididencia de 1 casilla si es '~' o no. Fila, columna y nombre del tablero
bool coincidencia(short x, short y, std::string nombreTablero) {

	//Inicializaci�n de puntero
	char* puntero = NULL;

	//Comprobar que tablero del jugador apunta
	if (nombreTablero == "tablero1") {//correci�n de los magic numbers
		puntero = &tablero1[x][y];
	}
	else if (nombreTablero == "tablero2") {
		puntero = &tablero2[x][y];
	}
	else {//Si el nombre del tablero es diferente (A�adir otro jugador por ejemplo)
		std::cout << "No hay este tablero" << std::endl;
	}

	//Comprovaci�n de la casilla
	if (*puntero != '~') {
		return true;
	}
	else {
		return false;
	}
}

//Funci�n para verificar que hhay espacio para el barco
void verificar(short x, short y, char* puntero, std::string barco, std::string nombreTablero) {
	//Comprovbar primero si el origen es agua
	bool coicide = coincidencia(x, y, nombreTablero);
	while (coicide) {
		x = randNum();
		y = randNum();
		coicide = coincidencia(x, y, nombreTablero);
	}

	//Generar modo de orientaci�n aleatria
	bool orientacion = randOrientacion();

	//Si es verdadero es en vertivcal si es falso en borizontal
	if (orientacion) {//Vertical
		bool hayEspacio = modoV(y, barco);


		while (!hayEspacio) {//Vertical
			//llamar otra vez para que genere un origen nuvo y orientaci�n nueva
			verificar(x, y,puntero, barco, nombreTablero);

		}
	}
	else {//horizontal
		bool hayEspacio = modoH(x, barco);
		
		while (!hayEspacio) {
			verificar(x, y, puntero, barco, nombreTablero);
		}
	}


}

//Funci�n n�mero random rango del 0 a 9
short randNum() {
	srand(time(NULL));
	short num = rand() % 10;

	return num;
}

//Funci�n random orientaci�n 0 o 1. 0 para horizontal y 1 para vertical
bool randOrientacion() {
	srand(time(NULL));
	bool num = rand() % 1;

	return num;
}

//Funci�n insetar barcos
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

//Funci�n Comprobaci�n del espacio modo horizontal para cada barco
bool modoH(short x, std::string barco) {
	
	if (barco == "barco3") {
		if (x > 7) {
			return false;
		}
	}
	else if (barco == "barco4"){
		if (x > 6) {
			return false;
		}
	}else if(barco =="barco5") {
		if (x > 5) {
			return false;
		}
	
	} else {//barco6 es menor de este rango
		if (x > 4) {
			return false;
		}
	}
	return true;

}

//Funci�n Comprobaci�n Modo Vertical
bool modoV(short y, std::string barco) {

	if (barco == "barco3") {
		if (y > 7) {
			return false;
		}
	}
	else if (barco == "barco4") {
		if (y > 6) {
			return false;
		}
	}
	else if (barco == "barco5") {
		if (y > 5) {
			return false;
		}

	}
	else {//barco6 es menor de este rango
		if (y > 4) {
			return false;
		}
	}
	return true;
}

void main() {
	//Parte 1: Tablero
	// Valores de la tablas por defecto
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			tablero1[i][j] = '~';
			tablero2[i][j] = '~';
		}
	}
	//Mostrar tablero
	imprimir(tama�o);

	//Parte 2: Barcos
	//Inicializaci�n barcos a cada jugaddor 
	
	char barcosJugador1[4][6] = 
	{ { '3','3','3' },
	{ '4', '4', '4', '4' },
	{ '5', '5', '5', '5', '5' },
	{ '6', '6', '6', '6', '6', '6' } };

	char barcosJugador2[4][6] =
	{ { '3','3','3' },
	{ '4', '4', '4', '4' },
	{ '5', '5', '5', '5', '5' },
	{ '6', '6', '6', '6', '6', '6' } };
	
	//Generaci�n de dos n�meros aleatorios que sera el origen de la casilla
	short x = randNum();
	short y = randNum();
	
	
	//Orientaci�n de cada barco seguidamente comprovaci�n 
	for (short i = 0; i < 4; i++) {
		randOrientacion();
		if (randOrientacion()) {
			//vertical

		}
		else {
			//horizontal
		}
	}



	//Gameplay
	bool gameOver = false;
	while (!gameOver) {

	}
}