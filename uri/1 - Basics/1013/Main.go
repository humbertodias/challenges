package main

import (
	"fmt"
)

func main() {
	var a, b, c, aux int

	fmt.Scanf("%d %d %d", &a, &b, &c)

	if a > b {
		aux = a
	} else {
		aux = b
	}

	if aux < c {
		aux = c
	}

	fmt.Printf("%d eh o maior\n", aux)

}
