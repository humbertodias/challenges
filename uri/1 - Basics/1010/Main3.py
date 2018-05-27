def main():

    a,b,e = [float(i) for i in input().split(' ')]
    c,d,f = [float(i) for i in input().split(' ')]

    print("VALOR A PAGAR: R$ %.2f" % (b*e + d*f) )

main()