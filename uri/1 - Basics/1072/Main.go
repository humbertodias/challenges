package main

import (
	"fmt"
)

func main() {
	var x, a int
	var in, out int

	fmt.Scanf("%d", &x)

	for i := 0; i < x; i++ {
		fmt.Scanf("%d", &a)
		if a >= 10 && a <= 20 {
			in++
		} else {
			out++
		}
	}
	fmt.Printf("%d in\n", in)
	fmt.Printf("%d out\n", out)

}
