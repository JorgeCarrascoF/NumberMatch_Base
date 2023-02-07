/*
 * TADJuego.cpp
 *
 *  Created on: 28 dic. 2022
 *      Author: Jorge Carrasco Facundo
 */


#include "TADJuego.h"


void iniciar(Juego &j, int filas, int col) {
	iniciarTablero(j.t, filas, col);
	j.puntuacion = 0;
}

void jugar(Juego &j) {
	int numFilas, numColumnas,filasIniciales, maxReplicas, maxAyudas, deDonde;
	int m[MAX_FILAS][MAX_COLUMNAS];


	if (entornoCargarConfiguracion(numFilas, numColumnas, filasIniciales,maxReplicas,maxAyudas, deDonde, m)) {
			entornoIniciar(numFilas, numColumnas); //se inicia el entorno gráfico
			int replicas = maxReplicas;

			iniciar(j, filasIniciales, numColumnas);

			if(deDonde == 0) {
				for(int i = 0; i < filasIniciales; i++) {
					for (int k = 0; k < numColumnas; k++) {
						ponerValorCelda(j.t, i, k, m[i][k]);
					}
				}
			}

			for (int fila = 0; fila < filasIniciales; fila++) {
				for (int col = 0; col < numColumnas; col++) {
					entornoActivarNumero(fila, col, obtenerValor(j.t.m[fila][col]));
				}
			}

			bool salir = false;
			TipoTecla tecla;

			int fila = 0;
			int col = 0;

			bool celdaGuardada = false;

			// Para guardar la primera selección a la hora de formar parejas
			int primeraSeleccionadaFila;
			int primeraSeleccionadaCol;

			entornoMarcarPosicion(fila, col);
			entornoPonerPuntuacion(j.puntuacion, 0);
			entornoMostrarMensaje("Pulsa ESC para salir",1.5);
			entornoMostrarMensaje("Pulsa F1 para hacer réplicas(MAX: 5)",1.5);
			entornoMostrarMensaje("Pulsa F2 para eliminar algunos números",1.5);

			while (!salir) {
				tecla = entornoLeerTecla();
				switch (tecla) {
				case TEnter:
					if(!estaVacia(j.t.m[fila][col])) {
					if (!estaBorrada(j.t.m[fila][col]) && !estaVacia(j.t.m[fila][col])) {
						entornoSeleccionarPosicion(fila, col);
						entornoPausa(0.4);
						if (!celdaGuardada) {
							primeraSeleccionadaFila = fila;
							primeraSeleccionadaCol = col;
							celdaGuardada = true;
						} else {
							celdaGuardada = false;
							entornoDeseleccionarPosicion(primeraSeleccionadaFila, primeraSeleccionadaCol);
							entornoDeseleccionarPosicion(fila, col);

							if(sonPareja(j.t, fila, col, primeraSeleccionadaFila, primeraSeleccionadaCol)){
								borrarCelda(j.t.m[fila][col]);
								entornoDesactivarNumero(fila, col, obtenerValorCelda(j.t, fila, col));
								borrarCelda(j.t.m[primeraSeleccionadaFila][primeraSeleccionadaCol]);
								entornoDesactivarNumero(primeraSeleccionadaFila, primeraSeleccionadaCol, obtenerValorCelda(j.t, primeraSeleccionadaFila,primeraSeleccionadaCol));
								j.puntuacion++;
								entornoPonerPuntuacion(j.puntuacion, 1);



								if(estaFilaBorrada(j.t, fila)){
									borrarFila(j.t, fila);
									actualizar(j, numFilas, numColumnas);
									j.puntuacion += 10;
									entornoPonerPuntuacion(j.puntuacion, 10);
									if (fila < primeraSeleccionadaFila) {
										primeraSeleccionadaFila--;
									}
								}

								if (j.t.celdasUtiles > numFilas) { // Evita que sume dos veces si sólo queda una fila por eliminar
									if(estaFilaBorrada(j.t, primeraSeleccionadaFila)){
										borrarFila(j.t, primeraSeleccionadaFila);
										actualizar(j, numFilas, numColumnas);
										j.puntuacion += 10;
										entornoPonerPuntuacion(j.puntuacion, 10);
									}
								}

							}
						}
					}

					}
					break;
				case TDerecha:
					entornoDesmarcarPosicion(fila, col);
					if (col < numColumnas-1) {
						col++;
					}
					else {
						col = 0;
					}
					entornoMarcarPosicion(fila, col);
					break;
				case TIzquierda:
					entornoDesmarcarPosicion(fila, col);
					if (col > 0){
						col--;
					}
					else {
						col = numColumnas - 1;
					}
					entornoMarcarPosicion(fila, col);
					break;
				case TArriba:
					entornoDesmarcarPosicion(fila, col);
					if (fila > 0) {
						fila--;
					}
					else {
						fila = numFilas - 1;
					}
					entornoMarcarPosicion(fila, col);
					break;
				case TAbajo:
					entornoDesmarcarPosicion(fila, col);
					if (fila < numFilas - 1) {
						fila++;
					}
					else {
						fila = 0;
					}
					entornoMarcarPosicion(fila, col);
					break;
				case TF1:
					if(replicas > 0) {
						replicarNoBorradas(j.t);
						actualizar(j, numFilas, numColumnas);
						replicas--;
						if(j.t.celdasUtiles >= numFilas*numColumnas) {
							entornoMostrarMensaje("Matriz desbordada",1.5);
							entornoMostrarMensajeFin("Fin del juego");
							terminar(j);
						}
					} else {
						entornoMostrarMensaje("No hay réplicas restantes",1.5);
					}
					break;
				case TF2:
					break;
				case TSalir:
					salir = true;
					terminar(j);
					break;
				case TNada:
					break;
				}

				if(j.t.celdasUtiles <= 0) {
					entornoMostrarMensaje("Todas las celdas emparejadas",1.5);
					entornoMostrarMensajeFin("¡Felicidades!");
					terminar(j);
				}

			}
	}

}

void actualizar(Juego j, int numFilas, int numColumnas) {
	int ultimaCol;
	int ultimaFila = devolverUltimaCeldaOcupada(j.t, ultimaCol);


	// Borrado de la matriz.
	for (int i = 0; i < numFilas; i++) {
		for (int j = 0; j < numColumnas; j++){
			entornoPonerVacio(i, j);
		}

	}

	for (int fila = 0; fila <= ultimaFila; fila++) {
		for (int col = 0; col < numColumnas; col++) {
			if (fila < ultimaFila) {
				if(estaBorrada(j.t, fila, col)){
					entornoDesactivarNumero(fila, col, obtenerValor(j.t.m[fila][col]));
				}	else {
					entornoActivarNumero(fila, col, obtenerValor(j.t.m[fila][col]));
				}
			} else if (fila == ultimaFila && col <= ultimaCol) {
				if(estaBorrada(j.t, fila, col)){
					entornoDesactivarNumero(fila, col, obtenerValor(j.t.m[fila][col]));
				}	else {
				entornoActivarNumero(fila, col, obtenerValor(j.t.m[fila][col]));
				}
			}
		}
	}
}



void terminar(Juego j) {
	entornoMostrarMensajeFin("¡¡¡¡Adios!!!!");
	entornoTerminar();
}
