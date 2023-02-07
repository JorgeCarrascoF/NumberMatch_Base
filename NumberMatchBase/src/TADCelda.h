/*
 * TADCelda.h
 *
 *  Created on: 28 dic. 2022
 *      Author: Jorge Carrasco Facundo
 */

#ifndef TADCELDA_H_
#define TADCELDA_H_

#include <iostream>
#include <string>

struct Celda {
	int valor;
	bool vacia;
	bool borrada;
};

using namespace std;

// PRE {Celda c, int num > 0}
// POST {Inicia una celda con el valor n}
// Complejidad: O(1)
void iniciarCelda(Celda &c, int num);

// PRE {Celda c}
// POST {Inicia una celda c.vacia y c.borrada en true}
// Complejidad: O(1)
void iniciarCeldaVacia(Celda &c);

// PRE {Celda c}
// POST {Devuelve c.valor}
// Complejidad: O(1)
int obtenerValor(Celda c);

// PRE {Celda c}
// POST {Devuelve c.vacia}
// Complejidad: O(1)
bool estaVacia(Celda c);

// PRE {Celda c}
// POST {Devuelve c.borrada}
// Complejidad: O(1)
bool estaBorrada(Celda c);

// PRE {Celda c}
// POST {Pone c.borrada en true}
// Complejidad: O(1)
void borrarCelda(Celda &c);


#endif /* TADCELDA_H_ */
