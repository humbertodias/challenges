package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, m, nl int
	var l *big.Int

	fmt.Scanf("%d", &nl)
	for i := 0; i < nl; i++ {
		fmt.Scanf("%d %d", &n, &m)
		l = powBig(n, m)
		fmt.Printf("%v\n", len(l.String()))
	}

}

func powBig(a, n int) *big.Int {
	tmp := big.NewInt(int64(a))
	res := big.NewInt(1)
	for n > 0 {
		temp := new(big.Int)
		if n%2 == 1 {
			temp.Mul(res, tmp)
			res = temp
		}
		temp = new(big.Int)
		temp.Mul(tmp, tmp)
		tmp = temp
		n /= 2
	}
	return res
}
