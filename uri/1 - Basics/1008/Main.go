package main

import "fmt"

func main() {

	var NUMBER, HOURS int
	var HOUR_VALUE float64
	fmt.Scanf("%d", &NUMBER)
	fmt.Scanf("%d", &HOURS)
	fmt.Scanf("%f", &HOUR_VALUE)
	SALARY := float64(HOURS) * HOUR_VALUE

	fmt.Printf("NUMBER = %d\n", NUMBER)
	fmt.Printf("SALARY = U$ %.2f\n", SALARY)
}
