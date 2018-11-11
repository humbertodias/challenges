package main

import (
	"fmt"
	"strings"
)

func main() {
	var line string
	fmt.Scanf("%s", &line)

	part1 := strings.Split(line, ".")
	fmt.Println(part1[0])
	fmt.Println(part1[1])

	part2 := strings.Split(part1[2], "-")
	fmt.Println(part2[0])
	fmt.Println(part2[1])

}
