package problems;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem004 {

    static int solve(){
        int product=0;
        int max=0;
        for(int i=999;i>100;i--)
        {
            for (int j=i;j>100;j--)
            {
                product=i*j;

                if(isPalindrome(product))
                {
                    //Just store maximum value of product.
                    //Following if loop is required in your code,in place of return i*j;
                    if(product>max)
                        max=product;
                }
            }
        }
        return max;
    }

    static boolean isPalindrome(int number) {
        int palindrome = number; // copied number into variable
        int remainder, reverse = 0;

        while (palindrome != 0) {
            remainder = palindrome % 10;
            reverse = reverse * 10 + remainder;
            palindrome = palindrome / 10;
        }

        // if original and reverse of number is equal means
        // number is palindrome in Java
        return number == reverse;
    }

    public static void main(String ... args) {
        System.out.println(solve());
    }

}
