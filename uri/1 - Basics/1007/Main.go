package main

import (
	"fmt"
)

func main() {
	var A, B, C, D int
	fmt.Scanf("%d", &A)
	fmt.Scanf("%d", &B)
	fmt.Scanf("%d", &C)
	fmt.Scanf("%d", &D)
	DIFERENCA := A*B - C*D

	fmt.Printf("DIFERENCA = %d\n", DIFERENCA)
}
