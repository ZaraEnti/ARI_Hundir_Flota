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
	else if (nombreTablero == "tablero2") {
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

//Función para verificar que hhay espacio para el barco
void verificar(short x, short y, char* puntero, std::string barco, std::string nombreTablero, short* punteroOrigenX, short* punteroOrigenY) {
	
	//Comprovbar primero si el origen es agua
	bool coicide = coincidencia(x, y, nombreTablero);
	while (coicide) {
		x = randNum();
		y = randNum();
		coicide = coincidencia(x, y, nombreTablero);
	}

	//Generar modo de orientación aleatoria
	bool orientacion = randOrientacion();

	//Si es verdadero es en vertivcal si es falso en borizontal
	if (orientacion) {//Vertical
		bool hayEspacio = modoV(y, barco);


		while (!hayEspacio) {//Vertical
			//llamar otra vez para que genere un origen nuvo y orientación nueva
			verificar(x, y,puntero, barco, nombreTablero, punteroOrigenX, punteroOrigenY);

		}

		//Modificación de los valores de origen en el main si hubo un cambio de origen
		*punteroOrigenX = x;
		*punteroOrigenY = y;
	}
	else {//horizontal
		bool hayEspacio = modoH(x, barco);
		
		while (!hayEspacio) {
			verificar(x, y, puntero, barco, nombreTablero, punteroOrigenX, punteroOrigenY);
		}

		//Modificación de los valores de origen en el main si hubo un cambio de origen
		*punteroOrigenX = x;
		*punteroOrigenY = y;
	}


}

//Función número random rango del 0 a 9
short randNum() {
	srand(time(NULL));
	short num = rand() % 10;

	return num;
}

//Función random orientación 0 o 1. 0 para horizontal y 1 para vertical
bool randOrientacion() {
	srand(time(NULL));
	bool num = rand() % 1;

	return num;
}

//Función insetar barcos
void insertarBarcos(short x, short y, char*puntero) {
	

}

//Función Comprobación del espacio modo horizontal para cada barco
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

//Función Comprobación Modo Vertical
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
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {
			tablero1[i][j] = '~';
			tablero2[i][j] = '~';
		}
	}
	//Mostrar tablero
	imprimir(tamaño);

	//Parte 2: Barcos
	//Inicialización barcos a cada jugaddor 
	
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
	
	//Generación de dos números aleatorios que sera el origen de la casilla
	short x = randNum();
	short y = randNum();

	//Asignación de puntero para cambiar el valor del origen en la función main()
	short* punteroOrigenX =&x;
	short* punteroOrigenY =&y;
	
	//Verificación de los 4 barcos



	//Gameplay
	bool gameOver = false;
	while (!gameOver) {

	}
}