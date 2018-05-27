# -*- coding: utf-8 -*-

a,b,c = [float(f) for f in raw_input().split(' ')]

if a >= (b+c) or b >= (a+c) or c >= (a+b) : 
    print("NAO FORMA TRIANGULO")
elif a*a == (b*b + c*c) or b*b == (a*a + c*c) or c*c == (a*a + b*b) :
    print("TRIANGULO RETANGULO")
elif a*a > (b*b + c*c) or b*b > (a*a + c*c) or c*c > (a*a + b*b) :
    print("TRIANGULO OBTUSANGULO")
elif a*a < (b*b + c*c) or b*b < (a*a + c*c) or c*c < (a*a + b*b) :
    print("TRIANGULO ACUTANGULO")
if ( a == b and a == c):
    print("TRIANGULO EQUILATERO")
if (a == b and a != c)  or (a == c and a != b) or (b == c and b != a) :
    print("TRIANGULO ISOSCELES")