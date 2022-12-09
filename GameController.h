#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Jugador.h"
#include "Mazo.h"
typedef struct GM{
	int numberPlayers;
	Jugador jugadores[7];
	Mazo StackCartas[6];
	Jugador Crupier;
	int indexMazo[6];
	int currentMazo;
	int TurnoJugador;
}GM;
GM GameMaster;
void start();
void getNumberPlayers();
void initPlayers();
void initMazos();
void initCrupier();
void repartirCartas();
void PintarCrupier();
void PintarJugadores();
void Juego();
int AccionesJugador();
int pedir();
int plantarse();
void Doblar();
void tomarApuestas();
int FinJuego();

#endif // !GAMECONTROLLER_H
