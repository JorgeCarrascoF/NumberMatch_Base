/*
 * pr_TADTablero.cpp
 *
 *  Created on: 30 dic. 2022
 *      Author: alumno
 */


#include "pr_TADTablero.h"

void pruebasTablero() {
	cout << "Inicio de las pruebas del TAD Tablero:" << endl;

	Tablero t;
	int filas, col;
	int ultimaFila, ultimaCol;
	VectorReplica v;
	int replicaAux, utilesAux;

	cout << "Prueba 1:" << endl;

	filas = 3;
	col = 3;


	iniciarTablero(t, filas, col);

	cout << "Matriz:" << endl;

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < col; j++) {
			cout << obtenerValor(t.m[i][j]) << " ";
		}
		cout << endl;
	}



	ultimaFila = devolverUltimaCeldaOcupada(t, ultimaCol);

	if(obtenerValor(t.m[filas-1][col-1]) != obtenerValor(t.m[ultimaFila][ultimaCol])) {
		cout << "Error al determinar la última celda ocupada." << endl;
		cout << "Coordenadas de la última celda ocupada: " << ultimaFila << ":" << ultimaCol << endl;
		cout << "Valor en esa coordenada: " << obtenerValor(t.m[ultimaFila][ultimaCol]) << endl;}


	ponerValorCelda(t, 0, 0, 1);
	ponerValorCelda(t, 1, 1, 2);
	ponerValorCelda(t, 2, 2, 4);

	if(obtenerValor(t.m[0][0]) != 1 ||
	   obtenerValor(t.m[1][1]) != 2 ||
	   obtenerValor(t.m[2][2]) != 4) {
		cout << "Error al modificar el valor de una celda." << endl;
	}

	borrar(t, 0, 0);
	borrar(t, 1, 1);
	borrar(t, 2, 2);

	if (!estaBorrada(t, 0, 0) ||
		!estaBorrada(t, 1, 1) ||
		!estaBorrada(t, 2, 2)) {
		cout << "Error al borrar una celda del tablero.";
	}

	ponerValorCelda(t, 0, 0, 2);
	ponerValorCelda(t, 1, 1, 2);
	ponerValorCelda(t, 1, 2, 8);

	if (!sonPareja(t, 0, 0, 1, 1) || !sonPareja(t, 1, 1, 1, 2)) {
		cout << "Error al determinar si dos celdas son pareja:" << endl;
		if(!sonPareja(t, 0, 0, 1, 1)) {
			cout << "Error al determinar la primera pareja: " << obtenerValor(t.m[0][0]) << " y " << obtenerValor(t.m[1][1]) << endl;
		} else if(!sonPareja(t, 1, 1, 1, 2)) {
			cout << "Error al determinar la segunda pareja: " << obtenerValor(t.m[1][1]) << " y " << obtenerValor(t.m[1][2]) << endl;
		}
	}

	borrar(t, 0, 0);
	borrar(t, 0, 1);
	borrar(t, 0, 2);

	if(!estaFilaBorrada(t, 0)){
		cout << "Error al determinar si una fila ha sido borrada." << endl;
	}

	cout << "Pruebas de borrado y replicado" << endl;

	iniciarTablero(t, filas, col);

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < col; j++) {
			cout << obtenerValor(t.m[i][j]) << " ";
		}
		cout << endl;
	}

	utilesAux = t.celdasUtiles;

	for(int j = 0; j < t.col; j++) {
		v[j] = t.m[1][j];
	}

	borrarFila(t, 0);

	cout << "Matriz tras borrar la fila 0" << endl;

	for (int i = 0; i <= t.ultimaCeldaFila; i++){
		for (int j = 0; j < col; j++) {
			cout << obtenerValor(t.m[i][j]) << " ";
		}
		cout << endl;
	}

	for(int j = 0; j < t.col; j++){
		if(obtenerValor(t.m[0][j])!= obtenerValor(v[j])){
			cout << "Error al borrar una fila de la matriz en el elemento: 0:" << j << endl;
		}
	}

	if(utilesAux-t.col != t.celdasUtiles) {
		cout << "Error al determinar cuántas celdas útiles quedan en la matriz" << endl;
	}

	replicaAux = t.celdasUtiles;

	replicarNoBorradas(t);

	cout << "Matriz tras replicar: " << endl;

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < col; j++) {
			cout << obtenerValor(t.m[i][j]) << " ";
		}
		cout << endl;
	}

	if(replicaAux*2 != t.celdasUtiles) {
		cout << "Error al replicar al determinar las celdas útiles de la matriz" << endl;
		cout << "Celdas útiles según el tablero: " << t.celdasUtiles << endl;
		cout << "Celdas útiles que debería haber: " << replicaAux*2 << endl;
	}

	cout << "Prueba 2:" << endl;

	filas = 5;
	col = 5;


	iniciarTablero(t, filas, col);

	cout << "Matriz:" << endl;

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < col; j++) {
			cout << obtenerValor(t.m[i][j]) << " ";
		}
		cout << endl;
	}



	ultimaFila = devolverUltimaCeldaOcupada(t, ultimaCol);

	if(obtenerValor(t.m[filas-1][col-1]) != obtenerValor(t.m[ultimaFila][ultimaCol])) {
		cout << "Error al determinar la última celda ocupada." << endl;
		cout << "Coordenadas de la última celda ocupada: " << ultimaFila << ":" << ultimaCol << endl;
		cout << "Valor en esa coordenada: " << obtenerValor(t.m[ultimaFila][ultimaCol]) << endl;}


	ponerValorCelda(t, 4, 4, 7);
	ponerValorCelda(t, 3, 1, 2);
	ponerValorCelda(t, 1, 5, 4);

	if(obtenerValor(t.m[4][4]) != 7 ||
	   obtenerValor(t.m[3][1]) != 2 ||
	   obtenerValor(t.m[1][5]) != 4) {
		cout << "Error al modificar el valor de una celda." << endl;
	}

	borrar(t, 0, 0);
	borrar(t, 2, 4);
	borrar(t, 4, 3);

	if (!estaBorrada(t, 0, 0) ||
		!estaBorrada(t, 2, 4) ||
		!estaBorrada(t, 4, 3)) {
		cout << "Error al borrar una celda del tablero.";
	}

	ponerValorCelda(t, 0, 0, 2);
	ponerValorCelda(t, 1, 1, 2);
	ponerValorCelda(t, 1, 2, 8);

	if (!sonPareja(t, 0, 0, 1, 1) || !sonPareja(t, 1, 1, 1, 2)) {
		cout << "Error al determinar si dos celdas son pareja:" << endl;
		if(!sonPareja(t, 0, 0, 1, 1)) {
			cout << "Error al determinar la primera pareja: " << obtenerValor(t.m[0][0]) << " y " << obtenerValor(t.m[1][1]) << endl;
		} else if(!sonPareja(t, 1, 1, 1, 2)) {
			cout << "Error al determinar la segunda pareja: " << obtenerValor(t.m[1][1]) << " y " << obtenerValor(t.m[1][2]) << endl;
		}
	}

	borrar(t, 0, 0);
	borrar(t, 0, 1);
	borrar(t, 0, 2);
	borrar(t, 0, 3);
	borrar(t, 0, 4);

	if(!estaFilaBorrada(t, 0)){
		cout << "Error al determinar si una fila ha sido borrada." << endl;
	}

	cout << "Pruebas de borrado y replicado" << endl;

	iniciarTablero(t, filas, col);

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < col; j++) {
			cout << obtenerValor(t.m[i][j]) << " ";
		}
		cout << endl;
	}

	utilesAux = t.celdasUtiles;

	for(int j = 0; j < t.col; j++) {
		v[j] = t.m[1][j];
	}

	borrarFila(t, 0);

	cout << "Matriz tras borrar la fila 0" << endl;

	for (int i = 0; i <= t.ultimaCeldaFila; i++){
		for (int j = 0; j < col; j++) {
			cout << obtenerValor(t.m[i][j]) << " ";
		}
		cout << endl;
	}

	for(int j = 0; j < t.col; j++){
		if(obtenerValor(t.m[0][j])!= obtenerValor(v[j])){
			cout << "Error al borrar una fila de la matriz en el elemento: 0:" << j << endl;
		}
	}

	if(utilesAux-t.col != t.celdasUtiles) {
		cout << "Error al determinar cuántas celdas útiles quedan en la matriz" << endl;
	}

	replicaAux = t.celdasUtiles;

	replicarNoBorradas(t);

	cout << "Matriz tras replicar: " << endl;

	for (int i = 0; i <= t.ultimaCeldaFila; i++){
		for (int j = 0; j < col; j++) {
			cout << obtenerValor(t.m[i][j]) << " ";
		}
		cout << endl;
	}

	if(replicaAux*2 != t.celdasUtiles) {
		cout << "Error al replicar al determinar las celdas útiles de la matriz" << endl;
		cout << "Celdas útiles según el tablero: " << t.celdasUtiles << endl;
		cout << "Celdas útiles que debería haber: " << replicaAux*2 << endl;
	}



	cout << "Fin de las pruebas del TAD Tablero." << endl;

}

