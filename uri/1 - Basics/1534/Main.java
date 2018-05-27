import java.util.*;
class Main{
    public static void main (String []args){
        int n, i, j;
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()){
            n = scanner.nextInt();
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    if (i == j && i + j == n - 1) System.out.print("2");
                    else if (i == j) System.out.print("1");
                    else if (i + j == n - 1) System.out.print("2");
                    else System.out.print("3");
                }
                System.out.println();
            }
        }
    }

}