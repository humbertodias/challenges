def main():
    
    pi = 3.14159
    a,b,c = [float(i) for i in input().split(' ')]
    
    print("TRIANGULO: %.3lf" % ((a*c)/2.0) )
    print("CIRCULO: %.3lf" % (pi*c*c) )
    print("TRAPEZIO: %.3lf" % (((a+b)*c)/2.0) )
    print("QUADRADO: %.3lf" % (b*b) )
    print("RETANGULO: %.3lf" % (a*b) )

main()