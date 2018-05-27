import java.util.*;

class Main{

    // static int[][] transposta(int m[][]){
    //     int M = m.length;
    //     int N = m[0].length;
    //     int mt[][] = new int[M][N];

    //     for (int i = 0; i < M; i++)
    //         for (int j = 0; j < N; j++)
    //             mt[j][i] = m[i][j];
        
    //     return mt;        
    // }

    static int[][] transposeMatrix(int [][] m){
        int[][] temp = new int[m[0].length][m.length];
        for (int i = 0; i < m.length; i++)
            for (int j = 0; j < m[0].length; j++)
                temp[j][i] = m[i][j];
        return temp;
    }

    static void show(int [][] m){
        int col = m[0].length;
        int row = m.length;

        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                System.out.print(m[i][j] + " ");

            }
            System.out.println();
        }

    }


    static boolean ehTransposta(int m[][]){
        int M = m.length;
        int N = m[0].length;
        int mt[][] = transposeMatrix(m);

        // 1 - É uma matriz quadrada.
        if(N!=M) return false;

        // 2 - A primeira coluna é formada apenas por 1's.
        for (int i = 0; i < M; i++){
            if(mt[0][i] != 1) return false;
        }

        // 3 - Para todo elemento (i, j) com j > 1, (i, j) = (i, 2)j-1 e (i, j) é diferente de zero.
        for (int i = 0; i < M; i++)
            for (int j = 1; j < N; j++)
                if(mt[i][j] == 0) return false;

        return true;
    }

    public static void main(String args[]){

        Scanner scanner = new Scanner(System.in);
        int C, N;
        int m1[][];

        C = scanner.nextInt();
        while( (C--) > 0){
            N = scanner.nextInt();
            m1 = new int[N][N];

            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    m1[i][j] = scanner.nextInt();
                }
            }

            // show(m1);

            System.out.println(ehTransposta(m1) ? "Potencia" : "Nao Potencia");

        }

    }
}