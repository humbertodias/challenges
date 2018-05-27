def main()
    
    pi = 3.14159
    ar=gets.split()
    a=ar[0].to_f
    b=ar[1].to_f
    c=ar[2].to_f

    print("TRIANGULO: %.3f\n" % ((a*c)/2.0) )
    print("CIRCULO: %.3f\n" % (pi*c*c) )
    print("TRAPEZIO: %.3f\n" % (((a+b)*c)/2.0) )
    print("QUADRADO: %.3f\n" % (b*b) )
    print("RETANGULO: %.3f\n" % (a*b) )
end

main()