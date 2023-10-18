#include <iostream>
#include "estructuras.h"
#include "funciones.h"

using namespace std;

int generarNumero(int tamanio)
{
    int random;
    random = rand() % tamanio;
    return random;
}


