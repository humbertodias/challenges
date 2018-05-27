import java.util.*;

public class Main{

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int t=1, N, p;
        while(scanner.hasNext()){
            N = scanner.nextInt();
            if(N == 0) break;
            System.out.format("Teste %d\n", t++);
            for(int i=1; i <= N; i++){
                if( i==scanner.nextInt() )
                    System.out.println(i);
            }
            System.out.println();
        }
    }

}