#include<iostream>
#include<string>


//Función actualizar matriz
void insertar(char valor, std::string nombreTabla, const short tamaño) {
	for (short i = 0; i < tamaño; i++) {
		for (short j = 0; j < tamaño; j++) {

			//Selecciónado que tabla queremos actualizar
			if (nombreTabla == "tablero1") {

			}
			else {

			}
		}
	}
}

//Función imprimir
void imprimir(std::string nombreTablero, const short tamaño) {
	for (short i = 0; i < tamaño; i++) {

	}
}


void main() {

	//Inicialización 2 Tablas
	const short tamaño = 10;
	char tablero1[tamaño][tamaño];
	char tablero2[tamaño][tamaño];

	// Valores de la tablas por defecto
		for (short i = 0; i < tamaño; i++) {
			for (short j = 0; j < tamaño; j++) {
				tablero1[i][j] = '~';
				tablero2[i][j] = '~';
			}
		}

}