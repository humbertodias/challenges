def is_pal(num):
	snum = str(num)
	return snum == snum[::-1]

def is_prime(num):
    if num==2 or num==3: return True
    if num%2==0 or num<2: return False
    for i in range(3,int(num**0.5)+1,2):   # only odd numbers
        if num%i==0:
            return False    
    return True

def main(DEBUG):
	found, num = 0, 2 
	while True:
		if is_pal(num) and is_prime(num):
			found += 1
			if DEBUG:
				print(num)
		if found >= 1661: 
			break
		num += 1
	print ("pprime-v1[%s]=%s" % (found, num) )

main(False)
