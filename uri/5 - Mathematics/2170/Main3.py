def PERCENTUAL(a,b):
	return ((b - a) / a)  * 100

def main():

	i = 1;
	while True :
		try:
			a,b = [ float(x) for x in input().split(" ") ]
		except (EOFError):
		   break #end of file reached

		print("Projeto %ld:" % (i) )
		print("Percentual dos juros da aplicacao: %.2f %%\n" % PERCENTUAL(a,b) )

		i = i+1

main()