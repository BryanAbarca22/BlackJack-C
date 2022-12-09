#ifndef MAZO_H
#define MAZO_H

#include "Carta.h"

typedef struct Mazo {
	Carta ArrayCartas[52];
}Mazo;
void initMazo(Mazo* oMazo);
void initTipo(Mazo* oMazo, int start, int _simbolo);
void Desordenar(Mazo* oMazo);
#endif // !MAZO_H
