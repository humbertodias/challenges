package main

import "fmt"

func main() {
	var i int
	for i = 2; i <= 100; i++ {
		if i%2 == 0 {
			fmt.Printf("%d\n", i)
		}
	}
}
