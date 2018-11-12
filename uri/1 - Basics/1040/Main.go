package main

import "fmt"

func main() {

	var a, b, c, d, e, media float32

	fmt.Scanf("%f %f %f %f", &a, &b, &c, &d)

	media = (a*2 + b*3 + c*4 + d*1) / (10.0)
	fmt.Printf("Media: %.1f\n", media)

	if media >= 7.0 {
		fmt.Printf("Aluno aprovado.\n")
	}
	if media < 5.0 {
		fmt.Printf("Aluno reprovado.\n")
	}
	if media >= 5.0 && media < 7.0 {
		fmt.Printf("Aluno em exame.\n")
		fmt.Scanf("%f", &e)
		fmt.Printf("Nota do exame: %.1f\n", e)
		if (media+e)/2.0 >= 5.0 {
			fmt.Printf("Aluno aprovado.\n")
		} else {
			fmt.Printf("Aluno reprovado.\n")
		}
		fmt.Printf("Media final: %.1f\n", (media+e)/2.0)
	}
}
