import collections
import sys
sys.setrecursionlimit(10000)


def solve(word):
    if word in sub_strings or len(word) == 0:
        return
   
    sub_strings[word] = 0
    
    for i in xrange(len(word)):
        solve(word[:i] + word[i+1:])

    return


while True:
    sub_strings = {}
    
    try:
        word = raw_input()
    except EOFError:
        break

    solve(word)
    ans = sorted(sub_strings)
    for e in ans:
        print e
    print