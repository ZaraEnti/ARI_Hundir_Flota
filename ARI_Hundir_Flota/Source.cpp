#include<iostream>
#include<string>

//Inicializaci�n 2 Tablas
const short tama�o = 10;
char tablero1[tama�o][tama�o];
char tablero2[tama�o][tama�o];

//Funci�n actualizar matriz
void insertar(char valor, std::string nombreTabla, const short tama�o) {
	for (short i = 0; i < tama�o; i++) {
		for (short j = 0; j < tama�o; j++) {

			//Selecci�nado que tabla queremos actualizar
			if (nombreTabla == "tablero1") {

			}
			else {

			}
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