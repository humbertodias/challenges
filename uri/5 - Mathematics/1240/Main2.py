nTests = int(raw_input())
for test in range(nTests):
    a, b = raw_input().split()
    if len(b) <= len(a) and b == a[-len(b):]:
        print 'encaixa'
    else:
        print 'nao encaixa'