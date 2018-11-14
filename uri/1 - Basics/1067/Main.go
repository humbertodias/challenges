package main

import "fmt"

func main() {
	var x int
	fmt.Scanf("%d", &x)

	for i := 1; i <= x; i++ {
		if i%2 != 0 {
			fmt.Printf("%d\n", i)
		}
	}

}
