package main

import "fmt"

func main() {
	var sal float64

	fmt.Scanf("%f", &sal)

	if sal <= 2000.00 {
		fmt.Printf("Isento\n")
	} else if sal >= 2000.01 && sal <= 3000.00 {
		fmt.Printf("R$ %.2f\n", (sal-2000.00)*0.08)
	} else if sal >= 3000.01 && sal <= 4500.00 {
		fmt.Printf("R$ %.2f\n", ((sal-3000.00)*0.18 + 1000.00*0.08))
	} else if sal >= 4500.01 {
		fmt.Printf("R$ %.2f\n", ((sal-4500.00)*0.28 + 1500.00*0.18 + 1000.00*0.08))
	}

}
