#pragma once //guards
#include<iostream>
#include "estructuras.h"

///FUNCIONES DE MENU
void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[]);
void manejarOpcion(int opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[]);

///FUNCIONES DE INGRESO DATOS PRIMARIOS
void nombresJugadores(Jugador &j1, Jugador &j2);

///FUNCIONES RANDOM
int generarNumero(int tamanio);

///FUNCIONES JUGAR
void resetearMazo(Carta vMazo[]);
void mezclarMazo(Carta vArr[]);
void repartirCartas(Jugador &j1, Jugador &j2, Carta arr[]);
void mostrarRonda(Jugador &jA, Jugador &jB, int &contRonda);
void mostrarMazoEnMesa(Carta vMazo[]);
void mostrarCartasDeJugadores(Jugador &j1, Jugador &j2);
void validarIngreso(int &posicionCorral);


///FUNCIONES UNDER THE GUN
int clutchStarter(Jugador &j1, Jugador &j2);
bool straightHand (Jugador &j1, Jugador &j2);

///FUNCIONES DADO
int lanzarDado();
void dadoCaraUno(Jugador &j, Carta mazoMano[]);
void dadoCaraDos(Jugador &j, Carta mazo[]);
void dadoCaraTres(Jugador &j1, Jugador &j2);
void dadoCaraCuatro(Jugador &j);
void dadoCaraCinco(Jugador &j);
void dadoCaraSeis(Jugador &j1, Jugador &j2, Carta vMazo[], int &ultimaJugada);

///JUEGO IN SITU
void juegoInsitu(Jugador &j1, Jugador &j2, int returne, Carta vMazo[], Jugador &winner);

///FIN DE JUEGO
bool juegoFinalizado(Jugador &jugador);

///PUNTAJES
void mostrarPuntajes(Jugador &ganador, Jugador &perdedor, int ultimaJugada);
void mostrarHito(Jugador &j1, Jugador &j2);

///PROVISORIAS
int calcularPuntajes(Jugador &ganador, Jugador &perdedor, int ultimaJugada);

///CREDITOS
void mostrarCreditos (int &opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[]);
