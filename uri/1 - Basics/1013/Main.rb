def main()

    aux = 0
    ar=gets.split()
    a=ar[0].to_i
    b=ar[1].to_i
    c=ar[2].to_i

    if(a > b)
    	aux = a
    else
	    aux = b
    end
    
    if(aux > c)
        aux = aux
    else
        aux = c
    end
    
    print("%d eh o maior\n" % (aux) )

end

main()