package main

import (
	"fmt"
)

func main() {
	var d, h, m, s int
	var df, hf, mf, sf int
	var skip string
	fmt.Scanf("%s %d", &skip, &d)
	fmt.Scanf("%d : %d : %d", &h, &m, &s)

	fmt.Scanf("%s %d", &skip, &df)
	fmt.Scanf("%d : %d : %d", &hf, &mf, &sf)

	dur := (df*86400 + hf*3600 + mf*60 + sf) - (d*86400 + h*3600 + m*60 + s)
	fmt.Printf("%d dia(s)\n", dur/86400)
	fmt.Printf("%d hora(s)\n", (dur%86400)/3600)
	fmt.Printf("%d minuto(s)\n", ((dur%86400)%3600)/60)
	fmt.Printf("%d segundo(s)\n", ((dur%86400)%3600)%60)
}
