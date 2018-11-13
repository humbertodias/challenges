package main

import (
	"fmt"
)

func main() {
	var a, b, aux int

	fmt.Scanf("%d %d", &a, &b)

	if a < b {
		aux = a
		a = b
		b = aux
	}

	if a%b == 0 {
		fmt.Printf("Sao Multiplos\n")
	} else {
		fmt.Printf("Nao sao Multiplos\n")
	}

}
