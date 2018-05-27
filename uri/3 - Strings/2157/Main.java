import java.util.*;

public class Main{

    public static void main(String args[]){
        Scanner scanner  = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int C, B, E;
        while(scanner.hasNext()){
            C = scanner.nextInt();
            
            for(int i=0; i<C;i++){
                B = scanner.nextInt();
                E = scanner.nextInt();
                for(int j=B; j <= E; j++){
                    System.out.print(j);
                    sb.append(j);
                }

                System.out.println(sb.reverse());
                sb.setLength(0);
            }


        }
    }
}