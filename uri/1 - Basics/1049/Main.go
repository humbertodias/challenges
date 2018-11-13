package main

import (
	"fmt"
	"strings"
)

func strcmp(a, b string) bool {
	return strings.Compare(a, b) == 0
}

func main() {
	var input string
	var input2 string
	var input3 string

	fmt.Scanf("%s", &input)
	fmt.Scanf("%s", &input2)
	fmt.Scanf("%s", &input3)

	if strcmp(input, "vertebrado") {
		if strcmp(input2, "ave") {
			if strcmp(input3, "carnivoro") {
				fmt.Printf("aguia\n")
			}
			if strcmp(input3, "onivoro") {
				fmt.Printf("pomba\n")
			}
		}
		if strcmp(input2, "mamifero") {
			if strcmp(input3, "onivoro") {
				fmt.Printf("homem\n")
			}
			if strcmp(input3, "herbivoro") {
				fmt.Printf("vaca\n")
			}
		}
	}

	if strcmp(input, "invertebrado") {
		if strcmp(input2, "inseto") {
			if strcmp(input3, "hematofago") {
				fmt.Printf("pulga\n")
			}
			if strcmp(input3, "herbivoro") {
				fmt.Printf("lagarta\n")
			}
		}
		if strcmp(input2, "anelideo") {
			if strcmp(input3, "hematofago") {
				fmt.Printf("sanguessuga\n")
			}
			if strcmp(input3, "onivoro") {
				fmt.Printf("minhoca\n")
			}
		}
	}

}
