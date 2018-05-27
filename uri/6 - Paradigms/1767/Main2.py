def solve(package, capacity):
    if mem[package][capacity] != 0:
        return mem[package][capacity]

    if package == 0:
        if weights[0] <= capacity:
            mem[package][capacity] = quantities[0]
            return quantities[0]
        else:
            return 0

    dont_put = solve(package - 1, capacity)
    put = 0
    if weights[package] <= capacity:
        put = quantities[package] + solve(package - 1, capacity - weights[package])

    if dont_put > put:
        mem[package][capacity] = dont_put
    else:
        mem[package][capacity] = put

    return mem[package][capacity]


n_deliveries = int(raw_input())
for d in xrange(n_deliveries):
    n_packages = int(raw_input())

    quantities = []
    weights = []
    for p in xrange(n_packages):
        qt, weight = map(int, raw_input().split())
        quantities.append(qt)
        weights.append(weight)

    mem = [[0] * 101 for i in range(101)]
    ans = solve(n_packages - 1, 50)

    capacity = 50
    items = 0
    for i in xrange(n_packages - 1, 0, -1):
        if mem[i][capacity] != mem[i-1][capacity]:
            items += 1
            capacity -= weights[i]

    if mem[0][capacity] != 0:
        items += 1
        capacity -= weights[0]

    print '%d brinquedos' % (ans)
    print 'Peso: %d kg' % (50 - capacity)
    print 'sobra(m) %d pacote(s)' % (n_packages - items)
    print