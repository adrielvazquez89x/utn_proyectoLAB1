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

    do
    {
        cout << endl << "CLUTCH " << endl; //Usamos el UNICODE
        cout << "--------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "---------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        if(opcion < 0 || opcion > 3)
        {
            cout << "ERROR: " << opcion << " no es un numero valido. Presione una tecla para continuar...." << endl;
            rlutil::anykey();
            rlutil::cls();//Borra pantalla para ver el fondo verde
        }
        else
        {
            manejarOpcion(opcion, j1, j2, vEstadisticas);
        }
    }
    while(opcion !=0);
}

void manejarOpcion(int opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[])
{
    setlocale(LC_ALL, "Spanish");
    switch (opcion)
    {
    case 1: //Jugar
    {
        rlutil::cls(); //Borra lo que estaba antes al elegir una opcion
        nombresJugadores(j1, j2);// INGRESO NOMBRES
        rlutil::cls();
        cout << "ENHORABUENA COMENZAMOS EL JUEGO!!!" << endl;
        cout << "ESTAS SON LAS CARTAS INICIALES" << endl;

        Carta vMazo[MAZO];//Declaro el mazo
        resetearMazo(vMazo);//resetea y pone default)
        mostrarMazoEnMesa(vMazo);//Mostramos el mazo ordenado
        mezclarMazo(vMazo); //esto mezcla el mazo completo
        repartirCartas(j1, j2, vMazo);
        mostrarCartasDeJugadores(j1,j2);

        j1.corral[0].valor = "10", j1.corral[1].valor = "J", j1.corral[2].valor = "Q", j1.corral[3].valor = "A", j1.corral[4].valor = "K";
        j2.corral[0].valor = "10", j2.corral[1].valor = "J", j2.corral[2].valor = "Q", j2.corral[3].valor = "A", j2.corral[4].valor = "A";


        //Valida que no haya escalera
        while(straightHand(j1, j2))
        {
            cin.ignore(); // Limpiar el buffer de entrada de cualquier caracter pendiente, incluyendo el caracter de nueva l�nea
            cout << "OPS SALIO ESCALERA! VOLVEREMOS A REPARTIR...";
            cout << "Mezclando mazo, presione enter para continuar....";
            getchar(); // Espera a que se presione una tecla

            //resetear mazo inicial y volver a repartir cartas
            resetearMazo(vMazo);
            mezclarMazo(vMazo);
            repartirCartas(j1,j2,vMazo);
            mostrarCartasDeJugadores(j1,j2);
        }


        rlutil::setColor(rlutil::RED);
        cout << "DETERMINEMOS QUIEN COMIENZA EL JUEGO" << endl;
        cout << "Veremos quien tiene mas A, caso de empate seguiremos comparando con los siguientes valores (K, Q, J, 10)" << endl;
        rlutil::setColor(rlutil::BLACK);

        //Valida quien inicia el juego y que no haya empate en el inicio
        int starter = clutchStarter(j1, j2);
        while(starter == 0)
        {
            cin.ignore(); // Limpiar el búfer de entrada de cualquier carácter pendiente, incluyendo el carácter de nueva línea
            cout << "*****OPS SALIO EMPATE...*****" << endl;
            cout << "DETERMINEMOS QUIEN COMIENZA EL JUEGO, presione enter para continuar....";
            getchar(); // Espera a que se presione una tecla
            resetearMazo(vMazo);
            mezclarMazo(vMazo);
            repartirCartas(j1,j2, vMazo);
            mostrarCartasDeJugadores(j1,j2);
            starter = clutchStarter(j1, j2);
        }

        cout << "-> El jugador que inicia es: " << ((starter == 1) ? j1.nombre : j2.nombre) << " <-" << endl << endl;

        ///ACA se tiene que guardar el dato
        Jugador ganador;
        juegoInsitu(j1, j2, starter, vMazo, ganador);

        j1 = ganador;
        cout << "Ganador: " << ganador.puntajeHistorico << endl;


        break;
    }
    case 2:
        //mostrarHito(j1,j2);
        cout << j1.nombre << " y su puntaje es: " << j1.puntajeHistorico << endl;
        cout << j2.nombre << " y su puntaje es: " << j2.puntajeHistorico << endl;

        break;

    case 3:
        mostrarCreditos(opcion, j1, j2, vEstadisticas);
        break;

    case 0:
        cout << "SALIENDO DEL JUEGO. GRACIAS POR JUGAR CLUTCH" << endl;
        break;

    }
}





