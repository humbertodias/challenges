package main

import (
	"fmt"
)

func main() {
	var a, b, c, d, e, f float32
	num := 0

	fmt.Scanf("%f", &a)
	fmt.Scanf("%f", &b)
	fmt.Scanf("%f", &c)
	fmt.Scanf("%f", &d)
	fmt.Scanf("%f", &e)
	fmt.Scanf("%f", &f)

	if a > 0.0 {
		num++
	}
	if b > 0.0 {
		num++
	}
	if c > 0.0 {
		num++
	}
	if d > 0.0 {
		num++
	}
	if e > 0.0 {
		num++
	}
	if f > 0.0 {
		num++
	}

	fmt.Printf("%d valores positivos\n", num)

}
