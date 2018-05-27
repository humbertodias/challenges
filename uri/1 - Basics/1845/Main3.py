# coding: utf-8

letter = ['s','j','b','z','p','v','x',"S","J","B","Z","P","V","X"]

while True:
    try:
        a = input()
        b = a[::]
    except EOFError:
        break
    for l in a:
        if l in letter:
            b = b.replace(l.upper(),'F')
            b = b.replace(l.lower(),'f')
            b = b.replace('ff','f')
            b = b.replace('Ff','F')
            b = b.replace('fF','f')
            a = b.replace('FF','F')
    b = b.replace('ff','f')
    b = b.replace('Ff','F')
    b = b.replace('fF','f')
    a = b.replace('FF','F')
    print(a)
