# -*- coding: utf-8 -*-

a,b,c = [float(f) for f in raw_input().split(' ')]

mod1 = abs(c - b)
mod2 = abs(a - b)
mod3 = abs(a - c)

if mod1 < a and a < (b + c) and mod2 < c and c < (a+b) and mod3 < b and b < (a+c) :
    print("Perimetro = %.1f" %(a+b+c) )
else:
    print("Area = %.1f" % ( ((a+b)*c)/2.0)  )