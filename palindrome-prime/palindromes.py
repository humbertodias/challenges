from sys import argv

def isPalindrome(n):
    sn = str(n)
    return sn == sn[::-1]

def main():
	MAX = 20 if len(argv) < 2 else int(argv[1])

	n = 0
	while n < MAX:
	    if isPalindrome(n):
	        print(n)
	    n += 1

main()