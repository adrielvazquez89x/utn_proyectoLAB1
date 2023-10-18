//#ifndef ESTRUCTURAS_H_INCLUDED
//#define ESTRUCTURAS_H_INCLUDED
#include <iostream>
#include <string>
#pragma once

using namespace std;

const int MAZO = 20;
const int MAZO_MANO = 10;
const int CARTAS_CORRAL = 5;

struct Carta
{
    string palo;
    string valor;
    bool enMazo = true;
};

struct Jugador
{
    string nombre;
    Carta corral[CARTAS_CORRAL];

};

//#endif // ESTRUCTURAS_H_INCLUDED
