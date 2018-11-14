package main

import "fmt"

func main() {
	var x int
	fmt.Scanf("%d", &x)

	i := x
	for j := 0; j < 6; i++ {
		if i%2 != 0 {
			fmt.Printf("%d\n", i)
			j++
		}
	}

}
