
def fib2(n):
    if n == 0:
        return (0, 1)
    else:
        a, b = fib2(n // 2)
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n % 2 == 0:
            return (c, d)
        else:
            return (d, c + d)

def fib3(n):
    v1, v2, v3 = 1, 1, 0    # initialise a matrix [[1,1],[1,0]]
    for rec in bin(n)[3:]:  # perform fast exponentiation of the matrix (quickly raise it to the nth power)
        calc = v2*v2
        v1, v2, v3 = v1*v1+calc, (v1+v3)*v2, calc+v3*v3
        if rec=='1':    v1, v2, v3 = v1+v2, v1, v2
    return v2


def matrix_mul(A, B):
     return ([A[0][0] * B[0][0] + A[0][1] * B[1][0],
              A[0][0] * B[0][1] + A[0][1] * B[1][1]],
             [A[1][0] * B[0][0] + A[1][1] * B[1][0],
              A[1][0] * B[0][1] + A[1][1] * B[1][1]])
 
def matrix_exp(A, e):
     if not e:
             return [[1,0],[0,1]]
     elif e % 2:
             return matrix_mul(A, matrix_exp(A, e-1))
     else:
             sq= matrix_exp(A, e//2)
             return matrix_mul(sq, sq)
 
def fibo(n):
     M = [[1,1],[1,0]]
     return matrix_exp(M, n)[0][0]

def fib(n):
    # return fib2(n)[0]

    # return fib3(n)
    # return fib1(n)
    # return fib3(n)
    return fibo(n)

def main():


    while True :
        a,b,n = [ int(x) for x in input().split(" ") ]

        if a==0 and b==0 and n==0:
            break;

        num = 0
        cont = 0
        for cont in range(n): 

            n1 = a + cont
            n2 = b + cont
            num += fib(n1) * fib(n2)

        print("%ld" %( num ) );
    


main()