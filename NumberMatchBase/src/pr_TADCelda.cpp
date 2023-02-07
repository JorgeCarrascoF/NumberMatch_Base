/*
 * pr_TADCelda.cpp
 *
 *  Created on: 30 dic. 2022
 *      Author: alumno
 */


#include "pr_TADCelda.h"

void pruebasCelda() {
	cout << "Inicio de las pruebas del TAD Celda" << endl;

	cout << "Prueba 1:" << endl;

	Celda c, p;
	int n = 2;

	iniciarCelda(c, n);

	if(obtenerValor(c) != 2 || estaVacia(c) || estaBorrada(c)){
		cout << "Error al iniciar una celda con número:" << endl;
		if (estaVacia(c)) {
			cout << "La celda se ha iniciado vacía." << endl;
		} else if (estaBorrada(c)) {
			cout << "La celda se ha iniciado borrada." << endl;
		} else if(obtenerValor(c)!=2) {
			cout << "La celda tiene un valor diferente a " << n << ": " << obtenerValor(c);
		}
	}

	iniciarCeldaVacia(p);

	if(!estaVacia(p) || !estaBorrada(p)) {
		cout << "Error al iniciar una celda vacía:" << endl;
				if (!estaVacia(c)) {
					cout << "La celda se ha iniciado llena." << endl;
				} else if (!estaBorrada(c)) {
					cout << "La celda se ha iniciado sin borrar." << endl;
				}
	}

	borrarCelda(c);

	if(!estaBorrada(c)) {
		cout << "Error al borrar una celda con número:" << endl;
		cout << "La celda no se ha borrado." << endl;
	}

	cout << "Prueba 2:" << endl;

	n = 5;

	iniciarCelda(c, n);

	if(obtenerValor(c) != 5 || estaVacia(c) || estaBorrada(c)){
		cout << "Error al iniciar una celda con número:" << endl;
		if (estaVacia(c)) {
			cout << "La celda se ha iniciado vacía." << endl;
		} else if (estaBorrada(c)) {
			cout << "La celda se ha iniciado borrada." << endl;
		} else if(obtenerValor(c) != 5) {
			cout << "La celda tiene un valor diferente a " << n << ": " << obtenerValor(c);
		}
	}

	iniciarCeldaVacia(p);

	if(!estaVacia(p) || !estaBorrada(p)) {
		cout << "Error al iniciar una celda vacía:" << endl;
				if (!estaVacia(c)) {
					cout << "La celda se ha iniciado llena." << endl;
				} else if (!estaBorrada(c)) {
					cout << "La celda se ha iniciado sin borrar." << endl;
				}
	}

	borrarCelda(c);

	if(!estaBorrada(c)) {
		cout << "Error al borrar una celda con número:" << endl;
		cout << "La celda no se ha borrado." << endl;
	}


	cout << "Prueba 3:" << endl;

		n = 164;

		iniciarCelda(c, n);

		if(obtenerValor(c) != 164 || estaVacia(c) || estaBorrada(c)){
			cout << "Error al iniciar una celda con número:" << endl;
			if (estaVacia(c)) {
				cout << "La celda se ha iniciado vacía." << endl;
			} else if (estaBorrada(c)) {
				cout << "La celda se ha iniciado borrada." << endl;
			} else if(obtenerValor(c) != 164) {
				cout << "La celda tiene un valor diferente a " << n << ": " << obtenerValor(c);
			}
		}

		iniciarCeldaVacia(p);

		if(!estaVacia(p) || !estaBorrada(p)) {
			cout << "Error al iniciar una celda vacía:" << endl;
					if (!estaVacia(c)) {
						cout << "La celda se ha iniciado llena." << endl;
					} else if (!estaBorrada(c)) {
						cout << "La celda se ha iniciado sin borrar." << endl;
					}
		}

		borrarCelda(c);

		if(!estaBorrada(c)) {
			cout << "Error al borrar una celda con número:" << endl;
			cout << "La celda no se ha borrado." << endl;
		}

		cout << "Prueba 4:" << endl;

		n = 5000;

		iniciarCelda(c, n);

		if(obtenerValor(c) != 5000 || estaVacia(c) || estaBorrada(c)){
				cout << "Error al iniciar una celda con número:" << endl;
				if (estaVacia(c)) {
					cout << "La celda se ha iniciado vacía." << endl;
				} else if (estaBorrada(c)) {
					cout << "La celda se ha iniciado borrada." << endl;
				} else if(obtenerValor(c) != 5000) {
					cout << "La celda tiene un valor diferente a " << n << ": " << obtenerValor(c);
				}
		}

		iniciarCeldaVacia(p);

		if(!estaVacia(p) || !estaBorrada(p)) {
				cout << "Error al iniciar una celda vacía:" << endl;
						if (!estaVacia(c)) {
							cout << "La celda se ha iniciado llena." << endl;
						} else if (!estaBorrada(c)) {
							cout << "La celda se ha iniciado sin borrar." << endl;
						}
		}

		borrarCelda(c);

		if(!estaBorrada(c)) {
				cout << "Error al borrar una celda con número:" << endl;
				cout << "La celda no se ha borrado." << endl;
			}

		cout << "Prueba 5:" << endl;

		n = -75;

		iniciarCelda(c, n);

		if(obtenerValor(c) != -75 || estaVacia(c) || estaBorrada(c)){
				cout << "Error al iniciar una celda con número:" << endl;
				if (estaVacia(c)) {
					cout << "La celda se ha iniciado vacía." << endl;
				} else if (estaBorrada(c)) {
					cout << "La celda se ha iniciado borrada." << endl;
				} else if(obtenerValor(c) != -75) {
					cout << "La celda tiene un valor diferente a " << n << ": " << obtenerValor(c);
				}
		}

			iniciarCeldaVacia(p);

			if(!estaVacia(p) || !estaBorrada(p)) {
				cout << "Error al iniciar una celda vacía:" << endl;
						if (!estaVacia(c)) {
							cout << "La celda se ha iniciado llena." << endl;
						} else if (!estaBorrada(c)) {
							cout << "La celda se ha iniciado sin borrar." << endl;
						}
			}

			borrarCelda(c);

			if(!estaBorrada(c)) {
				cout << "Error al borrar una celda con número:" << endl;
				cout << "La celda no se ha borrado." << endl;
			}

	cout << "Fin de las pruebas del TAD Celda" << endl;
}
