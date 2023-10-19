#include <iostream>

#include "funciones.h"
#include "estructuras.h"

using namespace std;

/// COMPRUEBA STARTER
int clutchStarter(Jugador j1, Jugador j2)
{
    string valores[CARTAS_CORRAL] = {"A", "K", "Q", "J", "10"};
    int contadores1[CARTAS_CORRAL] = {}; // indice [0] = A, [1] = K, [2] = Q, etc...
    int contadores2[CARTAS_CORRAL] = {};

    // contar cada carta jugador 1
    for (int x = 0; x < CARTAS_CORRAL; x++)
    {
        for (int y = 0; y < CARTAS_CORRAL; y++)
        {
            contadores1[x] += (j1.corral[y].valor == valores[x]) ? 1 : 0;
            contadores2[x] += (j2.corral[y].valor == valores[x]) ? 1 : 0;
        }

    }

// comparar

    for (int x = 0; x < CARTAS_CORRAL; x++)
    {
        if (contadores1[x] > contadores2[x])
        {
            return 1;
        }
        else if (contadores1[x] < contadores2[x])
        {
            return 2;
        }

    }
    return 0;
}

/// COMPRUEBA QUE NO HAYA ESCALERA INICIAL
bool noStraightHand(Jugador &j1, Jugador &j2)  ///10-J-Q-K-A VER DONDE LO USAMOS
{
    string valores[CARTAS_CORRAL] = {"10", "J", "Q", "K", "A"};///Solo compara

    int contadorEscalera1 = 0;
    int contadorEscalera2 = 0;

    for(int x = 0; x < CARTAS_CORRAL; x ++)
    {
        contadorEscalera1 += (j1.corral[x].valor == valores[x]) ? 1 : 0;
        contadorEscalera2 += (j2.corral[x].valor == valores[x]) ? 1 : 0;
    }
    return (contadorEscalera1 == 5 || contadorEscalera2 == 5) ? true : false;

}


