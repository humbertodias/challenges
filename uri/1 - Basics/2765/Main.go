package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {

		strs := strings.Split(scanner.Text(), ",")
		for _, s := range strs {
			fmt.Printf("%s\n", s)
		}

	}

}
