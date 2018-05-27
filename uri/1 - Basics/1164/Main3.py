# -*- coding: utf-8 -*-

def divisor_sum( number ):
   sum = 0
   for i in range(1,number): 
      if number % i == 0: 
         sum += i  
   return sum


n = int(input())
for i in range(0,n):
	num = int(input())

	if  divisor_sum(num) == num : print ("%d eh perfeito" % (num)  )
	else: print("%d nao eh perfeito" % (num) )