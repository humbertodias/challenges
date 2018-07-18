n = int(input())
d = {}
for x in range(n):
	kv = input().split()
	d[kv[0]]=int(kv[1])
# TODO
sorted_d = reversed(sorted((value, key) for (key,value) in d.items()))
for item in sorted_d:
	print ("%s: %s" % (item[0], item[1]))
