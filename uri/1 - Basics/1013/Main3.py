def main():
    aux = 0
    a,b,c = [int(i) for i in input().split(' ')]
    
    if(a > b):
    	aux = a
    else:
	    aux = b
    
    if(aux < c):
        aux = c
    
    print("%d eh o maior" % (aux) )

main()