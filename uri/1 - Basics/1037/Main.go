package main

import (
	"fmt"
)

func main() {

	var f float64
	fmt.Scanf("%f", &f)

	if f < 0.0000 {
		fmt.Printf("Fora de intervalo\n")
	} else if f >= 0.0000 && f <= 25.0000 {
		fmt.Printf("Intervalo [0,25]\n")
	} else if f > 25.0000 && f <= 50.0000 {
		fmt.Printf("Intervalo (25,50]\n")
	} else if f > 50.0000 && f <= 75.0000 {
		fmt.Printf("Intervalo (50,75]\n")
	} else if f > 75.0000 && f <= 100.0000 {
		fmt.Printf("Intervalo (75,100]\n")
	} else if f > 100.0000 {
		fmt.Printf("Fora de intervalo\n")
	}

}
