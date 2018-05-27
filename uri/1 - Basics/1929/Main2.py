# -*- coding: utf-8 -*-

'''
Escreva a sua solução aqui
Code your solution here
Escriba su solución aquí
'''

a,b,c,d = [int(s) for s in raw_input().split(' ')]
tenta1 = (abs(b-c) < a and a < (b+c)) or (abs(a-c) < b and b < (a+c)) or (abs(a-b) < c and c < (a+b)) # a b c
tenta2 = (abs(c-d) < b and b < (c+d)) or (abs(b-d) < c and c < (b+d)) or (abs(b-c) < d and d < (b+c)) # b c d
tenta3 = (abs(c-d) < a and a < (c+d)) or (abs(a-d) < c and c < (a+d)) or (abs(a-c) < d and d < (a+c)) # a c d
tenta4 = (abs(b-d) < a and a < (b+d)) or (abs(a-d) < b and b < (a+d)) or (abs(a-b) < d and d < (a+b)) # a b d

if tenta1 or tenta2 or tenta3 or tenta4:
    print("S")
else: 
    print("N")
