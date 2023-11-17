#pragma once
using namespace std;

const int MAZO_PALO = 4, MAZO_VALOR=5, CARTAS_CORRAL=5, MAZO=20, MAZO_MESA=10;

//Strings para armar las estructuras
const string VALORES[CARTAS_CORRAL] = {"10", "J", "Q", "K", "A"};

const string PALOS[MAZO_PALO] = {"Diamante", "Pica", "Corazon", "Trebol"};

struct Carta
{
    string palo;
    string valor;
    bool enMazo;

     //Para el dado  cara CINCO
    bool bloqueada;
};

struct Jugador
{
    string nombre;
    Carta corral[CARTAS_CORRAL];
    int puntajeHistorico = 0;

    //Booleanos para puntajes
    bool sinPasarTurno = true;
    bool sinRobo = true;
};
