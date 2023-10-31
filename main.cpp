#include <iostream>
#include <locale>
#include <cstdlib> // Necesario para rand() y srand()
#include <ctime>   // Necesario para time()
#include "rlutil.h" //Posicionar, esconder, borrar pantalla, colores.
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
  rlutil::setBackgroundColor(rlutil::WHITE);
  rlutil::cls();//Borra pantalla para ver el fondo verde
  rlutil::setColor(rlutil::BLACK);

  setlocale(LC_ALL, "Spanish");
  srand(time(NULL));

  int opcion; // INGRESO AL SWITCH DE OPCIONES
  Jugador jugador1;
  Jugador jugador2;

 //Array para las estadiscicas
  Jugador estadisticas[CARTAS_CORRAL] = {};

  //FUNCION MENU()
  mostrarMenu(opcion, jugador1, jugador2, estadisticas); //MUESTRA el menu y maneja la opcion elegida

  return 0;
}
