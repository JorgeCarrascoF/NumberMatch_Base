/*
 * TADJuego.h
 *
 *  Created on: 28 dic. 2022
 *      Author: Jorge Carrasco Facundo
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_

#include <iostream>
#include <string>
#include "TADTablero.h"
#include "entorno.h"

struct Juego {
	Tablero t;
	int puntuacion;
};

// PRE {Juego j, 13 > int filas > 0, 10 > int col > 0}
// POST {Inicia el tablero del juego y pone la puntuación a cero}
// Complejidad: O(n²)
void iniciar(Juego &j, int filas, int col);

// PRE {Juego j}
// POST {Permite controlar el juego y la comunicación entre el teclado, el tablero y el entorno}
// Complejidad: O(n²)
void jugar(Juego &j);

// PRE {Juego j, 13 > int numFilas > 0, 10 > int numColumnas > 0}
// POST {Actualiza la matriz, ya sea por borrado de filas o replicado de las celdas}
// Complejidad: O(n²)
void actualizar(Juego j, int numFilas, int numColumnas);

// PRE {Juego j}
// POST {Muestra un mensaje de despedida y termina el entorno}
// Complejidad: O(1)
void terminar(Juego j);


#endif /* TADJUEGO_H_ */
