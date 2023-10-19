//#ifndef FUNCIONES_H_INCLUDED
//#define FUNCIONES_H_INCLUDED
//#endif // FUNCIONES_H_INCLUDED
#pragma once //guards

#include<iostream>
#include "estructuras.h"

//ACA VAN LAS DECLARACIONES

/// FUNCIONES DE MENU
void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2);
void manejarOpcion(int opcion, Jugador &j1, Jugador &j2);

/// FUNCIONES DE INGRESO DE DATOS PRIMARIOS
void nombresJugadores(Jugador &j1, Jugador &j2);

///FUNCIONES RANDOM
int generarNumero(int tamanio);

/// FUNCIONES JUGAR
void repartirCartas(Jugador &j1, Jugador &j2, Carta arr[]);
void mezclarMazo(Carta vArr[], int tam);
void contadorRonda(Jugador j1, Jugador j2);

/// FUNCIONES UNDER THE GUN
int clutchStarter(Jugador j1, Jugador j2);
bool noStraightHand(Jugador &j1, Jugador &j2) ;

///FUNCIONES DADO
int lanzarDado(int d);

