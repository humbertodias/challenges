package problems;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem005 {

    static int solve(int max){
        int i = 0;
        while( !divisibleByInterval(++i, max) );
        return i;
    }

    static boolean divisibleByInterval(int num, int max){
        for(int i=1; i <= max; i++){
            if(num % i != 0)
                return false;
        }
        return true;
    }


    public static void main(String ... args) {
        System.out.println(solve(20));
    }

}
