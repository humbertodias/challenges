package main

import "fmt"

func main() {
	var a, b, c float64
	const pi = 3.14159

	fmt.Scanf("%f %f %f", &a, &b, &c)

	fmt.Printf("TRIANGULO: %.3f\n", (a*c)/2.0)
	fmt.Printf("CIRCULO: %.3f\n", pi*c*c)
	fmt.Printf("TRAPEZIO: %.3f\n", ((a+b)*c)/2.0)
	fmt.Printf("QUADRADO: %.3f\n", b*b)
	fmt.Printf("RETANGULO: %.3f\n", a*b)

}
