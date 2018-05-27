import java.util.*;

public class Main {

    public static long sum(Long n){
        long sum = 0l;
        String s = Long.toString(n);
        for(int i=0; i< s.length(); i++)
            sum += Character.getNumericValue(s.charAt(i));
        return sum;
    }   

    public static void main(String[] args) {
        String answer;
        Long sum, n, m;
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {   
            n = in.nextLong();
            m = in.nextLong();
            sum = sum(m);
            answer = ((sum % 3) == 0) ? "sim" : "nao";
            System.out.println( sum + " " + answer );
        }       
    }
}