#include<iostream>
#include<locale>
#include<stdio.h>
#include "rlutil.h"
#include "funciones.h"
#include "estructuras.h"

using namespace std;


void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[])
{

    setlocale(LC_ALL, "Spanish");

    cout << endl << "CLUTCH " << endl; //Usamos el UNICODE
    cout << "--------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;
    manejarOpcion(opcion, j1, j2, vEstadisticas);
}

void manejarOpcion(int opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[])
{
    setlocale(LC_ALL, "Spanish");
    switch (opcion)
    {
    case 1: //Jugar
    {
        rlutil::cls();

        // INGRESO NOMBRES
        nombresJugadores(j1, j2);

        cout <<"ENHORABUENA COMENZAMOS EL JUEGO!!!" << endl;
        cout << "ESTAS SON LAS CARTAS INICIALES" << endl;

        // Declaramos el mazo.
        Carta vMazo[MAZO];

        // Restea y pone por default.
        resetearMazo(vMazo);

        // Mostramos el mazo completo y ordenado.
        mostrarMazoEnMesa(vMazo);

        // Mezclamos el orden de las cartas.
        mezclarMazo(vMazo);

        // Repartimos las cartas a los jugadores.
        repartirCartas(j1, j2, vMazo);

        // Mostramos las manos de los jugadores.
        mostrarCartasDeJugadores(j1, j2);

        //Valida que no haya escalera
        while(straightHand(j1, j2))
        {
            cin.ignore();
            cout << "OPS SALIO ESCALERA! VOLVEREMOS A REPARTIR...";
            // Limpiar el bufer de entrada de cualquier caracter pendiente, incluyendo el carácter de nueva línea.
            cout << "Mezclando mazo, presione enter para continuar...";
            // Espera a que se presione una tecla
            getchar();

            //resetear mazo inicial y volver a repartir cartas
            resetearMazo(vMazo);
            repartirCartas(j1, j2, vMazo);
        }

        rlutil::setColor(rlutil::RED);
        cout << "DETERMINEMOS QUIEN COMIENZA EL JUEGO" << endl;
        cout << "Veremos quien tiene mas A, caso de empate seguiremos comparando con los siguientes valores (K, Q, J, 10)" << endl;
        rlutil::setColor(rlutil::BLACK);

        //Valida quien inicia el juego y que no haya empate en el inicio
        int starter = clutchStarter(j1, j2);
        while(starter == 0)
        {
            // Limpiar el búfer de entrada de cualquier carácter pendiente, incluyendo el carácter de nueva línea
            cin.ignore();
            cout << "***** OPS SALIO EMPATE... *****" << endl;
            cout << "DETERMINEMOS QUIEN COMIENZA EL JUEGO, presione enter para continuar...";
            getchar(); // Espera a que se presione una tecla
            resetearMazo(vMazo);
            mezclarMazo(vMazo);
            repartirCartas(j1,j2, vMazo);
            starter = clutchStarter(j1, j2);
        }

        cout << endl << "-> El jugador que inicia es: " << ((starter == 1) ? j1.nombre : j2.nombre) << " <-" << endl << endl;

        juegoInsitu(j1, j2, starter, vMazo, vEstadisticas);

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
        mostrarMenu(opcion, j1, j2, vEstadisticas);
        break;
    }
}



