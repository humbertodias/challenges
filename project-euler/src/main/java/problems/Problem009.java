package problems;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem009 {

    static int solve(int finalSum){

        for (int a = 1; a < finalSum; a++) {
            for (int b = a + 1; b < finalSum; b++) {
                int c = finalSum - a - b;
                if (a * a + b * b == c * c)  // Note: This implies b < c
                return (a * b * c);
            }
        }
        return -1;

    }

    public static void main(String ... args) {
        System.out.println(solve(1000));
    }

}
