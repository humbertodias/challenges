package main

import (
	"fmt"
	"math"
)

func main() {
	var nl, n, m int
	var f float64
	var s string

	fmt.Scanf("%d", &nl)
	for i := 0; i < nl; i++ {
		fmt.Scanf("%d %d", &n, &m)
		f = math.Pow(float64(n), float64(m))
		s = fmt.Sprintf("%.0f", f)
		fmt.Printf("%d\n", len(s))
	}

}
