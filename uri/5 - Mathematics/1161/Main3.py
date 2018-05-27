# -*- coding: utf-8 -*-

import sys
from functools import lru_cache

'''
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
'''

@lru_cache(maxsize=None)
def fatorial(n):
	if n < 1 : return 1
	return n * fatorial(n-1) 

for line in sys.stdin:
	line = line.strip()
	if line == '': break
	M, N = [int(s) for s in line.split(' ')]
	print( fatorial (M) + fatorial(N) )