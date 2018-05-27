#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace	std;

queue < pair < int, int >>mazo;
//palo, numero
pair < int     , int >actual;
//ultima carta en ser descartada
int		p         , n, m, direccion;
bool		perdio_su_turno;
typedef struct {
	//datos de un jugador
	int		cartas     [4][14];
	int		n_cartas;
}		jugador;
int 
convertir_palo(char c)
{
	if (c == 'C')
		return 0;
	else if (c == 'D')
		return 1;
	else if (c == 'H')
		return 2;
	else
		return 3;
}


void 
inicializar_jugador(jugador * x)
{
	//inicializando todo a cero
	for (int i = 1; i <= 13; i++) {
		x->cartas[0][i] = 0;
		x->cartas[1][i] = 0;
		x->cartas[2][i] = 0;
		x->cartas[3][i] = 0;
	}
	x->n_cartas = 0;
}
void 
insertar_carta(jugador * x, int p, int c)
{
	x->cartas[p][c]++;
	x->n_cartas++;
}
int 
max_por_numero(jugador * x, int p)
{
	//seleccionando lamayor carta en relacion al palo
	for (int i = 13; i >= 1; i--)
		if (x->cartas[p][i] > 0)
			return i;
	return -1;
}
int 
max_por_palo(jugador * x, int c)
{
	//seleccionando la mayor carta en relacion al numero
	if (x->cartas[3][c] > 0)
		return 3;
	else if (x->cartas[2][c] > 0)
		return 2;
	else if (x->cartas[1][c] > 0)
		return 1;
	else if (x->cartas[0][c] > 0)
		return 0;
	else
		return -1;
}
void 
descartar_carta(jugador * x, int p, int c)
{
	//descartando carta
	x->cartas[p][c]--;
	x->n_cartas--;
	if (c == 12)
		direccion *= (-1);
	//Reina invierte el sentido del juego
		perdio_su_turno = (c == 1 || c == 7 || c == 11);
	//as siete o jack
		actual.first = p;
	//actualizamos la carta a ser descargada
		actual.second = c;
}
bool 
intentando_descartar(jugador * x, int p1, int c1, int p2, int c2)
{
	//devuelve true si es que se pudo
	if (c1 != -1 || c2 != -1) {
		//descartar una carta
		if (c1 > c2)
			descartar_carta(x, p1, c1);
		//primero por numero
			else if (c1 == c2) {
			//despues por palo
				if (p1 > p2)
				descartar_carta(x, p1, c1);
			else
				descartar_carta(x, p2, c2);
		} else
			descartar_carta(x, p2, c2);
		return true;
	} return false;
}
void 
resuelva()
{
	jugador		jugadores[p];
	int		carta     , sw = 0, p1, p2, c1, c2;
	char		palo;

	pair < int     , int >aux;
	direccion = 1;
	//sentido normal, -1 en el caso de que se invierta
		perdio_su_turno = false;
	for (int i = 0; i < p; i++) {
		//insercion de cartas a cada jugador
			inicializar_jugador(&jugadores[i]);
		for (int j = 1; j <= m; j++) {
			scanf("%d %c", &carta, &palo);
			insertar_carta(&jugadores[i], convertir_palo(palo), carta);
		}
	}
	n -= (p * m);
	while (!mazo.empty())
		mazo.pop();
	for (int i = 1; i <= n; i++) {
		//insertando cartas a la cola
			scanf("%d %c", &carta, &palo);
		mazo.push(make_pair(convertir_palo(palo), carta));
	}
	actual = mazo.front();
	//sacando la primera carta
		mazo.pop();
	perdio_su_turno = (actual.second == 1 || actual.second == 7
			   || actual.second == 11);
	//por si
		if (actual.second == 12)
		direccion *= (-1);
	//as, siete, jack o reina
		while (true) {
		if (!perdio_su_turno) {
			//validando si el jugador ha perdido su turno
				p1 = actual.first;
			c1 = max_por_numero(&jugadores[sw], actual.first);
			//1 o candidato en relacion al numero
				p2 = max_por_palo(&jugadores[sw], actual.second);
			c2 = actual.second;
			//2 o candidato en relacion al palo
				// -1 si es que no se encontro algun candidato
				if (c1 == -1)
				p1 = -1;
			//Para que la funcion de comparacion
				if (p2 == -1)
				c2 = -1;
			//funcione bien.
				if (!intentando_descartar(&jugadores[sw], p1, c1, p2, c2
							  )) {
				//si no descarta se intenta una vez mas
					aux = mazo.front();
				mazo.pop();
				insertar_carta(&jugadores[sw], aux.first, aux.second);
				p1 = actual.first;
				c1 = max_por_numero(&jugadores[sw], actual.first);
				p2 = max_por_palo(&jugadores[sw], actual.second);
				c2 = actual.second;
				if (c1 == -1)
					p1 = -1;
				if (p2 == -1)
					c2 = -1;
				intentando_descartar(&jugadores[sw], p1, c1, p2, c2);
				//intentando descartar por 2 o vez
			} else if (jugadores[sw].n_cartas == 0) {
				//en el caso de que haya descartado en la

					printf("%d\n", sw + 1);
				//primera vez, se verifica si ya no tiene
					return;
				//cartas, si es asi, imprime y termina
			}
		} else {
			//si el jugador actual perdio su turno
				if (actual.second == 1) {
				//as hace que saque una carte
					aux = mazo.front();
				mazo.pop();
				insertar_carta(&jugadores[sw], aux.first, aux.second);
			} else if (actual.second == 7) {
				//siete hace que saque dos cartas
					aux = mazo.front();
				mazo.pop();
				insertar_carta(&jugadores[sw], aux.first, aux.second);
				aux = mazo.front();
				mazo.pop();
				insertar_carta(&jugadores[sw], aux.first, aux.second);
			}
			perdio_su_turno = false;
		}
		sw += direccion;
		//pasando al siguiente jugador
			if (sw < 0)
			sw = p - 1;
		//igual a la funcion % p
			else if (sw >= p)
			sw = 0;
	}
}
int 
main()
{
	while (scanf("%d %d %d", &p, &m, &n) && (p || m || n))
		resuelva();
}
