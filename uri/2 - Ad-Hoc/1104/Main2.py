while True:
    a, b = map(int, raw_input().split())

    if a == b == 0: break

    cards_a = map(int, raw_input().split())
    cards_b = map(int, raw_input().split())

    op1 = len(set(cards_a) - set(cards_b))
    op2 = len(set(cards_b) - set(cards_a))

    print min(op1, op2)