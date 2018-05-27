import java.math.*;
import java.util.*;
import java.text.*;


public class Main{

    public static void main(String[] args)  {
        Scanner scanner = new Scanner(System.in);
        String s[];
        String biggestWord = new String();
        while(scanner.hasNext()){
            s = scanner.nextLine().split(" ");

            if(s.length == 1 && "0".equals(s[0]))
                break;

            for(int i=0; i<s.length; i++){
                if(i<s.length-1)
                    System.out.print(s[i].length() + "-");
                else
                    System.out.print(s[i].length() + "\n");

                if(s[i].length()>=biggestWord.length())
                    biggestWord = s[i];
            }
        }
        System.out.format("\nThe biggest word: %s\n", biggestWord);
    }

}