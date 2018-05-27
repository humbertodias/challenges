#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

#define INFINITO 99999
using namespace	std;
long		numerador, denominador;
//posible solucion
long		a1       , b1, c1, d1, a2, b2, c2, d2;
//datos de entrada
long
GCD(int a, int b)
{
	//maximo comun divisor
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}
void
reducir()
{
	//hace que la solucion sea una fraccion irreducible
	long		gcd = GCD(numerador, denominador);
	numerador /= gcd;
	denominador /= gcd;
}
bool
busca_solucion_theta()
{
	//en el caso de que la solucion se encuentre en theta
		if (d1 < 0)
		d1 = 360 * (long)ceil(d1 / -360.0) + d1;
	//haciendo que 0 <= d1, d2 < 360
		else
		d1 = d1 % 360;
	if (d2 < 0)
		d2 = 360 * (long)ceil(d2 / -360.0) + d2;
	else
		d2 = d2 % 360;
	numerador = d2 - d1;
	//creando la posible solucion
		denominador = c1 - c2;
	if (denominador < 0) {
		numerador *= -1;
		denominador *= -1;
	}
	//en el caso de que el numerador sea negativo, se le suma 360 hasta que sea positivo
		if (numerador < 0)
		numerador = 360 * (long)ceil(numerador / -360.0) + numerador;
	if (denominador == 0) {

		if (numerador == 0)
			denominador = 1;
		//infinitas soluciones, asi que buscamos el menor(0, 1)
			else
			return false;
		//no existe solucion
	} else if (numerador == 0)
		denominador = 1;
	//para evitar respuestas del tipo 0 / 358...y convertirlas a0 / 1
		else
		reducir();
	//volviendo a fraccion irreducible.
		return true;
	//entonces si se llego a una solucion
}
void
obtener_solucion()
{
	//buscando la solucion en las ecuaciones de r
	bool ok = true;
	//por ahora existe solucion
		numerador = b2 - b1;
	//creando una posible solucion
		denominador = a1 - a2;
	if (denominador == 0) {
		if (numerador == 0)
			ok = busca_solucion_theta();
		//infinitas soluciones, asi que buscamos en theta
			else
			ok = false;
		//no existen soluciones
	} else if (numerador * denominador >= 0) {
		//hay solucion si es positiva
			if (numerador == 0)
			denominador = 1;
		//para evitar respuestas del tipo 0 / 358...y convertirlas a0 / 1
			else {
			numerador = labs(numerador);
			denominador = labs(denominador);
			//volviendolos positivos, evita solucion - 2, -6
				reducir();
			//volviendo a fraccion irreducible.
		}
		if (ok) {
			//si hasta ahora no ha fallado nada, se comprueba la solucion en theta
				long		th1 = c1 * numerador + d1 * denominador;
			long		th2 = c2 * numerador + d2 * denominador;
			ok = (a1 * numerador + b1 * denominador == 0) || ((th1 - th2) % (360 * denominador) == 0);
			//verdad si r1 == 0 o es solucion de theta
		}
	} else
		ok = false;
	//solucion negativa, se descarta
		if (!ok) {
		numerador = INFINITO;
		//si no hay solucion, se la pone en infinita
			denominador = 1;
	}
}
int 
main()
{
	long		num1     , num2, den1, den2;
	while ((cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2) &&
	       (a1 || b1 || c1 || d1 || a2 || b2 || c2 || d2)) {
		obtener_solucion();
		//obteniendo solucion de la manera normal
			num1 = numerador, den1 = denominador;
		//guardando solucion
			a2 *= -1;
		b2 *= -1;
		d2 += 180;
		//obteniendo solucion de la segunda manera
			obtener_solucion();


		num2 = numerador, den2 = denominador;
		//guardando solucion
			// mostrando la menor solucion.
			if (num1 == INFINITO && num2 == INFINITO)
			printf("0 0\n");
		else if (num1 * den2 > num2 * den1)
			printf("%ld %ld\n", num2, den2);
		else
			printf("%ld %ld\n", num1, den1);
	}
	return 0;
}
