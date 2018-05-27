while True:
    n = int(raw_input())

    if n == 0: break

    a = 0
    b = 1
    fib = 1
    for i in xrange(n):
        fib = a + b
        a = b
        b = fib

    print fib