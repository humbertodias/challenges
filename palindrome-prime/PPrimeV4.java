public class PPrimeV4 {

    // Source:
    // https://github.com/darrensun/OJ-Solutions/blob/master/src/com/darrensun/spoj/palin/Main.java
    /**
     * Find the next palindrome of a given integer.
     * @param k The given integer as a string.
     * @return The next palindrome of k.
     */
     static String nextPalindrome(String k) {
        int n = k.length();
        // Construct a palindrome using the first half of k's digits (including the middle digit if k has odd number of digits)
        StringBuilder temp = new StringBuilder(k.substring(0, (n-1)/2+1));
        StringBuilder reverse = new StringBuilder(temp);
        if ((n & 1) == 1)   // k has odd number of digits
            reverse.deleteCharAt(reverse.length()-1);
        reverse.reverse();
        temp.append(reverse);
        String result = temp.toString();

        // The constucted palindrome is larger than k; it is the next palindrome of k.
        if (result.compareTo(k) > 0)
            return result;

        // Otherwise, we add the integer formed by the first half of k's digits by one,
        // and produce a palindrome based on it.
        for (int i = (n-1)/2; i >= 0; i--) {
            if (k.charAt(i) != '9') {
                // The addition increments the digit at position i,
                // and set the remaining (n-1)/2-i digits to zeroes
                temp = new StringBuilder(k.substring(0, i));
                temp.append((char)(k.charAt(i)+1));
                for (int j = i+1; j <= (n-1)/2; j++)
                    temp.append('0');

                reverse = new StringBuilder(temp);
                if ((n & 1) == 1)
                    reverse.deleteCharAt(reverse.length()-1);
                reverse.reverse();
                temp.append(reverse);
                return temp.toString();
            }
        }

        // The integer formed by the first half of k's digits is 9...9 (say, of m digits).
        // Its next palindrome must be 10...01 (of m+1 digits)
        temp = new StringBuilder("1");
        for (int i = 1; i < n; i++)
            temp.append('0');
        temp.append('1');

        return temp.toString();
    }

    static boolean isPalindrome(int number) {
        int palindrome = number; // copied number into variable
        int reverse = 0;

        while (palindrome != 0) {
            int remainder = palindrome % 10;
            reverse = reverse * 10 + remainder;
            palindrome = palindrome / 10;
        }

        // if original and reverse of number is equal means
        // number is palindrome in Java
        return (number == reverse);
    }

    static boolean isPrime(long num) {
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num < 2) return false;
        int lim = (int) Math.pow(num, 0.5) + 1;
        for (int i = 3; i < lim; i += 2) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    public static void main(String ... args) {
        int MAX = (args.length == 0) ? 1661 :  Integer.parseInt(args[0]);
        String sn = "2";
        int n = Integer.parseInt(sn);
        int found = 0;
        boolean DEBUG = false;
        while(true){
            if(isPrime(n)){
               found++;
               if(DEBUG)
               System.out.println(sn);
            }
            if (found >= 1661)  break;
            sn = nextPalindrome(sn);
            n = Integer.parseInt(sn);
        }

        System.out.printf("PPrime-v4[%d]=%s\n",found,sn);
    }
}
