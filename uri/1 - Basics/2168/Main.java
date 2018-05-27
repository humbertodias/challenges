import java.util.*;

class Main{

    public static void main(String [] args){

        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int [][] matrix = new int[N+1][N+1];
        int [] sum = new int[ (N*N)];
        Arrays.fill(sum, 0);
        for(int i=0, id=0; i<= N; i++){
            for(int j=0; j<= N; j++){
                matrix[i][j] = scanner.nextInt();
            }
        }

        int k=0;
        for(int i=0; i < N; i++){
            for(int j=0; j < N; j++){

                    sum[k] += matrix[i][j];
                    sum[k] += matrix[i][j+1];
                    sum[k] += matrix[i+1][j+1];
                    sum[k] += matrix[i+1][j];

                    if(sum[k] >= 2)
                        System.out.print("S");
                    else
                        System.out.print("U");
                    k++;
            }
            System.out.println();
        }

    }
}