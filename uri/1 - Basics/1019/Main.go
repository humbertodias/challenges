package main

import "fmt"

func main() {
	var a int
	fmt.Scanf("%d", &a)
	fmt.Printf("%d:%d:%d\n", a/3600, (a%3600)/60, a%60)
}
