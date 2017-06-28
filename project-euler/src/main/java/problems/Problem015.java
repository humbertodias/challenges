package problems;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem015 {

    static long solve(int NUMBER){
        final long[][] grid = new long[NUMBER+1][NUMBER+1];
        grid[0][0] = 0;
        for (int i=1; i <= NUMBER; i++){
            grid[i][0] = 1;
            grid[0][i] = 1;
        }
        for (int i=1; i <= NUMBER; i++){
            for (int j=1; j <=i; j++){
                grid[i][j] = grid[j][i] = grid[j-1][i] + grid[j][i-1];
            }
        }
        return grid[NUMBER][NUMBER];
    }

    public static void main(String ... args) {
        System.out.println(solve(2));
        System.out.println(solve(20));
    }

}
