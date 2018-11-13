package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c float64

	fmt.Scanf("%f %f %f", &a, &b, &c)

	mod1 := math.Abs(c - b)
	mod2 := math.Abs(a - b)
	mod3 := math.Abs(a - c)

	if mod1 < a && a < (b+c) && mod2 < c && c < (a+b) && mod3 < b && b < (a+c) {
		fmt.Printf("Perimetro = %.1f\n", a+b+c)
	} else {
		fmt.Printf("Area = %.1f\n", ((a+b)*c)/2)
	}
}
