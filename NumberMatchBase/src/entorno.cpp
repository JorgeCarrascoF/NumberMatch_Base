/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2022/2023

 Nombre: entorno.cpp
 Descripción: Implementación del TAD Entorno para el proyecto NumberMatch
 Encargado del manejo de la interfaz del juego.
 Autor:	Profesorado de las asignaturas
 Fecha:	02/11/2022

 */

#include "entorno.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro5.h>

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// -------------------------------------------------------------
// Definicion de constantes privadas
// -------------------------------------------------------------
// Definición de colores que usa el entorno

const int COLOR_AZUL      = 1;
const int COLOR_BLANCO    = 2;
const int COLOR_ROJO      = 3;
const int COLOR_NEGRO     = 4;
const int COLOR_GRIS      = 5;
const int COLOR_AMARILLO  = 6;
const int COLOR_ORO       = 7;
const int COLOR_VERDE     = 8;
const int COLOR_GRIS_CLARO = 9;
const int COLOR_PLATA     = 10;

const int COLOR_LINEAS = COLOR_NEGRO;
const float GROSOR_LINEAS = 2.0;


const int ANCHO_VENTANA = 600;
const int ALTO_VENTANA  = 700;

// Definicón de constantes para posicionar los números en el tablero
const int DISTANCIA_COLS  = 45;  // Distancia entre columnas
const int DISTANCIA_FILAS = 45;  // Distancia entre filas
const int DISTANCIA_FIL_COL = 45;
const int SEPARACION_FILAS_COL = 2;  // separacion entre las filas y columnas

const int ORIGEN_X          = 95 ;  // Origen de las x
const int ORIGEN_Y     		= 70 ;  // Origen de las y


// definicion de las constantes para posicionar los marcadores
const int FILA_MARCADOR = 110;
const int COL_MARCADOR  = 14;



ALLEGRO_DISPLAY     *display;
ALLEGRO_FONT        *font, *font_texto;
ALLEGRO_EVENT_QUEUE *colaEventos = NULL;


// -------------------------------------------------------------
// Definición de módulos PRIVADOS
// -------------------------------------------------------------

// define el color en función de los valores makecol - allegro library
ALLEGRO_COLOR makecolor2(int color) {

	ALLEGRO_COLOR alColor;

	switch (color) {
	case COLOR_BLANCO:
		alColor = al_map_rgb (255, 255, 255);
		break;
	case COLOR_ROJO:
		alColor = al_map_rgb (255,   69,  0);
		break;
	case COLOR_NEGRO:
		alColor = al_map_rgb (0,    0,   0);
		break;
	case COLOR_AZUL:
		alColor = al_map_rgb (70,   150, 255);
		break;
	case COLOR_GRIS:
		alColor = al_map_rgb ( 47, 79, 79);
		break;
	case COLOR_AMARILLO:
		alColor = al_map_rgb ( 255, 255, 000);
		break;
	case COLOR_ORO:
		alColor = al_map_rgb ( 234, 190, 63);
		break;
	case COLOR_VERDE:
		alColor = al_map_rgb ( 036,231,017);
		break;
	case COLOR_GRIS_CLARO:
		alColor = al_map_rgb ( 220,220,220);
		break;
	case COLOR_PLATA:
		alColor = al_map_rgb ( 138,149,151);
		break;
	default:
		alColor = al_map_rgb (255, 255, 255);
		break; //color blanco
	}

	return alColor;
}



void invertirFC(int &fila, int &columna) {
	int aux = columna;
	columna = fila;
	fila = aux;
}

// -------------------------------------------------------------
// Definición de la interfaz PÚBLICA
// -------------------------------------------------------------

void entornoIniciar(int n_filas, int n_columnas) {
	string msg;
	// Iniciar el entorno

	if (al_init()){
	al_install_keyboard();

	al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
	al_set_new_display_flags (ALLEGRO_WINDOWED);

	display = al_create_display(ANCHO_VENTANA,ALTO_VENTANA);
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	// carga las fuentes con tamaño 20
	font = al_load_ttf_font("OpenSans-Bold.ttf", 20, 0);
	font_texto = al_load_ttf_font("DroidSerif-Regular.ttf", 17, 0);

	// borra la ventana con el color blanco
    al_clear_to_color(makecolor2(COLOR_BLANCO));
    al_set_window_title(display, "UEx NumberMatch");

    // se refresca la pantalla
    colaEventos = al_create_event_queue();
    al_register_event_source(colaEventos, al_get_keyboard_event_source());

    //se pinta la rejilla, cuadro exterior
    al_draw_rectangle(ORIGEN_X, ORIGEN_Y,
    				ORIGEN_X + n_columnas * DISTANCIA_FIL_COL ,
    				ORIGEN_Y + n_filas * DISTANCIA_FIL_COL , makecolor2(COLOR_NEGRO) ,5);

    //lineas verticales
    for (int i=1; i< n_columnas; i++){
    	al_draw_line(ORIGEN_X + i*DISTANCIA_FIL_COL,
    			    ORIGEN_Y ,
    	    		ORIGEN_X + i*DISTANCIA_FIL_COL,
    	    		ORIGEN_Y + n_filas * DISTANCIA_FIL_COL , makecolor2(COLOR_NEGRO) ,2);
    }

    //lineas horizontales
    for (int i=1; i< n_filas; i++){
        al_draw_line(ORIGEN_X ,
        		    ORIGEN_Y + i*DISTANCIA_FIL_COL,
        	    	ORIGEN_X + n_columnas*DISTANCIA_FIL_COL,
        	    	ORIGEN_Y + i*DISTANCIA_FIL_COL , makecolor2(COLOR_NEGRO) ,2);
     }

    //mensaje al final en la parte inferior de la ventana
    msg = "Cursores:  ←, →, ↑, ↓ - Enter: Selec - Esc: Salir - F1: Replicar - F2: Ayuda";
    al_draw_text(font_texto, makecolor2(COLOR_NEGRO), 20,630,  ALLEGRO_ALIGN_LEFT, msg.c_str());

    al_flip_display();

	}
}


void entornoTerminar(){

	al_destroy_display          (display);
	al_destroy_event_queue      (colaEventos);
	al_destroy_font				(font);
	al_destroy_font				(font_texto);
	al_shutdown_primitives_addon();
	al_shutdown_font_addon      ();
}


bool entornoCargarConfiguracion ( int &filas, int &columnas, int &filasIniciales,
		int &maxReplicas, int &maxAyudas, int &deDonde, int m[MAX_FILAS][MAX_COLUMNAS]){

	bool leido;
	int i, j;
	ifstream fEntrada;
	string cadena, cad;
	fEntrada.open("match.cnf");
	if (fEntrada.is_open()) {
		getline(fEntrada, cadena);
		filas = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		columnas = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		filasIniciales = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		maxReplicas = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		maxAyudas = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		deDonde = atoi(cadena.c_str());

		for (i = 0; i<filas; i++){
				for (j = 0; j< columnas-1; j++){
					getline (fEntrada,cad,' ');
					m[i][j]= atoi(cad.c_str());
				}
				getline (fEntrada,cad);
				m[i][j]= atoi(cad.c_str());
				}
		leido = true;

		fEntrada.close();
	} else {
		cout << "Fichero de configuración no encontrado (<proyecto>/match.cnf)" << endl;
		leido = false;
	}

	return leido;
}



void entornoActivarNumero(int fila, int columna, int numero) {
	invertirFC(fila, columna);
	float base, altura, ptoMedioX, ptoMedioY;
	float x1 = (ORIGEN_X + fila    * DISTANCIA_COLS                   ) + SEPARACION_FILAS_COL;
	float y1 = (ORIGEN_Y + columna * DISTANCIA_FILAS                  ) + SEPARACION_FILAS_COL;
	float x2 = (ORIGEN_X + fila    * DISTANCIA_COLS  + DISTANCIA_COLS )	- SEPARACION_FILAS_COL;
	float y2 = (ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS) - SEPARACION_FILAS_COL;

	base      = (x2 - x1);
	altura    = (y2 - y1);
	ptoMedioX = ((base / 2.0) + x1);
	ptoMedioY = ((y2 + y1) / 2.0) - (altura / 2.0) + SEPARACION_FILAS_COL + 5;

	al_draw_text(font, makecolor2(COLOR_NEGRO), ptoMedioX, ptoMedioY,	ALLEGRO_ALIGN_CENTER, to_string(numero).c_str());
	al_flip_display();

}


void entornoDesactivarNumero(int fila, int columna, int numero) {
	invertirFC(fila, columna);
	float base, altura, ptoMedioX, ptoMedioY;
	float x1 = (ORIGEN_X + fila    * DISTANCIA_COLS                   ) + SEPARACION_FILAS_COL;
	float y1 = (ORIGEN_Y + columna * DISTANCIA_FILAS                  ) + SEPARACION_FILAS_COL;
	float x2 = (ORIGEN_X + fila    * DISTANCIA_COLS  + DISTANCIA_COLS )	- SEPARACION_FILAS_COL;
	float y2 = (ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS) - SEPARACION_FILAS_COL;

	base      = (x2 - x1);
	altura    = (y2 - y1);
	ptoMedioX = ((base / 2.0) + x1);
	ptoMedioY = ((y2 + y1) / 2.0) - (altura / 2.0) + SEPARACION_FILAS_COL + 5;

	al_draw_text(font, makecolor2(COLOR_GRIS_CLARO), ptoMedioX, ptoMedioY,	ALLEGRO_ALIGN_CENTER, to_string(numero).c_str());
	al_flip_display();

}


void entornoPonerVacio(int fila, int columna) {
	invertirFC(fila, columna);

	float x1 = (ORIGEN_X + fila    * DISTANCIA_COLS                   ) + SEPARACION_FILAS_COL;
	float y1 = (ORIGEN_Y + columna * DISTANCIA_FILAS                  ) + SEPARACION_FILAS_COL;
	float x2 = (ORIGEN_X + fila    * DISTANCIA_COLS  + DISTANCIA_COLS )	- SEPARACION_FILAS_COL;
	float y2 = (ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS) - SEPARACION_FILAS_COL;

	al_draw_filled_rectangle(x1, y1, x2, y2, makecolor2(COLOR_BLANCO));
	al_flip_display();
}


void entornoMarcarPosicion(int fila, int columna) {

	invertirFC(fila, columna);
	al_draw_rectangle( (ORIGEN_X + fila * DISTANCIA_COLS ) + SEPARACION_FILAS_COL + 5 ,
				(ORIGEN_Y + columna * DISTANCIA_FILAS) + SEPARACION_FILAS_COL +5,
				(ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL - 5,
				(ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL -5 , makecolor2(COLOR_AZUL) ,2);
	al_flip_display();
}


void entornoDesmarcarPosicion(int fila, int columna) {

	invertirFC(fila, columna);
    al_draw_rectangle( (ORIGEN_X + fila * DISTANCIA_COLS ) + SEPARACION_FILAS_COL + 5,
				(ORIGEN_Y + columna * DISTANCIA_FILAS) + SEPARACION_FILAS_COL +5,
				(ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL - 5,
				(ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL -5, makecolor2(COLOR_BLANCO) ,2);
 	al_flip_display();
}


void entornoSeleccionarPosicion(int fila, int columna) {
	invertirFC(fila, columna);
	al_draw_rectangle( (ORIGEN_X + fila * DISTANCIA_COLS ) + SEPARACION_FILAS_COL +3,
				(ORIGEN_Y + columna * DISTANCIA_FILAS) + SEPARACION_FILAS_COL +2 ,
				(ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL -2 ,
				(ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL -3 , makecolor2(COLOR_ROJO) ,3);
	al_flip_display();
}


void entornoDeseleccionarPosicion(int fila, int columna) {
	invertirFC(fila, columna);
	    al_draw_rectangle( (ORIGEN_X + fila * DISTANCIA_COLS ) + SEPARACION_FILAS_COL +3,
					(ORIGEN_Y + columna * DISTANCIA_FILAS) + SEPARACION_FILAS_COL +2 ,
					(ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL -2 ,
					(ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL -3, makecolor2(COLOR_BLANCO) ,3);
	 	al_flip_display();
}


void entornoAyuda(int f1, int c1, int f2, int c2, float pausa) {
	invertirFC(f1, c1);
	invertirFC(f2, c2);
	al_draw_rectangle( (ORIGEN_X + f1 * DISTANCIA_COLS ) + SEPARACION_FILAS_COL +3,
				(ORIGEN_Y + c1 * DISTANCIA_FILAS) + SEPARACION_FILAS_COL +3 ,
				(ORIGEN_X + f1 * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL -3 ,
				(ORIGEN_Y + c1 * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL -3 , makecolor2(COLOR_ORO) ,3);
	al_draw_rectangle( (ORIGEN_X + f2 * DISTANCIA_COLS ) + SEPARACION_FILAS_COL +3,
					(ORIGEN_Y + c2 * DISTANCIA_FILAS) + SEPARACION_FILAS_COL +3 ,
					(ORIGEN_X + f2 * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL -3 ,
					(ORIGEN_Y + c2 * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL -3 , makecolor2(COLOR_ORO) ,3);
	al_flip_display();
	al_rest(pausa);
	al_draw_rectangle( (ORIGEN_X + f1 * DISTANCIA_COLS ) + SEPARACION_FILAS_COL +3,
					(ORIGEN_Y + c1 * DISTANCIA_FILAS) + SEPARACION_FILAS_COL +3 ,
					(ORIGEN_X + f1 * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL -3 ,
					(ORIGEN_Y + c1 * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL -3 , makecolor2(COLOR_BLANCO) ,3);
	al_draw_rectangle( (ORIGEN_X + f2 * DISTANCIA_COLS ) + SEPARACION_FILAS_COL +3,
						(ORIGEN_Y + c2 * DISTANCIA_FILAS) + SEPARACION_FILAS_COL +3 ,
						(ORIGEN_X + f2 * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL -3 ,
						(ORIGEN_Y + c2 * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL -3 , makecolor2(COLOR_BLANCO) ,3);
	al_flip_display();

}


void entornoPonerPuntuacion(int valor, int incremento) {
	string msg,msg1;
	msg = "Puntuación: "+to_string(valor);
	if (incremento > 0){
		msg1 = "+ " + to_string(incremento);
		al_draw_text(font, makecolor2(COLOR_AZUL),ORIGEN_X+180, COL_MARCADOR + 4  , ALLEGRO_ALIGN_LEFT, msg1.c_str());
		al_flip_display();
		al_rest(1);
	}
	al_draw_filled_rectangle(ORIGEN_X , COL_MARCADOR, ORIGEN_X+ 250, COL_MARCADOR+30, makecolor2(COLOR_BLANCO));
	al_draw_text(font, makecolor2(COLOR_GRIS),ORIGEN_X, COL_MARCADOR + 4  , ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
}


void entornoMostrarMensajeFin(string msg) {
	int i, j;
		for (i = 0, j = 0; i < 40 && j < 40; i += 4, j += 4) {

			al_draw_filled_rectangle(i + ORIGEN_X,     j + ORIGEN_Y   + 200,  ORIGEN_X   +350 - i, ORIGEN_Y+   320 -j,  makecolor2(COLOR_BLANCO));
			al_draw_filled_rectangle(i + ORIGEN_X + 2 ,j + ORIGEN_Y +2+ 200, (ORIGEN_X-2)+350 - i, ORIGEN_Y -2 +320 -j,  makecolor2(COLOR_PLATA));
			usleep(25000); //25 milisegundos
			al_flip_display();
		}

	al_draw_text(font_texto, makecolor2(COLOR_BLANCO),ORIGEN_X+100,ORIGEN_Y+250, ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
	usleep(500000); // medio segundo
}


void entornoMostrarMensaje( string msg, float pausa) {
	int col = ORIGEN_X/2;
	int fila = 660;
	int alto = 25;
	int ancho = 600;

	al_draw_filled_rectangle(col-2 , fila,  col + ancho, fila + alto,  makecolor2(COLOR_BLANCO));
	al_draw_text(font_texto, makecolor2(COLOR_ROJO),col,fila, ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
	entornoPausa(pausa);
	al_draw_filled_rectangle(col-2 , fila,  col + ancho,fila + alto,  makecolor2(COLOR_BLANCO));
	al_flip_display();

}


TipoTecla entornoLeerTecla() {

	TipoTecla tecla = TNada;
	ALLEGRO_EVENT evento;

	al_wait_for_event(colaEventos, &evento);

	if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (evento.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			tecla = TArriba;
			break;
		case ALLEGRO_KEY_DOWN:
			tecla = TAbajo;
			break;
		case ALLEGRO_KEY_LEFT:
			tecla = TIzquierda;
			break;
		case ALLEGRO_KEY_RIGHT:
			tecla = TDerecha;
			break;
		case ALLEGRO_KEY_ESCAPE:
			tecla = TSalir;
			break;
		case ALLEGRO_KEY_ENTER:
			tecla = TEnter;
			break;
		case ALLEGRO_KEY_F1:
			tecla = TF1;
			break;
		case ALLEGRO_KEY_F2:
			tecla = TF2;
			break;
		default:
			tecla = TNada;
			break;
		}
	};

	return tecla;

}



void entornoPausa(float pausa) {
	al_rest(pausa);
}




