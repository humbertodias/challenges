package main

import "fmt"

func main() {

	var a int
	var b float64

	_, err1 := fmt.Scanf("%d", &a)
	if err1 != nil {
		return
	}
	_, err2 := fmt.Scanf("%f", &b)
	if err2 == nil {
		fmt.Printf("%.3f km/l\n", float64(a)/b)
	}

}
