import math

while True:
    try:
        l = int(raw_input())
    except EOFError:
        break

    koch_area = 2 * math.sqrt(3) * (l ** 2) / 5
    print '%.2f' % koch_area