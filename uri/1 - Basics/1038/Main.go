package main

import "fmt"

func main() {
	var a, b int
	var valor float32
	fmt.Scanf("%d %d", &a, &b)

	if a == 1 {
		valor = 4.00 * float32(b)
	} else if a == 2 {
		valor = 4.50 * float32(b)
	} else if a == 3 {
		valor = 5.00 * float32(b)
	} else if a == 4 {
		valor = 2.00 * float32(b)
	} else if a == 5 {
		valor = 1.50 * float32(b)
	}

	fmt.Printf("Total: R$ %.2f\n", valor)
}
