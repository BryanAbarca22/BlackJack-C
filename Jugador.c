#include "Jugador.h"

void initJugador(Jugador* oJugador) {

	oJugador->CurrentIndex = 0;
	oJugador->CurrentIndexDup = 0;
	oJugador->apuesta = 0;
	oJugador->apuestaDup = 0;
	oJugador->duplicado = 0;
	Carta carta = { NULL, NULL, NULL };
	for (int i = 0; i < 21; i++) {
		oJugador->MazoJugador[i] = carta;
	}
}
int MazoValor(Jugador oJugador) {
	int valor = 0;
	for (int i = 0; i < 21; i++) {
		if (oJugador.MazoJugador[i].value != NULL) {
			valor += oJugador.MazoJugador[i].value;
		}
	}
	return valor;
}
int MazoValorOpt(Jugador oJugador) {
	int valor;
	for (int i = 0; i < 21; i++) {
		if (oJugador.MazoJugador[i].OpValue != NULL) {
			valor = oJugador.MazoJugador[i].OpValue;
		}
		else if (oJugador.MazoJugador[i].value != NULL) {
			valor = oJugador.MazoJugador[i].value;
		}
	}
	return valor;
}
int MazoValorD(Jugador oJugador) {
	int valor;
	for (int i = 0; i < 21; i++) {
		if (oJugador.MazoDuplicado[i].value != NULL) {
			valor = oJugador.MazoDuplicado[i].value;
		}
	}
	return valor;
}
int MazoValorDOpt(Jugador oJugador) {
	int valor;
	for (int i = 0; i < 21; i++) {
		if (oJugador.MazoDuplicado[i].OpValue != NULL) {
			valor = oJugador.MazoDuplicado[i].OpValue;
		}
		else if (oJugador.MazoDuplicado[i].value != NULL) {
			valor = oJugador.MazoDuplicado[i].value;
		}
	}
	return valor;
}
void addCarta(Jugador* oJugador, Carta oCarta) {
	int i = oJugador->CurrentIndex;
	oJugador->MazoJugador[i] = oCarta;
	oJugador->CurrentIndex++;
}
void addCartaD(Jugador* oJugador, Carta oCarta) {
	int i = oJugador->CurrentIndexDup;
	oJugador->MazoDuplicado[i] = oCarta;
	oJugador->CurrentIndexDup++;
}
void AgregarApuesta(Jugador oJugador, int Apuesta) {
	oJugador.apuesta += Apuesta;
}
void AgregarApuestaD(Jugador oJugador, int Apuesta) {
	oJugador.apuestaDup += Apuesta;
}
void imprimirCartas(Jugador *oJugador) {
	for (int i = 0; i < 21; i++) {
		if (oJugador->MazoJugador[i].value == NULL) {
			printf("%s ", oJugador->MazoJugador[i].nombre);
		}
	}
}