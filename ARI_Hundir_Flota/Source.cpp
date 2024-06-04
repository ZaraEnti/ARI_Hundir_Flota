#include<iostream>
#include<string>
#include <stdlib.h>
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


//Función número random rango del 0 a 9
short randNum() {

	short num = rand() % 10;

	return num;
}

//Función random orientación 0 o 1. 0 para horizontal y 1 para vertical
bool randOrientacion() {
	srand(time(NULL));
	bool num = rand() % 1;

	return num;
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

//Función Comprobación del espacio modo horizontal para cada barco
bool modoH(short x, std::string barco) {

	if (barco == "barco3") {
		if (x > 7) {
			return false;
		}
	}
	else if (barco == "barco4") {
		if (x > 6) {
			return false;
		}
	}
	else if (barco == "barco5") {
		if (x > 5) {
			return false;
		}

	}
	else {//barco6 es menor de este rango
		if (x > 4) {
			return false;
		}
	}
	return true;

}

//Función Comprobación Modo Vertical
bool modoV(short y, std::string barco) {

	if (barco == "barco3") {
		std::cout << "dentro barco 3" << std::endl;
		if (y > 7) {
			std::cout << "no cabe el barco 3 en la tabla" << std::endl;
			return false;
		}
	}
	else if (barco == "barco4") {
		if (y > 6) {
			return false;
			std::cout << "no cabe el barco 4 en la tabla" << std::endl;
		}
	}
	else if (barco == "barco5") {
		if (y > 5) {
			return false;
			std::cout << "no cabe el barco 5 en la tabla" << std::endl;
		}

	}
	else {//barco6 es menor de este rango
		if (y > 4) {
			return false;
			std::cout << "no cabe el barco 6 en la tabla" << std::endl;
		}
	}
	return true;
}
//Función para verificar que hhay espacio para el barco
bool verificar(short x, short y, std::string barco, std::string nombreTablero, bool orientacion) {

	short longBarco;
	//Para saber la longitud del barco
	if (barco == "barco3") {
		longBarco = 3;
	}
	else if (barco == "barco4") {
		longBarco = 4;
	}
	else if (barco == "barco5") {
		longBarco = 5;
	}
	else {//barco6 es menor de este rango
		longBarco = 6;
	}

	//Si es verdadero es en vertivcal si es falso en borizontal
	if (orientacion) {//Vertical
		if (nombreTablero == "tablero1") {

			for (short i = y; i < (y + longBarco); i++) {
				std::cout << "comprobando si se puede";
				if (!tablero1[i][x] == '~') {
					return false;
				}
			}
		}
		else if (nombreTablero == "tablero2") {
			for (short i = y; i < (y + longBarco); i++) {
				std::cout << "comprobando si se puede";
				if (!tablero2[i][x] == '~') {
					return false;
				}
			}
		}
		else {//Si el nombre del tablero es diferente (Añadir otro jugador por ejemplo)
			std::cout << "No hay este tablero" << std::endl;
		}

	}
	else {//horizontal

		if (nombreTablero == "tablero1") {
			for (short i = x; i < (x + longBarco); i++) {
				std::cout << "comprobando si se puede";
				if (!tablero1[y][i] == '~') {
					return false;
				}
			}
		}
		else if (nombreTablero == "tablero2") {
			for (short i = x; i < (x + longBarco); i++) {
				std::cout << "comprobando si se puede";
				if (!tablero2[y][i] == '~') {
					return false;
				}
			}
		}
		else {//Si el nombre del tablero es diferente (Añadir otro jugador por ejemplo)
			std::cout << "No hay este tablero" << std::endl;
		}


	}


}


//Función insetar barcos
void insertarBarcos(short x, short y, std::string nombreTablero, std::string barco, bool modoInsercción) {
	short longBarco;

	//Para saber la longitud del barco
	if (barco == "barco3") {
		longBarco = 3;
	}
	else if (barco == "barco4") {
		longBarco = 4;
	}
	else if (barco == "barco5") {
		longBarco = 5;
	}
	else {//barco6 es menor de este rango
		longBarco = 6;
	}

	//Cual tablero hay que insertar
	if (nombreTablero == "tablero1") {

		if (modoInsercción) {
			for (short i = y; i < y + longBarco; i++) {

				tablero1[i][x] = (char)longBarco;//podemos hacer lo ashí porque coicide con el valor del barco
				std::cout << tablero1[i][x];
			}
		}
		else {
			for (short j = x; j < x + longBarco; j++) {

				tablero1[y][j] = (char)longBarco;//podemos hacer lo ashí porque coicide con el valor del barco
				std::cout << tablero1[y][j];
			}
		}



	}
	else if (nombreTablero == "tablero2") {

		if (modoInsercción) {
			for (short i = y; i < y + longBarco; i++) {

				tablero2[i][x] = (char)longBarco;//podemos hacer lo ashí porque coicide con el valor del barco
				std::cout << tablero2[i][x];
			}
		}
		else {
			for (short j = x; j < x + longBarco; j++) {

				tablero2[y][j] = (char)longBarco;//podemos hacer lo ashí porque coicide con el valor del barco
				std::cout << tablero2[y][j];
			}

		}

	}
	else {//Si el nombre del tablero es diferente (Añadir otro jugador por ejemplo)
		std::cout << "No hay este tablero" << std::endl;
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
	srand(time(NULL));//Ponemos la semilla para que nos de diferentes resultados según transcure el tiempo dando valores diferentes
	short x = randNum();
	short y = randNum();
	std::cout << "Numero rand x: " << x << std::endl;
	std::cout << "Numero rand y: " << y << std::endl;

	//Confirmar que la casilla tomada es agua
	bool coicide = coincidencia(x, y, "tablero1");
	while (coicide)
	{
		x = randNum();
		y = randNum();
	}
	//Generara orientación
	bool orientacion = randOrientacion();
	if (orientacion) {//vertical
		bool hayEspacio = modoV(y, "barco1");

		while (!hayEspacio)
		{
			y = randNum();
			hayEspacio = modoV(y, "barco1");
		}
	}
	else {//Horizontal
		bool hayEspacio = modoH(x, "barco1");

		while (!hayEspacio)
		{
			x = randNum();
			hayEspacio = modoV(x, "barco1");
		}
	}


	imprimir(tamaño);



	//Gameplay
	//bool gameOver = false;
	//while (!gameOver) {

	//}
}