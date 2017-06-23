
**PPrime** is a prime palindromic number.

## Tests

1. Brute force for Prime and Palindrome

	```
	$ time python pprime-v1.py
	pprime-v1[1661]=159323951
	
	real    1m24.221s
	user    0m0.000s
	sys     0m0.000s
	```
	[pprime-v1.py](pprime-v1.py)

2.  Brute force for Prime and Math Guess for Palindrome

	```
	$ time python pprime-v2.py
	pprime-v2[1661]=159323951
	
	real    0m0.724s
	user    0m0.000s
	sys     0m0.000s
	```
	[pprime-v2.py](pprime-v2.py)

3.  Sieve of Eratosthenes for Prime and Math Guess for Palindrome

	```
	$ time python pprime-v3.py
	pprime-v3[1661]=159323951
	
	real    0m0.851s
	user    0m0.000s
	sys     0m0.031s
	```
	[pprime-v3.py](pprime-v3.py)

4. Brute force for Prime and Math Guess for Palindrome

	```
	$ javac PPrimeV4.java
	$ time java PPrimeV4 1661
	PPrime-v4[1661]=159323951
	
	real    0m0.285s
	user    0m0.000s
	sys     0m0.015s
	```
	[PPrimeV4.java](PPrimeV4.java)

5. Brute force for Prime and Math Guess for Palindrome with bytes Array

	```
	$ javac PPrimeV5.java
	time java PPrimeV5 1661
	PPrimeV5[1661]=159323951
	
	real	0m0.201s
	user	0m0.199s
	sys	0m0.035s
	```
	[PPrimeV5.java](PPrimeV5.java)
	
	or
	
	```
	mvn compile exec:java -Dexec.mainClass="PPrimeV5"
	```
