package main

import "fmt"

func main() {
	var a, b, c, d, e int
	var par, impar, pos, neg int

	fmt.Scanf("%d", &a)
	if a%2 == 0 {
		par++
	} else {
		impar++
	}
	if a > 0 {
		pos++
	} else if a < 0 {
		neg++
	}
	fmt.Scanf("%d", &b)
	if b%2 == 0 {
		par++
	} else {
		impar++
	}
	if b > 0 {
		pos++
	} else if b < 0 {
		neg++
	}
	fmt.Scanf("%d", &c)
	if c%2 == 0 {
		par++
	} else {
		impar++
	}
	if c > 0 {
		pos++
	} else if c < 0 {
		neg++
	}
	fmt.Scanf("%d", &d)
	if d%2 == 0 {
		par++
	} else {
		impar++
	}
	if d > 0 {
		pos++
	} else if d < 0 {
		neg++
	}
	fmt.Scanf("%d", &e)
	if e%2 == 0 {
		par++
	} else {
		impar++
	}
	if e > 0 {
		pos++
	} else if e < 0 {
		neg++
	}

	fmt.Printf("%d valor(es) par(es)\n", par)
	fmt.Printf("%d valor(es) impar(es)\n", impar)
	fmt.Printf("%d valor(es) positivo(s)\n", pos)
	fmt.Printf("%d valor(es) negativo(s)\n", neg)

}
