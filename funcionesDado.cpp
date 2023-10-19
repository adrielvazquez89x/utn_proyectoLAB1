#include <iostream>

#include "funciones.h"
#include "estructuras.h"

using namespace std;

int lanzarDado(int d)
{
    int dado = generarNumero(d) + 1;

    return dado;
}
