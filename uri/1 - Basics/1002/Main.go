package main

import (
	"fmt"
)

func main() {
	const PI = 3.14159
	var R float64
	fmt.Scanf("%f", &R)
	A := PI * R * R
	fmt.Printf("A=%.4f\n", A)
}
