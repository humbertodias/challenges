package main

import (
	"fmt"
	"math"
)

func main() {
	var a int
	fmt.Scanf("%d", &a)
	fmt.Printf("VOLUME = %.3f\n", (4.0/3.0)*3.14159*math.Pow(float64(a), 3))
}
