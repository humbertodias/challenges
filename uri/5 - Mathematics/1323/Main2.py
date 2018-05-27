while True:
    n = int(raw_input())

    if n == 0: break

    squares = 0
    for i in xrange(n):
        squares += (n - i) ** 2

    print squares