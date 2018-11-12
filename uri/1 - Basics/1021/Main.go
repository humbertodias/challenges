package main

import "fmt"

func main() {
	var N float64
	var inteiro, aux, aux1 int

	for {
		_, err := fmt.Scanf("%f", &N)
		if err != nil {
			break
		}

		inteiro = int(N)
		N = 100 * N
		aux1 = int(N)

		fmt.Printf("NOTAS:\n")
		fmt.Printf("%d nota(s) de R$ 100.00\n", inteiro/100)
		aux = (inteiro % 100)
		fmt.Printf("%d nota(s) de R$ 50.00\n", aux/50)
		aux = (aux % 50)
		fmt.Printf("%d nota(s) de R$ 20.00\n", aux/20)
		aux = (aux % 20)
		fmt.Printf("%d nota(s) de R$ 10.00\n", aux/10)
		aux = (aux % 10)
		fmt.Printf("%d nota(s) de R$ 5.00\n", aux/5)
		aux = (aux % 5)
		fmt.Printf("%d nota(s) de R$ 2.00\n", aux/2)
		aux = (aux % 2)
		fmt.Printf("MOEDAS:\n")
		fmt.Printf("%d moeda(s) de R$ 1.00\n", aux/1)

		aux1 = aux1 % 100
		fmt.Printf("%d moeda(s) de R$ 0.50\n", aux1/50)
		aux1 = aux1 % 50
		fmt.Printf("%d moeda(s) de R$ 0.25\n", aux1/25)
		aux1 = aux1 % 25
		fmt.Printf("%d moeda(s) de R$ 0.10\n", aux1/10)
		aux1 = aux1 % 10
		fmt.Printf("%d moeda(s) de R$ 0.05\n", aux1/5)
		aux1 = aux1 % 5
		fmt.Printf("%d moeda(s) de R$ 0.01\n", aux1/1)

	}

}
