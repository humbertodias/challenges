# -*- coding: utf-8 -*-
import sys

for line in sys.stdin:
    g = int(line)
    j = 0
    test = 0
    for i in range(0,60):
        if(i%5 == 0): j+=1
        angulo = i*6 - j*6
        if(g == angulo or g == -angulo):
            test = 1
            break
    if(test == 1): print("Y");
    else: print ("N");
