package main

import "fmt"

func main() {
	var f1, f2, f3 float64
	var name string
	fmt.Scanf("%s", &name)
	fmt.Scanf("%f", &f1)
	fmt.Scanf("%f", &f2)
	f3 = f1 + (15.0 * f2 / 100.0)
	fmt.Printf("TOTAL = R$ %.2f\n", f3)
}
