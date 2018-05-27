import math

while True:
    try:
        d, vf, vg = map(int, raw_input().split())
    except EOFError:
        break

    t_f = 12 / float(vf)
    t_g = (math.sqrt(d**2 + 144)) / float(vg)

    if t_g <= t_f:
        print 'S'
    else:
        print 'N'