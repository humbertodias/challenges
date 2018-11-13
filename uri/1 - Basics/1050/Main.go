package main

import (
	"fmt"
)

func main() {

	var a int
	fmt.Scanf("%d", &a)

	switch a {
	case 11:
		fmt.Printf("Sao Paulo\n")
		break
	case 19:
		fmt.Printf("Campinas\n")
		break
	case 21:
		fmt.Printf("Rio de Janeiro\n")
		break
	case 27:
		fmt.Printf("Vitoria\n")
		break
	case 31:
		fmt.Printf("Belo Horizonte\n")
		break
	case 32:
		fmt.Printf("Juiz de Fora\n")
		break
	case 61:
		fmt.Printf("Brasilia\n")
		break
	case 71:
		fmt.Printf("Salvador\n")
		break
	default:
		fmt.Printf("DDD nao cadastrado\n")
		break
	}

}
