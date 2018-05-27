import java.util.*;
import java.text.*;

class Main{

    public static List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>();
        int half = rowIndex / 2; 
        long cur = 1;
        result.add((int)(cur));
        // since every row is symmetric, we just need to compute half of kth row
        for(int i = 1; i <= half; i++) {  
            cur = cur * (rowIndex - i + 1) / i;
            result.add((int)(cur));
        }
        if(rowIndex % 2 == 0) {
            half -= 1;
        }
        for(int i = half; i >= 0; i--) { 
            result.add(result.get(i));
        }
        return result;
    }

    public static int sum(List<Integer> ints) {
        int len = ints.size();
        if (len == 0) return 0;
        if (len == 1) return ints.get(0);
        return sum(ints.subList(0, len/2)) + sum(ints.subList(len/2, len));
    }

    public static void main(String [] args) throws Exception{
        Scanner scanner = new Scanner(System.in);
        int t, n;
        while(scanner.hasNext()){
            t = scanner.nextInt();
            for(int i=0; i<t; i++){
                n = scanner.nextInt();
                System.out.println(sum(getRow(n))-1 );
            }
        }
    }
}