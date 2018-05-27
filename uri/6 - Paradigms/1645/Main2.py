def solve(start, k):
    if mem[start][k] != -1:
        return mem[start][k]

    if k == 1:
        mem[start][k] = 1
        return 1

    sum_seqs = 0
    for i in xrange(start + 1, n):
        if nums[start] < nums[i]:
            sum_seqs += solve(i, k - 1)
    
    mem[start][k] = sum_seqs
    return sum_seqs


while True:
    n, k = map(int, raw_input().split())

    if n == 0 and k == 0: break

    nums = map(int, raw_input().split())

    mem = [[-1]*(k + 1) for i in xrange(n)]
    seqs = 0
    for i in xrange(n):
        seqs += solve(i, k)

    print seqs