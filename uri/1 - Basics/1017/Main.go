package main

import "fmt"

func main() {
	var a, b int

	_, err := fmt.Scanf("%d", &a)
	if err == nil {
		fmt.Scanf("%d", &b)
		f := float32(a*b) / 12.0

		fmt.Printf("%.3f\n", f)
	}
}
