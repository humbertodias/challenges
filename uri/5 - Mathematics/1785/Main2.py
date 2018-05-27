def bigger(n):
    num = map(int, n)
    num.sort(reverse = True)
    return ''.join(map(str, num))

def lower(n):
    num = map(int, n)
    num.sort()
    return ''.join(map(str, num))

def krapekar(n):
    cnt = 0
    while (int(n) != 6174):
        if int(n) == 0:
            return -1
        
        if len(n) < 4:
            n = '%04d' % (int(n))
        
        maxi = bigger(n)
        mini = lower(n)
        n = str(int(maxi) - int(mini))
        cnt += 1

    return cnt


nTests = int(raw_input())
for nt in xrange(1, nTests + 1):
    n = raw_input()

    print 'Caso #%d: %d' % (nt, krapekar(str(n)))