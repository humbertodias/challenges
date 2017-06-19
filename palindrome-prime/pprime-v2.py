def next_palindrome(num):
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
        return next_palindrome(round_up(num))

def get_left_half(num):
    return str(num)[:len(str(num))//2]
 
def get_middle(num):
    return str(num)[(len(str(num))-1)//2]
 
def round_up(num):
    length=len(str(num))
    increment=pow(10,((length//2)+1))
    return ((num//increment)+1)*increment

def is_prime(num):
    if (num < 2):
        return False
    if (num == 2):
        return True
    if (num % 2 == 0):
        return False
    maxFactor = round(num**0.5)
    for factor in range(3,int(maxFactor+1),2):
        if (num % factor == 0):
            return False
    return True

def main(DEBUG):
    found, num = 0, 2 
    while True:
        if is_prime(num):
            found += 1
            if DEBUG:
                print(num)
        if found >= 1661: 
            break
        num = next_palindrome(num)

    print ("pprime-v2[%s]=%s" % (found, num) )


main(False)
