package main

import "fmt"

func main() {
	var a, b, c float64

	fmt.Scanf("%f %f %f", &a, &b, &c)

	if a >= (b+c) || b >= (a+c) || c >= (a+b) {
		fmt.Printf("NAO FORMA TRIANGULO\n")
	} else if a*a == (b*b+c*c) || b*b == (a*a+c*c) || c*c == (a*a+b*b) {
		fmt.Printf("TRIANGULO RETANGULO\n")
	} else if a*a > (b*b+c*c) || b*b > (a*a+c*c) || c*c > (a*a+b*b) {
		fmt.Printf("TRIANGULO OBTUSANGULO\n")
	} else if a*a < (b*b+c*c) || b*b < (a*a+c*c) || c*c < (a*a+b*b) {
		fmt.Printf("TRIANGULO ACUTANGULO\n")
	}

	if a == b && a == c {
		fmt.Printf("TRIANGULO EQUILATERO\n")
	}
	if (a == b && a != c) || (a == c && a != b) || (b == c && b != a) {
		fmt.Printf("TRIANGULO ISOSCELES\n")
	}

}
