#include "GameController.h"
void start() {
	GameMaster.currentMazo  = 0;
	GameMaster.TurnoJugador = 0;
	srand(time(NULL));//inicialisacion de srand
	getNumberPlayers();
	initPlayers();
	initCrupier();
	initMazos();
	repartirCartas();
	repartirCartas();
	Juego();
}
void getNumberPlayers() {
	int a = 0;
	printf("Por favor digite el numero de jugadores en este juego(No puede ser mayor a 7)\n");
	int w = scanf_s("%i", &a);
	fflush(stdin);
	if (w == 0) {
		int x;
		while ((x = getchar()) != EOF && x != '\n');//descarta valores del buffer
		printf("Por favor ingrese un caracter valido\n");
		getNumberPlayers();
	}
	else if (w != EOF) {
		if (a > 7) {
			printf("El numero de jugadores no puede ser mayor a 7\n");
			getNumberPlayers();
		}
		else if (a <= 0) {
			printf("El numero de jugadores no puede menor o igual a 0\n");
			getNumberPlayers();
		}
		else {
			GameMaster.numberPlayers = a;
			system("cls");
		}
	}
	else {
		printf("Por favor ingrese un caracter valido\n");
		getNumberPlayers();
	}
	
}
void initPlayers() {
	for (int i = 0; i < GameMaster.numberPlayers; i++) {
		Jugador temporal;
		initJugador(&temporal);
		GameMaster.jugadores[i] = temporal;
	}
}
void initMazos() {
	for (int i = 0; i < 6; i++) {
		initMazo(&GameMaster.StackCartas[i]);
		Desordenar(&GameMaster.StackCartas[i]);
	}
	
}
void initCrupier() {
	GameMaster.Crupier.apuesta = NULL;//crupier no hace apuestas
	GameMaster.Crupier.apuestaDup = NULL;//no tiene dobles
	GameMaster.Crupier.CurrentIndex = 0;
	GameMaster.Crupier.CurrentIndexDup = NULL;
	Carta carta = { NULL, NULL, NULL };
	for (int i = 0; i < 21; i++) {
		GameMaster.Crupier.MazoJugador[i] = carta;
	}
}
void repartirCartas() {
	int a = GameMaster.currentMazo;
	int b;
	if (GameMaster.currentMazo+1 > 7) {
		GameMaster.currentMazo++;
	}
	else {
		GameMaster.currentMazo = 0;
	}
	for (int i = 0; i < GameMaster.numberPlayers; i++) {
		b = GameMaster.indexMazo[a];
		GameMaster.indexMazo[a]++;
		addCarta(&GameMaster.jugadores[i], GameMaster.StackCartas[a].ArrayCartas[b]);

	}
	b = GameMaster.indexMazo[a];
	addCarta(&GameMaster.Crupier, GameMaster.StackCartas[a].ArrayCartas[b]);
}

void PintarCrupier() {
	printf("Cartas de Crupier: ");
	for (int i = 0; i < GameMaster.Crupier.CurrentIndex; i++) {
		printf("%s ", GameMaster.Crupier.MazoJugador[i].nombre);
	}
}
void PintarJugadores() {

	printf("\nCartas de Jugadores: ");
	for (int j = 0; j < GameMaster.numberPlayers; j++) {

		printf("\n");

		printf("Jugador #%i : ",j + 1);

		for (int i = 0; i < GameMaster.jugadores[j].CurrentIndex; i++) {
			printf("%s ", GameMaster.jugadores[j].MazoJugador[i].nombre);
		}
		if (GameMaster.jugadores[j].duplicado == 1) {
			for (int i = 0; i < GameMaster.jugadores[j].CurrentIndex; i++) {
				printf("%s ", GameMaster.jugadores[j].MazoDuplicado[i].nombre);
			}
		}
		
	}
	

}

void Juego() {
	int opcion = 1;
	int accion = 0;
	tomarApuestas();
	
		  
	
	AccionesJugador();

	
	
	
}
int AccionesJugador() {
	int ac = 0;
	PintarCrupier();
	PintarJugadores();
	printf("\nTurno del Jugador #%i \n",GameMaster.TurnoJugador+1);
	printf("1.Pedir\n");
	printf("2.Planarse\n");
	printf("3.Doblar Apuesta\n");
	int err = scanf_s("%d", &ac);
	if (err > 0) {
		switch (ac)
		{
		case 1:
			if (pedir() == 1) {
				AccionesJugador();
			}
			break;
		case 2:

			if (plantarse() ==1) {
				AccionesJugador();
			}
			break;
		case 3:
			Doblar();
			AccionesJugador();
			break;
		default:
			printf("\nPor favor digite una opcion valida\n");
			return AccionesJugador();// se llama a si mismo recursivamente para optener la accion
			break;
		}
	}
	else {
		int x;
		while ((x = getchar()) != EOF && x != '\n');//descarta valores del buffer
		printf("Por favor digite un caracter valido");
		return AccionesJugador();
	}
	
	return 1;
}
int pedir() {
	system("cls");
	printf("Jugador #%i Pidio carta\n", GameMaster.TurnoJugador+1);
	int p = GameMaster.TurnoJugador;
	GameMaster.jugadores[p];
	int a = GameMaster.currentMazo;
	int b;
	b = GameMaster.indexMazo[a];
	GameMaster.indexMazo[a]++;
	if (GameMaster.currentMazo + 1 > 7) {
		GameMaster.currentMazo++;
	}
	else {
		GameMaster.currentMazo = 0;
	}
	addCarta(&GameMaster.jugadores[p], GameMaster.StackCartas[a].ArrayCartas[b]);
	if (MazoValor(GameMaster.jugadores[p]) >= 21) {
		printf("Jugador se planta Con Mazo Valor: %i\n", MazoValor(GameMaster.jugadores[p]));
		if (GameMaster.TurnoJugador + 1 < GameMaster.numberPlayers) {
			GameMaster.TurnoJugador++;
		}
		else {
			//FinJuego();
			GameMaster.TurnoJugador = 0;
			return FinJuego();
			
		}
	}
	return 1;
}
int plantarse() {
	system("cls");
	printf("Jugador #%i se planto\n", GameMaster.TurnoJugador + 1);
	if (GameMaster.TurnoJugador + 1 < GameMaster.numberPlayers) {
		GameMaster.TurnoJugador++;
	}
	else {
		//FinJuego();
		GameMaster.TurnoJugador = 0;
		return FinJuego();
	}
	return 1;
	
}
void Doblar() {
	system("cls");
	printf("Jugador #%i doblo su apuesta\n", GameMaster.TurnoJugador + 1);
	GameMaster.jugadores;
}
void tomarApuestas(){
	
	for (int i = 0; i < GameMaster.numberPlayers; i++) {
		printf("Jugador #%i agrege numero de apuesta deseada ", i+1);
		int a;
		int err = scanf_s("%i", &a);
		if (err > 0) {
			GameMaster.jugadores[i].apuesta = a;
		}
		else {
			int x;
			while ((x = getchar()) != EOF && x != '\n');//descarta valores del buffer
			printf("Por favor digite un caracter valido");
			i = GameMaster.numberPlayers;
			tomarApuestas();
		}

	}
}
void CrupierJuego() {
	int val = MazoValor(GameMaster.Crupier);
	printf("\nEl mazo del crupier tiene un valor de %i\n", val);
	if (val < 16) {
		int a = GameMaster.currentMazo;
		int b;
		b = GameMaster.indexMazo[a];
		GameMaster.indexMazo[a]++;
		if (GameMaster.currentMazo + 1 > 7) {
			GameMaster.currentMazo++;
		}
		else {
			GameMaster.currentMazo = 0;
		}
		printf("El crupier pide carta \n");
		addCarta(&GameMaster.Crupier, GameMaster.StackCartas[a].ArrayCartas[b]);
		CrupierJuego();
		PintarCrupier();
	}
	else {
		printf("\nEl crupier se planta \n");
		PintarCrupier();
	}
}
void repartirApuestas() {
	printf("\n\n\nRepartiendo Apuestas\n");
	for (int i = 0; i < GameMaster.numberPlayers; i++) {
		if ((MazoValor(GameMaster.jugadores[i]) == 21 || MazoValorOpt(GameMaster.jugadores[i]) == 21) && MazoValor(GameMaster.Crupier) != 21) {
			printf("Jugador #%i gana: %f\n Con un BlackJack\n", i, GameMaster.jugadores[i].apuesta * 1.5);
		}
		else if (MazoValor(GameMaster.Crupier) > 21 && MazoValor(GameMaster.jugadores[i])<=21) {
			printf("Jugador #%i gana, crupier se paso de 21\n", i );
		}
		else if (MazoValor(GameMaster.jugadores[i]) == MazoValor(GameMaster.Crupier) || MazoValorOpt(GameMaster.jugadores[i]) == MazoValor(GameMaster.Crupier) || MazoValor(GameMaster.jugadores[i]) == MazoValorOpt(GameMaster.Crupier) || MazoValorOpt(GameMaster.jugadores[i]) == MazoValorOpt(GameMaster.Crupier)) {
			printf("Jugador #%i no gana ni pierde nada\n Con una mano de igual valor que el crupier\n", i);
		}
		else if (MazoValor(GameMaster.jugadores[i]) < MazoValor(GameMaster.Crupier) || MazoValorOpt(GameMaster.jugadores[i]) < MazoValor(GameMaster.Crupier) || MazoValor(GameMaster.jugadores[i]) < MazoValorOpt(GameMaster.Crupier) || MazoValorOpt(GameMaster.jugadores[i]) < MazoValorOpt(GameMaster.Crupier)) {
			printf("Jugador #%i Pierde %i su valor de juego es menor que el crupier\n", i, GameMaster.jugadores[i].apuesta);
		}
		else {
			printf("El jugador perdio lo apostado\n");
		}
	}
	
}
int FinJuego() {
	CrupierJuego();
	repartirApuestas();
	printf("Digite 1 si desea jugar otra vez y 0 si desea cerrar la aplicacion\n");
	int continuar;
	int err = scanf_s("%d", &continuar);
	if (err > 0) {
		if (continuar == 1) {
			start();

		}
	}
	return 0;

}