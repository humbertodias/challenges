package main

import "fmt"

func main() {
	var a, b int

	fmt.Scanf("%d %d", &a, &b)

	if a >= b {
		fmt.Printf("O JOGO DUROU %d HORA(S)\n", (24-a)+b)
	} else {
		fmt.Printf("O JOGO DUROU %d HORA(S)\n", b-a)
	}

}
