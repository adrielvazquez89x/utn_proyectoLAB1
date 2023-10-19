#include<iostream>
#include<locale>
#include "funciones.h"
#include "estructuras.h"

using namespace std;
// Reglas del juego:
// 1. Las cartas se organizan de A a 10 de manera ordenada, se mezclan y reparten nuevamente.
// 2. Opción de nivel "Dios": empate en todo, por ejemplo, 2 Ases + 2 Ks + Js.
// 3. Determinación de quién comienza:
//    - Más Ases
//    - Más Ks
//    - Más Qs
//    - Más Js
//    - Más 10s
// B - Información de la ronda, jugadores, el turno del jugador y cartas correspondientes.
// C - Acción: Lanzamiento del dado
// mezclarDado(dado);
// cout << "El valor del dado ahora es: " << dado;

void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2)
{
    setlocale(LC_ALL, "Spanish");
    cout << endl << "CLUTCH " << endl; //Usamos el UNICODE
    cout << "--------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTAD�STICAS" << endl;
    cout << "3 - CR�DITOS" << endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "Ingrese su opci�n: ";
    cin >> opcion;
    manejarOpcion(opcion, j1, j2);
}


void manejarOpcion(int opcion, Jugador &j1, Jugador &j2)
{
    setlocale(LC_ALL, "Spanish");
    switch (opcion)
    {
    case 1: //Jugar
    {
        //Inicio con el mazo ordenado
        Carta vMazo[MAZO] =
        {
            {"Diamante", "10", true}, {"Diamante", "J", true}, {"Diamante", "Q", true}, {"Diamante", "K", true}, {"Diamante", "A", true},
            {"Corazon", "10", true}, {"Corazon", "J", true}, {"Corazon", "Q", true}, {"Corazon", "K", true}, {"Corazon", "A", true},
            {"Pica", "10", true}, {"Pica", "J", true}, {"Pica", "Q", true}, {"Pica", "K", true}, {"Pica", "A", true},
            {"Trebol", "10", true}, {"Trebol", "J", true}, {"Trebol", "Q", true}, {"Trebol", "K", true}, {"Trebol", "A", true}
        };
        // INGRESO NOMBRES
        nombresJugadores(j1, j2);

        // MEZCLAR EL MAZO
        //   mezclarMazo(vMazo, MAZO); //esto mezcla el mazo completo


        // SELECCIONAR CARTAS EN JUEGO
        repartirCartas(j1, j2, vMazo);
        mezclarMazo(vMazo, MAZO_MANO); //esto mezcla las cartas que quedan a un costado
        contadorRonda(j1, j2);
        repartirCartas(j1, j2, vMazo); //Crea el corral de cada jugador

        cout << "elegirOrden:" << clutchStarter(j1, j2);

        Jugador j3;
        Jugador j4;
        j3.corral[0].valor = "J", j3.corral[1].valor = "J", j3.corral[2].valor = "Q", j3.corral[3].valor = "K", j3.corral[4].valor = "A";
        j4.corral[0].valor = "10", j4.corral[1].valor = "J", j4.corral[2].valor = "Q", j4.corral[3].valor = "K", j4.corral[4].valor = "A";

        if(noStraightHand(j3, j4))
        {
            cout << "HOLA es VERDADERO";
        }
        else
        {
            cout << "CHAU es FALSO";
        }

        cout << "Lanzar dado: " <<  lanzarDado(6) << " <----" << endl;
        cout << "Lanzar dado: " <<  lanzarDado(6) << " <----" << endl;
        cout << "Lanzar dado: " <<  lanzarDado(6) << " <----" << endl;

        break;
    }
    case 2:
        //estadisticas();
        break;
    case 3:
        //creditos();
        break;
    case 0:
        cout << "Gracias por jugar CLUTCH" << endl;
        break;
    default:
        cout << "El numero ingresado no es valido. Por favor ingrese una opcion valida." << endl;
        mostrarMenu(opcion, j1, j2);
        break;
    }
}
