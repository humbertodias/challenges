package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c float64

	fmt.Scanf("%f %f %f", &a, &b, &c)

	if (math.Pow(b, 2)-4*a*c) < 0 || 2*a == 0 {
		fmt.Printf("Impossivel calcular\n")
	} else {
		fmt.Printf("R1 = %.5f\n", ((-b)+math.Sqrt((math.Pow(b, 2)-4*a*c)))/(2*a))
		fmt.Printf("R2 = %.5f\n", ((-b)-math.Sqrt((math.Pow(b, 2)-4*a*c)))/(2*a))
	}

}
