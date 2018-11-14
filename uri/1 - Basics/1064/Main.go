package main

import (
	"fmt"
)

func main() {
	var a, b, c, d, e, f float32
	var post, soma float32

	fmt.Scanf("%f", &a)
	if a >= 0.0 {
		post += 1.0
		soma += a
	}
	fmt.Scanf("%f", &b)
	if b >= 0.0 {
		post += 1.0
		soma += b
	}
	fmt.Scanf("%f", &c)
	if c >= 0.0 {
		post += 1.0
		soma += c
	}
	fmt.Scanf("%f", &d)
	if d >= 0.0 {
		post += 1.0
		soma += d
	}
	fmt.Scanf("%f", &e)
	if e >= 0.0 {
		post += 1.0
		soma += e
	}
	fmt.Scanf("%f", &f)
	if f >= 0.0 {
		post += 1.0
		soma += f
	}
	fmt.Printf("%.0f valores positivos\n", post)
	fmt.Printf("%.1f\n", soma/post)

}
