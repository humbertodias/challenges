entradas = raw_input().split()
num1 = entradas[0]
num2 = entradas[1]
 
while ( float(num1) != 0 or float(num2) != 0):
	if(float(num1) == 0):
		print 2
	elif(float(num2) == 0):
		print 1
 
	else:
		if(float(num1) < 10):
			soma = float(num1)
		else:
			while(float(num1) >= 10):
				soma = 0
				for i in range(len(num1)):
					soma += int(num1[i])
				num1 = str(soma)
		if(float(num2) < 10):
			soma1 = float(num2)
		else:
			while(float(num2) >= 10):
				soma1 = 0
				for i in range(len(num2)):
					soma1 += int(num2[i])
				num2 = str(soma1)
 
		if(soma > soma1):
			print 1
		elif(soma == soma1):
			print 0
		else:
			print 2
	entradas = raw_input().split()
	num1 = entradas[0]
	num2 = entradas[1]