public class PPrimeV5 {

    public static void main(String ... args) {
		 int limit = args.length < 1 ? 1661 : Integer.parseInt(args[0]);
         System.out.printf("PPrimeV5[%d]=%d\n", limit, find(limit));
     }

    public static int find(int limit){
        int n = 0, i = 0;
        byte [] digits = {2};
        while(i < limit){
           if(isPrime(n = toInt(digits))) i++;
           digits = nextPalindrome(digits);
        }
        return n;
    }

    private static byte[] nextPalindrome(byte[] digits) {
        int len = digits.length;

        int i = (len - 1) / 2 + 1;

        while (--i >= 0) {
            if (digits[i] < 9) {
                digits[len - i - 1] = digits[i] = (byte) (digits[i] + 1);
                return digits;
            } else {
                digits[len - i - 1] = digits[i] = 0;
            }
        }

        return firstPalindromeOfLength(len + 1);
    }

    private static byte[] firstPalindromeOfLength(int len) {
        byte[] result = new byte[len];
        result[result.length - 1] = result[0] = 1;
        return result;
    }

    private static boolean isPrime(int num) {
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num < 2) return false;
        int lim = (int) Math.pow(num, 0.5) + 1;
        for (int i = 3; i < lim; i += 2) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    private static int toInt(byte[] digits){
        int result = 0;

        for (byte d : digits) {
            result += d;
            result *= 10;
        }

        result /= 10;

        return result < 0 ? -result : result;
    }

}
