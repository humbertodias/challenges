primes = []
# CACHE = int(10**5) # Cache size for Sieve
CACHE = int(12640) #12640 ** 2 = 159769600 < 159323951
# Cache size for Sieve
# https://stackoverflow.com/questions/20650623/next-higher-prime-and-palindrome-number

def sieve():
    global primes
    is_prime = [False,False]+([True]*(CACHE-1))
    for i in range(2,int(CACHE**0.5)):
        if is_prime[i]:
            is_prime[i*i::i] = [False]*((CACHE-i*i+i)//i)
    primes = [num for num, bool_prime in enumerate(is_prime) if bool_prime]

def is_prime(n):
    """Checks whether n is prime"""
    global primes
    if n<2:
        return False
    if n==2:
        return True
    for prime in primes:
        if prime>n**0.5+1:
            return True
        if n%prime==0:
            return False
    # For the case that the number is bigger than the square of our largest prime
    for num in range(primes[-1]+2,n**0.5+1,2):
        if n%num==0:
            return False
    return True

def next_higher_odd_length_palindrome(num):
    length=len(str(num))
    oddDigits=(length%2!=0)
    leftHalf=get_left_half(num)
    middle=get_middle(num)
    if oddDigits:
        increment=pow(10, length//2)
        newNum=int(leftHalf+middle+leftHalf[::-1])
    else:
        increment=int(1.1*pow(10, length//2))
        newNum=int(leftHalf+leftHalf[::-1])
    if newNum>num:
        return newNum
    if middle!='9':
        return newNum+increment
    else:
        return next_higher_odd_length_palindrome(round_up(num))

def get_left_half(num):
    return str(num)[:len(str(num))//2]
 
def get_middle(num):
    return str(num)[(len(str(num))-1)//2]
 
def round_up(num):
    length=len(str(num))
    increment=pow(10,((length//2)+1))
    return ((num//increment)+1)*increment

def next_higher(n):
    # Ensure the number is a palindrome of odd length
    n = next_higher_odd_length_palindrome(n)
    while True:
        if is_prime(int(n)):
            return int(n)
        n = str(next_higher_odd_length_palindrome(int(n)))
        if int(n[0])%2==0:
            new_lead = str(int(n[0])+1)
            n = new_lead+n[1:-1]+new_lead

def main(DEBUG):
    # cache
    sieve()

    found, num = 0, 2
    while True:
      found += 1
      if DEBUG:
          print(num)
      if found >= 1661: 
        break
      num = next_higher(num)

    print ("pprime-v3[%s]=%s" % (found, num) )

main(False)