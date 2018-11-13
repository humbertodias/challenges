package main

import "fmt"

func main() {
	var a, b, c, d int

	fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)

	inicio := a*60 + b
	final := c*60 + d
	duracao := 0

	if a <= c {
		duracao = final - inicio
		if duracao == 0 {
			fmt.Printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", 24, duracao%60)
		} else {
			fmt.Printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (duracao-duracao%60)/60, duracao%60)
		}
	} else {
		duracao = (24*60 - inicio) + final
		fmt.Printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (duracao-duracao%60)/60, duracao%60)
	}

}
