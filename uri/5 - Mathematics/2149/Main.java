import java.util.*;

public class Main{

    public static void main(String args[]){
        Scanner scanner  = new Scanner(System.in);
        String [] sequence = {"0", "1", "1", "1", "2", "2", "4", "8", "12", "96", "108", "10368", "10476", "108615168", "108625644", "11798392572168192", "11798392680793836", "139202068568601556987554268864512", "139202068568601568785946949658348", "19377215893777651167043206536157390321290709180447278572301746176"};
        while(scanner.hasNext()){
          System.out.println(sequence[scanner.nextInt()-1]);
        }
    }
}