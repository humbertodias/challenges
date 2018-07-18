def array_left_rotation(a, n, k):
    # Creta Empty List
    b = []
    # Loop through a
    for i in range(n):
        # Append new position value to b
        b.append(a[(i + k) % n])
    return b
 
n, d = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
answer = array_left_rotation(a, n, d);
print(*answer, sep=' ')