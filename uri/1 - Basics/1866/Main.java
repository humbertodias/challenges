import java.util.*;
class Main{
    public static void main(String []args){

        int n, res;
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        while(N-- > 0){
            n = scanner.nextInt();
            res = 0;

            while(n-- > 0){
                if(n%2 == 0) res++;
                else res--;
            }

            System.out.println(res);

        }

    }

}