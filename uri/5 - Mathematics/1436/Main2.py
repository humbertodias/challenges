nTests = int(raw_input())
for test in range(1, nTests + 1):
    ages = map(int, raw_input().split())
    print 'Case %d: %d' % (test, ages[len(ages) / 2])