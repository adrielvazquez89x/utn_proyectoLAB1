#include <iostream>
#include <locale>
#include "estructuras.h"
#include "funciones.h"

using namespace std;

// FUNCIONES PARA LA SECCION JUGAR

void nombresJugadores(Jugador &j1, Jugador &j2)
{
    char confirmacion;
    do
    {
        cout << std::endl << "CLUTCH" << endl;
        cout << "---------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres:" << endl;
        cout << endl;
        cout << "Participante 1: ";
        cin.ignore(); // Limpiar el buffer del teclado antes de leer la cadena
        getline(cin, j1.nombre); //es para poner espacios entre nombres
        cout << "Participante 2: ";
        getline(cin, j2.nombre);

        cout << ("Confirmar nombres (S/N): ");
        cin >> confirmacion;
        while (!(confirmacion == 'S' || confirmacion == 's' || confirmacion == 'N' || confirmacion == 'n'))
        {
            cout << "Por favor ingrese solo 'S' o 'N'." << endl;
            cout << ("Confirmar nombres(S/N): "); //no sale el '¿'
            cin >> confirmacion;
        }

        confirmacion = (confirmacion == 's') ? 'S': confirmacion; //para no usar funcion std::touppers
        confirmacion = (confirmacion == 'n') ? 'N': confirmacion; //para no usar funcion std::touppers
        cout << ((confirmacion == 'N') ? "Ingrese los nombres nuevamente: " : "") << endl; // si es 'n' vuelve a empezar el while
    }
    while(confirmacion != 'S');

    cout << "Nombres confirmados: " << j1.nombre << " VS " << j2.nombre << endl;
}

//void generarNuevoIndice(int arr[])
//{
//    for (int x = 0; x < 20; x++)
//    {
//        arr[x] = generarNumero(); // Generamos números
//
//        for (int y = 0; y < x; y++) // Acá habilitamos un nuevo ciclo para poder usar su indice.
//        {
//            while (arr[x] == arr[y]) // Acá, comparamos que existan duplicados. Y mientas existan coincidencias, que siga iterando.
//            {
//                arr[x] = generarNumero(); // Si el número está repetido, genera otro
//                y = 0;                    // Restablece y para volver a verificar desde el principio
//            }
//        }
//    }
//}

void selecCartas(Jugador j1, Jugador j2, Carta arr[], Carta vMazoMano[])
{
    int aleatorio;
    for(int x = 0; x < MAZO_MANO; x++)
    {
        aleatorio = generarNumero(MAZO);
        if(arr[aleatorio].enMazo == true)
        {
            vMazoMano[x] = arr[aleatorio];
            arr[aleatorio].enMazo = false;
        }
        else
        {
            x--;
        }
    }


    for(int x = 0; x < 20; x++)
    {
        cout << "CARTA ACTUAL: " << arr[x].palo << " " << arr[x].valor << " " << arr[x].enMazo << endl;
    }

    for(int i = 0; i < MAZO_MANO; i++)
    {
        cout << "CARTA en juego: " << vMazoMano[i].palo << " " << vMazoMano[i].valor << " " << vMazoMano[i].enMazo << endl;
    }

}

void mezclarMazo(Carta vArr[], int tam)
{
    int aleatorio1, aleatorio2;
    Carta aux;
    for(int x = 0; x < 100; x ++)
    {
        aleatorio1= generarNumero(tam);
        aleatorio2= generarNumero(tam);
        aux = vArr[aleatorio1];
        vArr[aleatorio1] = vArr[aleatorio2];
        vArr[aleatorio2] = aux;
    }

    for(int x = 0; x<10; x++)
    {
        cout << "Cartas mezcladas " << vArr[x].palo << " " << vArr[x].valor << endl;
    }
}

void repartirCartas(Carta vMazoMano[], Jugador &jugador1, Jugador &jugador2)
{
    for (int x = 0; x < 10; x++)
    {
        if (x % 2 == 0) // Simulamos una repartida "clásica" o intercalada. Las reglas no especifica si es asi, o cinco y cinco. Por lo que prefiero esta.
        {
            jugador1.corral[x/2] = vMazoMano[x];

        }
        else
        {
            jugador2.corral[x/2] = vMazoMano[x];

        }
    }
}
