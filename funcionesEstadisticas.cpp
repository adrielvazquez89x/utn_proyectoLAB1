#include <iostream>
#include <iomanip> // Necesario para setw
#include "rlutil.h"
#include "funciones.h"
#include "estructuras.h"


void mostrarHito(Jugador &j1, Jugador &j2)
{
    Jugador jugadorHito;
    string jugadoresEmpateHitoNmbre[2];
    int jugadoresEmpateHitoPje;

    if(j1.puntajeHistorico == j2.puntajeHistorico)
    {
        jugadoresEmpateHitoNmbre[0] = j1.nombre;
        jugadoresEmpateHitoNmbre[1] = j2.nombre;
        jugadoresEmpateHitoPje = j1.puntajeHistorico;
    }
    else
    {
        jugadorHito = (j1.puntajeHistorico > j2.puntajeHistorico) ? j1 : j2;
    }

    cout << endl << "CLUTCH" << endl;
    cout << "--------------------------------------------" << endl;
    if (j1.puntajeHistorico == j2.puntajeHistorico)
    {
        cout << "HITO -> EMPATE ENTRE: " << jugadoresEmpateHitoNmbre[0] << " y " << jugadoresEmpateHitoNmbre[1] << endl;
        cout << "--------------------------------------------" << endl;
        cout << "TOTAL -> " << jugadoresEmpateHitoPje << " Puntos" << endl;
        cout << "Presione una tecla para continuar..." << endl;
        rlutil::anykey();
    }
    else
    {
        cout << "HITO" << setw(31) << " | " << jugadorHito.nombre << endl;
        cout << "--------------------------------------------" << endl;
        cout << "TOTAL: " << setw(28) << " | " << jugadorHito.puntajeHistorico  << " puntos" << endl;
        cout << "Presione una tecla para continuar..." << endl;
        rlutil::anykey();

    }
    rlutil::cls();
}

