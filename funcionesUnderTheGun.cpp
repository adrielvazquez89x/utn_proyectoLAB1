#include <iostream>
#include "funciones.h"
#include "estructuras.h"


///Comprueba que no haya escalera y quien es el STARTER del juego.
bool straightHand (Jugador &j1, Jugador &j2)
{

    int contadorEscalera1 = 0;
    int contadorEscalera2 = 0;

    for(int x = 0; x < CARTAS_CORRAL; x ++)
    {
        // Comparamos los valores de cada posición con nuestro string de valores. Cuenta cada coincidencia.
        contadorEscalera1 += (j1.corral[x].valor == VALORES[x]) ? 1 : 0;
        contadorEscalera2 += (j2.corral[x].valor == VALORES[x]) ? 1 : 0;
    }
    return (contadorEscalera1 == 5 || contadorEscalera2 == 5) ? true : false;
}

/// Validar el RETURN 0 - SE USA UNA VEZ ESTA FX
int clutchStarter(Jugador j1, Jugador j2)
{
    // Inicialización de dos nuevos vectores de contadores.

     // indice [0] = A ; [1] = K ; [2] = Q ; [3] = J ; [4] = 10;

    int contadores1[CARTAS_CORRAL] = {};
    int contadores2[CARTAS_CORRAL] = {};

    // Alamcena en cada indice, cuantas cartas hay.
    for (int x = CARTAS_CORRAL -1; x >= 0; x--)
    {
        for (int y = CARTAS_CORRAL-1; y >= 0; y--)
        {
            contadores1[x] += (j1.corral[y].valor == VALORES[x]) ? 1 : 0;
            contadores2[x] += (j2.corral[y].valor == VALORES[x]) ?  1 : 0;
        }
    }

    ///Comparamos los contadores:

    for (int x = CARTAS_CORRAL-1; x >= 0; x--)
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
