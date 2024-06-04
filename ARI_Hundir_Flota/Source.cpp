#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>

//Inicializaci�n 2 Tablas para la colocaci�n de los barcos
const short tama�o = 10;

//2 tablero par los barcos
char tablero1[tama�o][tama�o];
char tablero2[tama�o][tama�o];

//2 tableros de los jugadores
char tableroJugador1[tama�o][tama�o];
char tableroJugador2[tama�o][tama�o];

//Funci�n imprimir tableros
void imprimir(const short tama�o, std::string nombretablero) {
	//Para imprimir el tablero que contiene los barcos
	if (nombretablero == "tablero1" || nombretablero == "tablero2") {
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
	//Para imprimir el tablero de los jugadores durante el juego
	if (nombretablero == "tableroJugador1" || nombretablero == "tableroJugador2") {
		std::cout << "Tablero jugador 1" << std::endl;
		for (short i = 0; i < tama�o; i++) {
			for (short j = 0; j < tama�o; j++) {
				std::cout << " " << tableroJugador1[i][j];

			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "Tablero jugador 2" << std::endl;
		for (short i = 0; i < tama�o; i++) {
			for (short j = 0; j < tama�o; j++) {
				std::cout << " " << tableroJugador2[i][j];

			}
			std::cout << std::endl;
		}
	}
	
}


//Funci�n n�mero random rango del 0 a 9
short randNum() {

	short num = rand() % 10;

	return num;
}

//Funci�n random orientaci�n 0 o 1. 0 para horizontal y 1 para vertical
bool randOrientacion() {
	bool num = rand() % 2;

	return num;
}


//Funci�n coididencia de 1 casilla si es '~' o no. Fila, columna y nombre del tablero
bool coincidencia(short x, short y, std::string nombreTablero) {

	char* puntero = NULL;
	//Comprobar que tablero del jugador apunta
	if (nombreTablero == "tablero1") {//correci�n de los magic numbers
		puntero = &tablero1[x][y];
	}
	else if (nombreTablero == "tablero2") {
		puntero = &tablero2[x][y];
	}
	
	//Aciertos de los barcos
	if (nombreTablero == "tableroJugador1") {//correci�n de los magic numbers
		puntero = &tablero1[x][y];//Tiene que ser el tablero del contricante
	}
	else if (nombreTablero == "tableroJugador2") {
		puntero = &tablero2[x][y];
	}


	//Comprovaci�n de la casilla
	if (*puntero != '~') {
		return true;
	}
	else {
		return false;
	}
}

//Funci�n Comprobaci�n del espacio modo horizontal para cada barco
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

//Funci�n Comprobaci�n Modo Vertical
bool modoV(short y, std::string barco) {

	if (barco == "barco3") {
		
		if (y >7) {
			
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
//Funci�n para verificar que hhay espacio para el barco
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
			
				if (!(tablero1[i][x] == '~')) {
					return false;
				}
			}

		}
		else if (nombreTablero == "tablero2") {
			for (short i = y; i < (y + longBarco); i++) {
				if (!(tablero2[i][x] == '~')) {
					return false;
				}
			}
			
		}

	}
	else {//Vertificaci�n horizontal

		if (nombreTablero == "tablero1") {
			for (short i = x; i < (x + longBarco); i++) {
				if (!(tablero1[y][i] == '~')) {
					return false;
				}
				
			}
			
		}
		else if (nombreTablero == "tablero2") {
			for (short i = x; i < (x + longBarco); i++) {
				if (!(tablero2[y][i] == '~')) {
					return false;
				}
			}
			
		}
	}
	return true;
}


//Funci�n insetar barcos
void insertarBarcos(short x, short y, std::string nombreTablero, std::string barco, bool modoInsercci�n) {
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

	char var = longBarco+0x30;//para convertir en char ya que los barcos tienen sus propios n�meros

	//Cual tablero hay que insertar
	if (nombreTablero == "tablero1") {
		
		if (modoInsercci�n) {//Modo vertical
			for (short i = y; i < (y + longBarco); i++) {
				
				tablero1[i][x] = var;//podemos hacer lo ash� porque coicide con el valor del barco
			}
		}
		else {//Modo horizontal
			for (short j = x; j < (x + longBarco); j++) {

				tablero1[y][j] = var;//podemos hacer lo ash� porque coicide con el valor del barco
				
			}
		}



	}
	else if (nombreTablero == "tablero2") {

		if (modoInsercci�n) {
			for (short i = y; i < y + longBarco; i++) {

				tablero2[i][x] = var;//podemos hacer lo ash� porque coicide con el valor del barco
				
			}
		}
		else {
			for (short j = x; j < x + longBarco; j++) {

				tablero2[y][j] = var;//podemos hacer lo ash� porque coicide con el valor del barco
				
			}

		}

	}
	else {//Si el nombre del tablero es diferente (A�adir otro jugador por ejemplo)
		std::cout << "No hay este tablero" << std::endl;
	}

}
void ponerBarcosJugadores(std::string barco, std::string nombreTabla) {
	//Generaci�n de dos n�meros aleatorios que sera el origen de la casilla
	short x = randNum();
	short y = randNum();
	

	//Vertidficar que se puede poner el barco
	bool sePuedePoner;

		//Confirmar que la casilla origen tomada es agua
		bool coicide = coincidencia(x, y, nombreTabla);
		while (coicide)
		{
			x = randNum();
			y = randNum();
			coicide = coincidencia(x, y, nombreTabla);
		}

		//Generara orientaci�n
		bool orientacion = randOrientacion();

		if (orientacion) {//vertical
			bool hayEspacio = modoV(y, barco);

			if (hayEspacio) {
				sePuedePoner = verificar(x, y, barco, nombreTabla, orientacion);
				if (sePuedePoner) {
					insertarBarcos(x, y, nombreTabla, barco, orientacion);
				}else{
					ponerBarcosJugadores(barco,nombreTabla);
				}
			}
			else {
				ponerBarcosJugadores(barco, nombreTabla);
			}
			
		}
		else {//Horizontal
			bool hayEspacio = modoH(x, barco);
			
			if (hayEspacio) {
				sePuedePoner = verificar(x, y, barco, nombreTabla, orientacion);
				if (sePuedePoner) {
					insertarBarcos(x, y, nombreTabla, barco, orientacion);
				}
				else {
					ponerBarcosJugadores(barco, nombreTabla);
				}
			}
			else {
				ponerBarcosJugadores(barco, nombreTabla);
			}
		}
	

}
//Funci�n para saber quien gana la partida
bool win(std::string nombreTablero) {
	if (nombreTablero == "tableroJugador1") {
		for (short i = 0; i < tama�o; i++) {
			for (short j = 0; j < tama�o; j++) {

				if ((tableroJugador1[i][j] != '~') || (tableroJugador1[i][j] != 'O') || (tableroJugador1[i][j] != 'X')) {
					return false;
				}
			}
		}
		std::cout << "enorabuena jugador 2 has ganado!!" << std::endl;
		
	}
	else (nombreTablero == "tableroJugador2") {
		for (short i = 0; i < tama�o; i++) {
			for (short j = 0; j < tama�o; j++) {

				if ((tableroJugador2[i][j] != '~') || (tableroJugador2[i][j] != 'O') || (tableroJugador2[i][j] != 'X')) {
					return false;
				}
			}
			std::cout << "enorabuena jugador 1 has ganado!!" << std::endl;
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
	imprimir(tama�o, "tablero1");

	//Parte 2: Barcos
	//Inicializaci�n barcos a cada jugaddor 
	srand(std::time(NULL));//Ponemos la semilla para que nos de diferentes resultados seg�n transcure el tiempo dando valores diferentes

	ponerBarcosJugadores("barco3", "tablero1");
	ponerBarcosJugadores("barco4", "tablero1");
	ponerBarcosJugadores("barco5", "tablero1");
	ponerBarcosJugadores("barco6", "tablero1");
	
	ponerBarcosJugadores("barco3", "tablero2");
	ponerBarcosJugadores("barco4", "tablero2");
	ponerBarcosJugadores("barco5", "tablero2");
	ponerBarcosJugadores("barco6", "tablero2");
	
	imprimir(tama�o, "tablero1");


	//Gameplay
	bool gameOver = false;
	bool turno = true; //true para jugado 1 false para jugador 2
	

	

	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			tableroJugador1[i][j] = '~';
			tableroJugador2[i][j] = '~';
		}
	}
	
	while (!gameOver) {
		
		short x, y;
		//Jugador 1
		if (turno) {
			//Introducir las posiciones de las casillas
			std::cout << "Jugador 1" << std::endl;
			std::cout<<"Introduce la fila" << std::endl;
			std::cin >> x;

			std::cout << "Introduce columna" << std::endl;
			std::cin >> y;
			
			//Comprobaci�n de la casilla si es agua o barco
			bool acierto = coincidencia(x, y, "tableroJugador2");
			
			
			if(acierto) {
				//Insertar si es barco 
				tableroJugador2[x][y] = '0';
			}
			else {
				//Insertar si es agua
				tableroJugador2[x][y] = 'X';	
			}
			imprimir(tama�o, "tableroJugador1");

			//Comprobaci�n que que no quede ning�un barco del jugador contrario
			gameOver = win("tableroJugador2");
			
			//cambiar turno
			turno ? turno = false : turno = true;
		}
		else {//Turno del jugador 2
			std::cout << "Jugador 2" << std::endl;
			std::cout << "Introduce la fila" << std::endl;
			std::cin >> x;

			std::cout << "Introduce columna" << std::endl;
			std::cin >> y;
			
			bool acierto = coincidencia(x, y, "tableroJugador1");
			if (acierto) {
				tableroJugador1[x][y] = '0';
			}
			else {
				tableroJugador1[x][y] = 'X';
			}
			imprimir(tama�o, "tableroJugador2");

			//Verificar si el jugador 1 es derrotado
			gameOver = win("tableroJugador1");
			//Para cambiar el turno
			turno ? turno = false : turno = true;
		}




	}
}