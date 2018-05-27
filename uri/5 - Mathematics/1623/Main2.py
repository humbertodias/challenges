def fact(n):
    fact = 1
    for i in xrange(1, n + 1):
        fact *= i
    return fact

while True:
    n, q = map(long, raw_input().split())

    if n == 0 and q == 0: break

    t = long(raw_input())
    n_words = fact(n - q + 1)
    if n_words > t:
        print 'descartado'
    else:
        print n_words