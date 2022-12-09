#include "Mazo.h"
void initMazo(Mazo* oMazo) {
	
	//init corazones
	initTipo(oMazo, 0, 3);//char 3 para corazon
	//init Diamantes;
	initTipo(oMazo, 13, 4);//char 4 para diamantes
	//init Trevol
	initTipo(oMazo, 26, 5);//char 5 para trevol
	//init bastos
	initTipo(oMazo, 39, 6);//char 6 bastos
}
void initTipo(Mazo* oMazo, int start, int _simbolo) {
	char simbolo = _simbolo;
	int end = start + 12;
	int offset = start - 1;
	for (int i = start; i <= end; i++) {

		if (i - offset == 1) {
			oMazo->ArrayCartas[i].value = i - offset;
			oMazo->ArrayCartas[i].OpValue = 11;
			oMazo->ArrayCartas[i].nombre[0] = 'A';
			oMazo->ArrayCartas[i].nombre[1] = simbolo;
			oMazo->ArrayCartas[i].nombre[2] = ' ';
			//printf(oMazo->ArrayCartas[i].nombre);
		}
		else if (i - offset < 10) {
			oMazo->ArrayCartas[i].value = i - offset;
			oMazo->ArrayCartas[i].nombre[0] = i - offset + '0';
			oMazo->ArrayCartas[i].nombre[1] = simbolo;
			oMazo->ArrayCartas[i].nombre[2] = ' ';
			//printf(oMazo->ArrayCartas[i].nombre);
		}
		else if (i - offset == 10) {
			oMazo->ArrayCartas[i].value = i - offset;
			oMazo->ArrayCartas[i].nombre[0] = 1 + '0';
			oMazo->ArrayCartas[i].nombre[1] = '0';
			oMazo->ArrayCartas[i].nombre[2] = simbolo;
			//printf(oMazo->ArrayCartas[i].nombre);
		}
		else if (i - offset == 11) {
			oMazo->ArrayCartas[i].value = 10;
			oMazo->ArrayCartas[i].nombre[0] = 'J';
			oMazo->ArrayCartas[i].nombre[1] = simbolo;
			oMazo->ArrayCartas[i].nombre[2] = ' ';
			//printf(oMazo->ArrayCartas[i].nombre);
		}
		else if (i - offset == 12) {
			oMazo->ArrayCartas[i].value = 10;
			oMazo->ArrayCartas[i].nombre[0] = 'Q';
			oMazo->ArrayCartas[i].nombre[1] = simbolo;
			oMazo->ArrayCartas[i].nombre[2] = ' ';
			//printf(oMazo->ArrayCartas[i].nombre);
		}
		else if (i - offset == 13) {
			oMazo->ArrayCartas[i].value = 10;
			oMazo->ArrayCartas[i].nombre[0] = 'K';
			oMazo->ArrayCartas[i].nombre[1] = simbolo;
			oMazo->ArrayCartas[i].nombre[2] = ' ';
			//printf(oMazo->ArrayCartas[i].nombre);
		}
	}
	//printf("\n");
}
void Desordenar(Mazo * oMazo) {
	
	for (int i = 0; i < (52/2); i++) {
		int r = rand() % 52;
		Carta aux = oMazo->ArrayCartas[i];
		oMazo->ArrayCartas[i] = oMazo->ArrayCartas[r];
		oMazo->ArrayCartas[r] = aux;
	}
}