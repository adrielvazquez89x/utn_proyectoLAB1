#include <iostream>
#include <locale>
#include <ctime>
#include <cstdlib>
#include "estructuras.h"
#include "funciones.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Spanish");

    // Menu con 3 funciones => 1 - Jugar(), 2 - Estadisticas(), 3 - Creditos;

    // 1 - JUGAR()
    // A - INGRESO NOMBRES
    //  => MESLCAR EL MAZO
    //  => ASIGNAR CARTAS
    //  => CHEQUEAR QUIEN JUEGA PRIMERO. => SI ALGUNO TIENE ESCALERA SERVIDA, SE REPARTE NUEVAMENTE.
    //      => JUEGA PRIMERO EL QUE TENGA MAS A, SINO MAS K, O HASTA LLEGAR A 10
    //      EN CASO DE EMPATE, BARAJAR DE NUEVO.
    // B - INFORMACIÓN DE RONDA - JUGADORES - EL TURNO DEL JGUADOR - CARTAS QUE LE CORRESPONDEN
    // C - ACCION: LANZAMIENTO DEL DADO

    // Funcion MENU
    srand(time(0));

    int opcion;

    Jugador jugador1 = {"Jugador 1", {}};
    Jugador jugador2 = {"Jugador 2", {}};

    Carta vMazo[MAZO] =
    {
        {"Diamante", "10", true}, {"Diamante", "J", true}, {"Diamante", "Q", true}, {"Diamante", "K", true}, {"Diamante", "A", true},
        {"Corazon", "10", true}, {"Corazon", "J", true}, {"Corazon", "Q", true}, {"Corazon", "K", true}, {"Corazon", "A", true},
        {"Pica", "10", true}, {"Pica", "J", true}, {"Pica", "Q", true}, {"Pica", "K", true}, {"Pica", "A", true},
        {"Trebol", "10", true}, {"Trebol", "J", true}, {"Trebol", "Q", true}, {"Trebol", "K", true}, {"Trebol", "A", true}
    };

    Carta vMazoEnMano[MAZO_MANO] = {};

    // mostrarMenu(opcion,jugador1, jugador2);
    mezclarMazo(vMazo, MAZO);
    selecCartas( jugador1,  jugador2,  vMazo, vMazoEnMano);
    mezclarMazo(vMazo, MAZO_MANO);

    return 0;
}
