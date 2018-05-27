import java.util.*;

public class Main {


public static String longestPalindrome(String s) {
    if (s.isEmpty()) {
        return null;
    }
 
    if (s.length() == 1) {
        return s;
    }
 
    String longest = s.substring(0, 1);
    for (int i = 0; i < s.length(); i++) {
        // get longest palindrome with center of i
        String tmp = helper(s, i, i);
        if (tmp.length() > longest.length()) {
            longest = tmp;
        }
 
        // get longest palindrome with center of i, i+1
        tmp = helper(s, i, i + 1);
        if (tmp.length() > longest.length()) {
            longest = tmp;
        }
    }
 
    return longest;
}
 
// Given a center, either one letter or two letter, 
// Find longest palindrome
public static String helper(String s, int begin, int end) {
    while (begin >= 0 && end <= s.length() - 1 && s.charAt(begin) == s.charAt(end)) {
        begin--;
        end++;
    }
    return s.substring(begin + 1, end);
}

    static String listToString(List<String> l){
        StringBuilder sb = new StringBuilder();
        
        for(String s : l)
            sb.append(s);

        return sb.toString();
    }

public static String longestPalindrome2(String s) {
        boolean[][] P = new boolean[s.length()][s.length()];
        int max = 0;
        int start = 0;
        for (int k = 0; k < s.length(); k++) {
            for (int i = 0; i < s.length() - k; i++) {
                if (s.charAt(i) == s.charAt(i + k)) {
                    if (k < 2 || P[i + 1][i + k - 1]) {
                        P[i][i + k] = true;
                        if (k > max) {
                            max = k;
                            start = i;
                        }
                    }
                }
            }
        }
        return s.substring(start, start + max + 1);
    }

   public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T;
    String word;
    List<String> words = new ArrayList<>();
    while(scanner.hasNext()){
        T = Integer.parseInt(scanner.nextLine());
        for(int i=0; i<T; i++){
            words.add( scanner.nextLine() );
        }

        System.out.println( longestPalindrome2( listToString(words) ) ) ;
        words.clear();

    }
   }
 

}