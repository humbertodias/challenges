import operator
import functools

def comparator(a, b):
    if a[1] != b[1]:
        if a[1] > b[1]:
            return -1
        else:
            return 0
    else:
        if a[0] < b[0]:
            return -1
        else:
            return 0
        

while True:
    n_lines = int(raw_input())

    if n_lines == 0: break

    text = ''
    for n in xrange(n_lines):
        text += raw_input()

    freq = {}
    for i in xrange(len(text) - 1):
        digraph = text[i:i+2]
        if digraph in freq:
            freq[digraph] += 1
        else:
            freq[digraph] = 1

    ord_freq = sorted(freq.items(), key=functools.cmp_to_key(comparator))

    for i in xrange(5):
        print '%s %d %.6f' % (ord_freq[i][0], ord_freq[i][1], ord_freq[i][1] / float((len(text) - 1)))
    print