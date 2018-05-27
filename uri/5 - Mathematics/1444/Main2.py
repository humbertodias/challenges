while True:
    n = int(raw_input())

    if n == 0: break

    runs = 0
    while n > 1:
        if n % 3 == 0:
            runs += n / 3
            n = n / 3
        else:
            runs += (n / 3) + 1
            n = (n / 3) + 1

    print runs