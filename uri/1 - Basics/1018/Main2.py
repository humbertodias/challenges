inteiro = int(raw_input())    
print inteiro    
banknotes = [100, 50, 20, 10, 5, 2, 1]
aux = inteiro ;
for div in banknotes:
	print "%d nota(s) de R$ %d,00" % ( aux/div, div)
	aux = aux % div