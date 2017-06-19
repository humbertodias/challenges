from sys import argv

def isPrime(n):
    if (n < 2):
        return False
    if (n == 2):
        return True
    if (n % 2 == 0):
        return False
    maxFactor = round(n**0.5)
    for factor in range(3,int(maxFactor+1),2):
        if (n % factor == 0):
            return False
    return True

def main():
    MAX = 10 if len(argv) < 2 else int(argv[1])

    n = 2
    while n < MAX:
        if isPrime(n):
            print(n)
        n += 1

main()