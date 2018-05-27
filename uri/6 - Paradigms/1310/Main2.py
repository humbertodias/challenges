def solve(i):
    if mem[i] != -1:
        return mem[i]

    if i == 0:
        mem[0] = profit[0]
        return mem[0]

    mem[i] = max(solve(i - 1) + profit[i], profit[i])
    return mem[i]

while True:
    try:
        days = int(raw_input())
    except EOFError:
        break

    cost = int(raw_input())

    profit = []
    max_profit = 0
    for i in xrange(days):
        profit.append(int(raw_input()) - cost)

    mem = [-1] * days
    for i in xrange(days):
        res = solve(i)
        if res > max_profit:
            max_profit = res

    print max_profit