package main

import "fmt"

func main() {
	var inteiro int
	fmt.Scanf("%d", &inteiro)
	fmt.Printf("%d\n", inteiro)
	var banknotes = [7]int{100, 50, 20, 10, 5, 2, 1}
	var div, i int
	aux := inteiro
	for i = 0; i < 7; i++ {
		div = banknotes[i]
		fmt.Printf("%d nota(s) de R$ %d,00\n", aux/div, div)
		aux = aux % div
	}
}
