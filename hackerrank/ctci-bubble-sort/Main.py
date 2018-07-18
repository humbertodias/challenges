n = int(input())
a = [int(x) for x in input().split()]

swaps = 0
flag = True

while flag:
    flag = False
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            a[i], a[i + 1] = a[i + 1], a[i]
            swaps += 1
            flag = True

print("Array is sorted in %d swaps." % swaps)
print("First Element: %d" % a[0])
print("Last Element: %d" % a[-1])
