#include<iostream>
#include<string>


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
void imprimir(std::string nombreTablero, const short tama�o) {
	for (short i = 0; i < tama�o; i++) {

	}
}


void main() {

	//Inicializaci�n 2 Tablas
	const short tama�o = 10;
	char tablero1[tama�o][tama�o];
	char tablero2[tama�o][tama�o];

	// Valores de la tablas por defecto
		for (short i = 0; i < tama�o; i++) {
			for (short j = 0; j < tama�o; j++) {
				tablero1[i][j] = '~';
				tablero2[i][j] = '~';
			}
		}

}