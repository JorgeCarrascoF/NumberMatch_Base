/**

	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2022/2023

	Nombre: entorno.h
	Descripción: Especificación del TAD Entorno para el proyecto NumberMatch
	     	 	 encargado del manejo de la interfaz del juego.
	     	 	 versión allegro 5.2
	Autor:	Profesorado de las asignaturas
    Fecha:	02/11/2022
*/

#ifndef ENTORNO_H_
#define ENTORNO_H_

#include <iostream>
#include <string>

using namespace std;


// -------------------------------------------------------------
// Definicion de constantes públicas
// -------------------------------------------------------------

//valores máximos para las filas y las columnas y número de filas que se ocupan al inicio del juego
const int MAX_FILAS = 12;
const int MAX_COLUMNAS = 9;


// -------------------------------------------------------------
// Definicion de tipos
// -------------------------------------------------------------

/**
 *   Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
 *   de los cursores o teclas válidas que se ha pulsado
 */
enum TipoTecla {TNada, TEnter, TIzquierda, TDerecha, TArriba, TAbajo, TF1, TF2, TSalir};


// ----------------------------------------------------------------
// Declaración de la interfaz pública (módulos que se pueden usar)
// ----------------------------------------------------------------


 /*
  *	PRE:  3 <= filas <= MAX_FILAS, 3 <= columnas <= MAX_COLUMNAS,
  *	DESCRIPCIÓN: Inicia la interfaz gráfica del juego, preparada para
  *		  un tablero de filas x columnas casillas.
  */
void entornoIniciar (int filas, int columnas);


 /*
  *	DESCRIPCIÓN: Libera los recursos usados por el entorno gráfico
  */
void entornoTerminar ();


/*
 *	PRE: Archivo match.cnf correcto y en la carpeta raíz del proyecto
 *	     (NO SE COMPRUEBAN ERRORES EN LOS DATOS)
 *	POST: Devuelve:
 *	        TRUE:  si se carga correctamente la configuración del juego,
 *		     FALSE: en caso contrario.
 *   PARÁMETROS:
 *		Si la configuración se lee de forma correcta se devolverá:
 *		   filas:		     número de filas del tablero del juego
 *		   columnas:         número de columnas del tablero del juego
 *		   filasIniciales:   número de filas ocupadas al iniciar el juego
 *		   maxReplicas:		 número máximo de veces que se pueden "replicar" los datos del tablero
 *		   maxAyudas:		 número máximo de veces que el jugador puede solicitar "ayuda" (ampliación)
 *		   deDonde           si deDonde == 0 el tablero se lee desde el fichero de configuración
 *		   					 en caso contrario se generará aleatoriamente
 *		   m:				 matriz que contiene los valores numéricos del tablero del juego.
 *		   					 Solo si deDonde es 0.
 *
 *		Por omisión, el archivo match.cnf se encuentra en el directorio  del proyecto
 */
bool entornoCargarConfiguracion ( int &filas, int &columnas, int &filasIniciales,
		int &maxReplicas, int &maxAyudas, int &deDonde, int m[MAX_FILAS][MAX_COLUMNAS]);


/*
 * PRE: { 0 <= fila < MAX_FILAS, 0 <= columna < MAX_COLUMNAS, 1 <=  numero <= 9 }
 * DESCRIPCIÓN: Coloca en la posición [fila,columna] del tablero el número indicado en color negro
 */
void entornoActivarNumero  (int fila, int columna, int numero);

/*
 * PRE: { 0 <= fila < MAX_FILAS, 0 <= columna < MAX_COLUMNAS, 1 <=  numero <= 9 }
 * DESCRIPCIÓN: Coloca en la posición [fila,columna] del tablero el número indicado en color gris
 *              indicando que se ha borrado por formar pareja
 */
void entornoDesactivarNumero  (int fila, int columna, int numero);

/*
 * PRE: { 0 <= fila < MAX_FILAS, 0 <= columna < MAX_COLUMNAS }
 * DESCRIPCIÓN: Deja en blanco la posición [fila, columna] del tablero
 * 				indicando que la celda está vacía
 */
void entornoPonerVacio  (int fila, int columna);


/*
 * PRE: { 0 <= fila < MAX_FILAS, 0 <= columna < MAX_COLUMNAS }
 * DESCRIPCIÓN: Enmarca la celda que ocupa la posición (fila, columna) en un cuadrado azul
 *              Se utiliza para simular el movimiento por el tablero
 */
void entornoMarcarPosicion(int fila, int columna);


/*
 * PRE: { 0 <= fila < MAX_FILAS, 0 <= columna < MAX_COLUMNAS }
 * DESCRIPCIÓN: Elimina el cuadrado azul de la celda que ocupa la posición (fila, columna)
 *              Se utiliza para simular el movimiento por el tablero
 */
void entornoDesmarcarPosicion(int fila, int columna);

/*
 * PRE: { 0 <= fila < MAX_FILAS, 0 <= columna < MAX_COLUMNAS }
 * DESCRIPCIÓN: Enmarca la celda que ocupa la posición (fila, columna) en un cuadrado rojo
 *              Se utiliza para indicar que la celda ha sido seleccionada por el jugador
 */
void entornoSeleccionarPosicion(int fila, int columna);

/*
 * PRE: { 0 <= fila < MAX_FILAS, 0 <= columna < MAX_COLUMNAS }
 * DESCRIPCIÓN: Elimina el cuadrado rojo de la celda que ocupa la posición (fila, columna)
 *              Se utiliza para indicar que la celda ya no está seleccionada
 */
void entornoDeseleccionarPosicion(int fila, int columna);


/*
 * PRE: { 0 <= f1,f2 < MAX_FILAS, 0 <= c1,c2 < MAX_COLUMNAS, pausa > 0 }
 * DESCRIPCIÓN: Destaca con cuadrados amarillos las celdas que ocupa las posiciones [f1,c1] y [f2,c2]
 * 				las marcas amarillas aparecen durante el tiempo (en segundos) que indica pausa
 *              Se utiliza para indicar que las celdas forman pareja
 */
void entornoAyuda(int f1, int c1, int f2, int c2, float pausa);


/*
 * PRE: {puntuacion <= 999, incremento >= 0 }
 * DESCRIPCIÓN: Muestra el valor indicado como "puntuación" en el marcador situado en la parte superior
 *              de la ventana, previamente muestra (durante unos segundos) a la derecha los puntos que se van a añadir
 *              (incremento), esto solo ocurre si incremento > 0
 *
 */
void entornoPonerPuntuacion( int puntuacion, int incremento);


/*
 * PRE: "msg" está correctamente inicializado
 * DESCRIPCIÓN: Muestra el mensaje "msg" en el centro de la ventana para indicar que ha finalizado el juego
 */
void entornoMostrarMensajeFin (string msg);


/*
 * PRE: {0 < pausa y "msg" está correctamente inicializado}
 * DESCRIPCIÓN:	Muestra el mensaje "msg" en la parte inferior de la pantalla
 *              durante los segundos indicados por "pausa"
 */
void entornoMostrarMensaje (string msg, float pausa);


/*
 * POST:Devuelve el valor enumerado de TipoTecla que corresponde a la tecla que se haya pulsado
 */
TipoTecla entornoLeerTecla();


/*
 * PRE: {0 < pausa}
 * DESCRIPCIÓN: para la ejecución durante "pausa" segundos
 */
void entornoPausa(float pausa);

#endif
