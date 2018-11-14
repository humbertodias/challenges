package main

import "fmt"

func main() {
	var a, b, c, d, e int
	par := 0

	fmt.Scanf("%d", &a)
	if a%2 == 0 {
		par++
	}
	fmt.Scanf("%d", &b)
	if b%2 == 0 {
		par++
	}
	fmt.Scanf("%d", &c)
	if c%2 == 0 {
		par++
	}
	fmt.Scanf("%d", &d)
	if d%2 == 0 {
		par++
	}
	fmt.Scanf("%d", &e)
	if e%2 == 0 {
		par++
	}

	fmt.Printf("%d valores pares\n", par)
}
