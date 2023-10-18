//#ifndef FUNCIONES_H_INCLUDED
//#define FUNCIONES_H_INCLUDED
//
//// Aca van las declaraciones.
//
//#endif // FUNCIONES_H_INCLUDED

#pragma once
#include <iostream>
#include "estructuras.h"

using namespace std;

void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2);
void manejarOpcion(int opcion, Jugador &j1, Jugador &j2);
void nombresJugadores(Jugador &j1, Jugador &j2);
int generarNumero(int tamanio);
void selecCartas(Jugador j1, Jugador j2, Carta arr[], Carta vMazoMano[]);
void repartirCartas(Carta vMazoMano[], Jugador &jugador1, Jugador &jugador2);
void mezclarMazo(Carta vArr[], int tam);
