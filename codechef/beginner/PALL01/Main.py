t = int(input())
for _ in range(t):
	n = str(input())
	if n == n[::-1] :
		print("wins")
	else:
		print("losses")