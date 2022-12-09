#ifndef JUGADOR_H
#define JUGADOR_H
#include "Carta.h"
typedef struct Jugador {
	Carta MazoJugador[21];
	Carta MazoDuplicado[21];
	int CurrentIndex;
	int CurrentIndexDup;
	int apuesta;
	int apuestaDup;
	int duplicado;
}Jugador;

void initJugador(Jugador* oJugador);
int MazoValor(Jugador oJugador);
int MazoValorOpt(Jugador oJugador);
int MazoValorD(Jugador oJugador);
int MazoValorDOpt(Jugador oJugador);
void addCarta(Jugador* oJugador, Carta oCarta);
void addCartaD(Jugador* oJugador, Carta oCarta);
void AgregarApuesta(Jugador oJugador, int Apuesta);
void AgregarApuestaD(Jugador oJugador, int Apuesta);
void imprimirCartas(Jugador oJugador);

#endif // !JUGADOR_H
