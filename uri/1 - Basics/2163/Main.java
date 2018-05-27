import java.util.*;

class Main{

    public static void main(String [] args){

        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int [][] matrix = new int[N][M];
        for(int i=0; i< N; i++){
            for(int j=0; j< M; j++){
                matrix[i][j] = scanner.nextInt();
            }
        }

        int X = 0, Y = 0;
        for(int i=0; i < N; i++){
            for(int j=0; j < M; j++){
                if(matrix[i][j] == 42){
                    if( ((i-1) >= 0 && (i+1) < N) && ((j-1)>=0 && (j+1)<M) ){
                        if(matrix[i+1][j] == 7
                        && matrix[i+1][j+1] == 7 
                        && matrix[i][j+1] == 7 
                        && matrix[i-1][j+1] == 7
                        && matrix[i-1][j] == 7 
                        && matrix[i-1][j-1] == 7 
                        && matrix[i][j-1] == 7 
                        && matrix[i+1][j-1] == 7 
                            ){
                            X = i+1;
                            Y = j+1;
                            break;
                        }
                    }
                }
            }
        }
        System.out.printf("%d %d\n", X, Y);

    }
}