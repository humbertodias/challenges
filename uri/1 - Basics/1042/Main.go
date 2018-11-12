package main

import (
	"fmt"
)

func main() {
	var a, b, c, aux int
	var v [3]int

	fmt.Scanf("%d %d %d", &a, &b, &c)
	v[0] = a
	v[1] = b
	v[2] = c

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if v[i] < v[j] {
				aux = v[j]
				v[j] = v[i]
				v[i] = aux
			}
		}
	}

	fmt.Printf("%d\n%d\n%d\n\n", v[0], v[1], v[2])
	fmt.Printf("%d\n%d\n%d\n", a, b, c)

}
