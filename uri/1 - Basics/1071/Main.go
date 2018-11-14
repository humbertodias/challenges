package main

import "fmt"

func main() {
	var x, y, i, aux int
	soma := 0

	fmt.Scanf("%d", &x)
	fmt.Scanf("%d", &y)

	if x > y {
		aux = x
		x = y
		y = aux
	}

	for i = x + 1; i < y; i++ {
		if i%2 != 0 {
			soma += i
		}
	}

	fmt.Printf("%d\n", soma)
}
