package main

import "fmt"

func main() {
	var a int
	fmt.Scanf("%d", &a)
	fmt.Printf("%d ano(s)\n", a/365)
	fmt.Printf("%d mes(es)\n", (a%365)/30)
	fmt.Printf("%d dia(s)\n", (a%365)%30)

}
