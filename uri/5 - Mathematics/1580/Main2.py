def count_letters(word):
    letters = {}
    for l in word:
        if l in letters:
            letters[l] += 1
        else:
            letters[l] = 1

    return sorted(letters.values(), reverse = True)

def fact(n):
    res = 1
    for i in xrange(1, n + 1):
        res *= i
    return res

while True:
    try:
        word = raw_input()
    except EOFError:
        break

    letters = count_letters(word)
   
    anagrams = fact(len(word))
    for l in letters:
        anagrams /= fact(l)

    print anagrams % (10**9 + 7)