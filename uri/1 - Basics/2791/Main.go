package main

import "fmt"

func main() {
	var abcd [4]int
	fmt.Scanf("%d %d %d %d", &abcd[0], &abcd[1], &abcd[2], &abcd[3])
	for i := 0; i < len(abcd); i++ {
		if abcd[i] == 1 {
			fmt.Printf("%d\n", i+1)
			break
		}
	}

}
