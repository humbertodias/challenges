nTests = int(raw_input())
for test in range(nTests):
    x = float(raw_input())
    days = 0
    while x > 1:
        x /= 2
        days += 1

    print '%d dias' % days