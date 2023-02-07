//============================================================================
// Name        : BlockMergeBase.cpp
// Author      : Profesorado de IP/FP
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "entorno.h"
#include "TADJuego.h"
#include "pr_TADCelda.h"
#include "pr_TADTablero.h"
#include <time.h>
#include <stdlib.h>

using namespace std;


void ejemploEntorno() {
	//variables para almacenar la información del fichero de configuración
	int numFilas, numColumnas,filasIniciales, maxReplicas, maxAyudas, deDonde;
	int m[MAX_FILAS][MAX_COLUMNAS];
	int puntos = 0; //variable que almacena los puntos obtendos por el jugador

	//se carga la información almacenada en el fich. de configuración
	if (entornoCargarConfiguracion(numFilas, numColumnas, filasIniciales,maxReplicas,maxAyudas, deDonde, m)) {
		entornoIniciar(numFilas, numColumnas); //se inicia el entorno gráfico




		//se visualizan en el entorno gráfico los valores extraídos del
		//fichero de configuración y almacenados en la matriz m
		int fila, col;
		for ( fila = 0; fila < numFilas; fila++) {
			for ( col = 0; col < numColumnas; col++) {
				if (fila % 2 ==0)
				entornoActivarNumero(fila, col, m[fila][col]);  //el número aparece en color negro
				else entornoDesactivarNumero(fila, col, m[fila][col]);  //el número aparece en gris
			}
		}

		bool salir = false; //bandera utilizada para finalizar el bucle
		TipoTecla tecla;    //almacena la tecla pulsada por el usuario

		fila = 0;
		col  = 0;
		entornoMarcarPosicion(fila,col);
		entornoPonerPuntuacion (puntos,0);
		entornoMostrarMensaje("Pulsa ESC para salir",1.5);
		entornoMostrarMensaje("Pulsa F1 para aumentar puntuacion",1.5);
		entornoMostrarMensaje("Pulsa F2 para eliminar algunos números",1.5);
		//el bucle permite al jugador desplazarse por el tablero de juego
		while (!salir) {
			tecla = entornoLeerTecla();
			switch (tecla) {
			case TEnter:
				entornoSeleccionarPosicion(fila,col);
				entornoPausa (0.5);
				entornoDeseleccionarPosicion (fila,col);
				break;
			case TDerecha:
				entornoDesmarcarPosicion(fila, col);
				if (col < numColumnas - 1)
						col++;
				else
						col = 0;
				entornoMarcarPosicion(fila, col);
				break;
			case TIzquierda:
				entornoDesmarcarPosicion(fila, col);
				if (col > 0)
					col--;
				else
					col = numColumnas - 1;
				entornoMarcarPosicion(fila, col);
				break;
			case TArriba:
				entornoDesmarcarPosicion(fila, col);
				if (fila > 0)
					fila--;
				else
					fila = numFilas - 1;
				entornoMarcarPosicion(fila, col);
				break;
			case TAbajo:
				entornoDesmarcarPosicion(fila, col);
				if (fila < numFilas - 1)
					fila++;
				else
					fila = 0;
				entornoMarcarPosicion(fila, col);
				break;

			case TF1:
				puntos = puntos + 10;
				entornoPonerPuntuacion(puntos,10);
				break;
			case TF2:
				for (int i = 0; i < filasIniciales; i++) {

							entornoPonerVacio(i,i);
							entornoPausa(0.5);
						}
				break;
			case TSalir:
				salir = true;
				break;

			case TNada:
				break;
			} //Fin de switch
		}//Fin de while


	entornoMostrarMensajeFin("¡¡¡¡Adios!!!!");
	entornoTerminar();
	}//Fin de if

}

int main() {
	//ejemploEntorno();
	Juego j;
	srand(time(0));
	//pruebasCelda();
	//pruebasTablero();
	jugar(j);
	return 0;
}
