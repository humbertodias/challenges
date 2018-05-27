# -*- coding: utf-8 -*-

'''
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
'''

for i in range(0,10):
	nan = False
	try:
		n = int(input())
	except Exception:
		nan = True
	if n <= 0 or nan == True : n = 1
	print("X[%d] = %d\n" %(i,n))

