package main

import "fmt"

func main() {

	var a, b, c, d int
	var e, f float32

	fmt.Scanf("%d %d %f", &a, &b, &e)
	fmt.Scanf("%d %d %f", &c, &d, &f)

	fmt.Printf("VALOR A PAGAR: R$ %.2f\n", (float32(b)*e + float32(d)*f))
}
