/*
 * TADCelda.cpp
 *
 *  Created on: 28 dic. 2022
 *      Author: Jorge Carrasco Facundo
 */


#include "TADCelda.h"

void iniciarCelda(Celda &c, int num) {
	c.valor = num;
	c.vacia = false;
	c.borrada = false;

}

void iniciarCeldaVacia(Celda &c) {
	c.vacia = true;
	c.borrada = true;
}

int obtenerValor(Celda c) {
	return c.valor;
}

bool estaVacia(Celda c) {
	return c.vacia;
}

bool estaBorrada(Celda c) {
	return c.borrada;
}

void borrarCelda(Celda &c){
	c.borrada = true;
}
