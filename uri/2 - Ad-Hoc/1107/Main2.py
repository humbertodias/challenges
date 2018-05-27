while True:
    a, c = map(int, raw_input().split())

    if a == c == 0: break

    heights = map(int, raw_input().split())

    sweep = 0
    last_h = a
    for h in heights:
        if h < last_h:
            sweep += last_h - h
        last_h = h

    print sweep