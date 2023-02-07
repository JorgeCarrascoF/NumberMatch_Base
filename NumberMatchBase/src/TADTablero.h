/*
 * TADTablero.h
 *
 *  Created on: 28 dic. 2022
 *      Author: Jorge Carrasco Facundo
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_


#include <iostream>
#include <string>
#include <cmath>
#include "TADCelda.h"
#include "entorno.h"

const int MAXFILAS = 12;
const int MAXCOL = 9;

typedef Celda Matriz[MAXFILAS][MAXCOL];
typedef Celda VectorReplica[MAXFILAS*MAXCOL];

/*El tamaño del vector podría reducirse, ya que nunca vamos a replicar más de la
mitad de la matriz */

struct Tablero {
	Matriz m;
	int filas;
	int col;
	int ultimaCeldaFila;
	int ultimaCeldaCol;
	int celdasUtiles;
};

using namespace std;

// PRE {Tablero t,  13 > int filasIniciales > 0, 10 > int colIniciales > 0}
// POST {Inicia el tablero con valores de celda aleatorios entre 1 y 9}
// Complejidad: O(n²)
void iniciarTablero(Tablero &t, int filasIniciales, int colIniciales);

// PRE {Tablero t}
// POST {Devuelve las filas y columnas de la matriz}
// Complejidad: O(1)
int devolverFilasColumnas(Tablero t, int &col);

// PRE {Tablero t}
// POST {Devuelve las coordenadas de la última celda ocupada}
// Complejidad: O(1)
int devolverUltimaCeldaOcupada(Tablero t, int &col);

// PRE {Tablero t, int i <= t.filas, int j <= t.col}
// POST {Devuelve el valor de una celda concreta}
// Complejidad: O(1)
int obtenerValorCelda(Tablero t, int i, int j);

// PRE {Tablero t, int i <= t.filas, int j <= t.col, 10 > int num > 0}
// POST {Pone el valor num en la celda que ocupa las coordenadas [i][j]}
// Complejidad: O(1)
void ponerValorCelda(Tablero &t, int i, int j, int num);

// PRE {Tablero t}
// POST {Borra la celda de las coordenadas dadas}
// Complejidad: O(1)
void borrar(Tablero &t, int i, int j);

// PRE {Tablero t, int i <= t.filas, int j <= t.col}
// POST {Devuelve true si la celda está borrada}
// Complejidad: O(1)
bool estaBorrada(Tablero t, int i, int j);

// PRE {Tablero t, int i <= t.filas, int j <= t.col, int m <= t.filas, int m <= t.col}
// POST {Devuelve true si las celdas son pareja}
// Complejidad: O(1)
bool sonPareja(Tablero t, int i, int j, int k, int m);

// PRE {Tablero t, int i <= t.filas}
// POST {Devuelve true si todas las celdas de la fila están borradas}
// Complejidad: O(n)
bool estaFilaBorrada(Tablero t, int i);

// PRE {Tablero t, int i <= t.filas}
// POST {Borra la fila i de la matriz}
// Complejidad: O(n²)
void borrarFila(Tablero &t, int i);

// PRE {Tablero t, int i <= t.filas, int j <= t.col}
// POST {Copia los números no borrados al final de la matriz}
// Complejidad: O(n²)
void replicarNoBorradas(Tablero &t);


#endif /* TADTABLERO_H_ */
