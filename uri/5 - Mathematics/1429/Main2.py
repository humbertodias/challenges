fact = [1, 1, 2, 6, 24, 120]
def acm_to_dec(n):
    dec = 0
    for i in xrange(1, len(n) + 1):
        dec += int(n[-i]) * fact[i]

    return dec


while True:
    n = raw_input()

    if n == '0': break

    print acm_to_dec(n)