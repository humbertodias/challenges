package problems;

public class Problem006
{
    static int sumOfSquaresOfFirstNNaturalNumbers(int n){
        int sum = 0;
        for(int i=1; i<=n;i++)
            sum += i*i;
        return sum;
    }

    static int squareOfSumFirstNNaturalNumbers(int n){
        int sum = (n * (n + 1)) / 2;
        return sum * sum;
    }

    static int solve(int num){
        return squareOfSumFirstNNaturalNumbers(num) - sumOfSquaresOfFirstNNaturalNumbers(num);
    }

    public static void main( String ... args )
    {
        System.out.println( solve(10) );
        System.out.println( solve(100) );
    }
}
