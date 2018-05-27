# -*- coding: utf-8 -*-

import sys

'''
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
'''

def fatorial(n):
    num = 1
    while n >= 1:
        num *= n
        n -= 1
    return num

for line in sys.stdin:
	line = line.strip()
	if line == '': break
	m, n = [int(s) for s in line.split(' ')]
	print( fatorial (m) + fatorial(n) )