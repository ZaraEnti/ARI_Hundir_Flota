#include<iostream>
#include<string>
#include <time.h>
//Inicializaci�n 2 Tablas
const short tama�o = 10;
char tablero1[tama�o][tama�o];
char tablero2[tama�o][tama�o];

//Funci�n actualizar matriz
void actualizar(const short tama�o) {

	//Comprobar 
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {

			
		}
	}
}
//Funci�n imprimir
void imprimir(const short tama�o) {
	std::cout << "Tablero jugador 1" << std::endl;
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			std::cout << " " << tablero1[i][j];

		}
		std::cout<<std::endl;
	}

	std::cout << std::endl;

	std::cout << "Tablero jugador 2" << std::endl;
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			std::cout << " " << tablero2[i][j];

		}
		std::cout<<std::endl;
	}
}
//Funci�n de verificaci�n de los barcos antes de insertar
bool verificar() {
	
}
//funci�n n�mero random
short randNum() {
	srand(time(NULL));
	short num  = rand() % 10;//rango 0 a 9
	
	return num;
}
//funci�n random orientaci�n
bool randOrientacion() {
	srand(time(NULL));
	bool num = rand() % 1;//rango 0 a 1

	return num;
}
//funci�n insetar barcos
void insertarBarcos(){
	char barco[2];

	//convertimos los n�meros aleatorios en char
	barco[0] = (char)randNum();
	barco[1] = (char)randNum();
	//orientaci�n TRUE para Horizontal
	if (randOrientacion()) {

	}
	else {//false para la orietacion vertival

	}

}

void main() {
	// Valores de la tablas por defecto
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {
			tablero1[i][j] = '~';
			tablero2[i][j] = '~';
		}
	}

	imprimir(tama�o);

	//Inicializaci�n barcos
	const short barco3[3] = {'3','3','3'};
	const short barco4[4] = {'4','4','4','4'};
	const short barco5[5] = {'5','5','5','5','5'};
	const short barco6[6] = {'6','6','6','6','6','6'};

}