import sys

def A005150(n):
   seq = [3] + [None] * (n - 1) # allocate entire array space
   def say(s):
       acc = '' # initialize accumulator
       while len(s) > 0:
           i = 0
           c = s[0] # char of first run
           while (i < len(s) and s[i] == c): # scan first digit run
               i += 1
           acc += str(i) + c # append description of first run
           if i == len(s):
               break # done
           else:
               s = s[i:] # trim leading run of digits
       return acc
   for i in xrange(1, n):
       seq[i] = int(say(str(seq[i-1])))
   # return seq
   return seq[n-1]

# https://oeis.org/A005150

for line in sys.stdin:
  print A005150(int(line))