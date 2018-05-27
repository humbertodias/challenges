import re, sys
 
def merge(a, left, mid, right):
    """
    Merge fuction
    """
    #Copy array
    global count
    copy_list = []
    i, j = left, mid + 1
    ind = left
 
    while ind < right+1:
        #if left array finish merging, copy from right side
        if i > mid:
         copy_list.append(a[j])
         j +=1
        #if right array finish merging, copy from left side
        elif j > right:
         copy_list.append(a[i])
         i +=1
        #Check if right array value is less than left one
        elif a[j] < a[i]:
         count += len(a[j:])
         copy_list.append(a[j])
         j +=1
        else:
         copy_list.append(a[i])
         i +=1
        ind +=1
 
    ind=0
    for x in (xrange(left,right+1)):
        a[x] = copy_list[ind]
    ind += 1
 
def mergesort(list_, left, right):
    """
    Iterative version of the Merge Sort Algorithm
    """
    factor = 2
    temp_mid = 0
    #Main loop to iterate over the array by 2^n.
    while 1:
        index = 0
        left = 0
        right = len(list_) - (len(list_) % factor) - 1
        mid = (factor / 2) - 1
 
        #Auxiliary array to merge subdivisions
        while index < right:
            temp_left = index
            temp_right = temp_left + factor -1
            mid2 = (temp_right +temp_left) / 2
            merge (list_, temp_left, mid2, temp_right)
            index = (index + factor)
 
        #Chek if there is something to merge from the remaining
        #Sub-array created by the factor
        if len(list_) % factor and temp_mid !=0:
            #merge sub array to later be merged to the final array
            merge(list_, right +1, temp_mid, len(list_)-1)
            #Update the pivot
            mid = right
        #Increase the factor
        factor = factor * 2
        temp_mid = right
 
        #Final merge, merge subarrays created by the subdivision
        #of the factor to the main array.
        if factor > len(list_) :
            mid = right
            right = len(list_)-1
            merge(list_, 0, mid, right)
            break
 
while True:
    try:
        entrada = int(raw_input())
    except Exception:
        break
 
    count = 0
    lista = []
 
    while entrada:
        mat = raw_input()
        mat = re.sub('/', '', mat)
        lista.append(int(mat))
        entrada -= 1
 
    mergesort(lista, 0, len(lista)-1)
    print count