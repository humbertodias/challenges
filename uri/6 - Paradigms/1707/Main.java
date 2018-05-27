import java.util.*;

public class Main{

    static long previousEven(long n){
        if(n % 2 == 0) return n;
        return previousEven(n-1);
    }

    static long nextEven(long n){
        if(n % 2 == 0) return n;
        return nextEven(n+1);
    }

    // static long previousOdd(long n){
    //     if(n % 2 != 0) return n;
    //     return previousOdd(n-1);
    // }

    // static long nextOdd(long n){
    //     if(n % 2 != 0) return n;
    //     return nextOdd(n+1);
    // }


    static long sumOfEvenNumber(long min, long max){
        //sum of even number: n((first even+last even)/2) 
        long firstEven = nextEven(min);
        long lastEven = previousEven(max);
        long n = findN(min, max);
        return n * ((firstEven+lastEven)/2L);
    }

    static long findN(long min, long max){
        // (First Even + Last Even)/2 - 1
        long firstEven = nextEven(min);
        long lastEven = previousEven(max);
        return ((firstEven + lastEven)/2L) - 1L;
    }

    static long sumOfOddNumber(long n){
        return ((n * (n+1))/2) - ((n/2)*(n/2+1));
    }

    static long somaImpares(long min, long max){
        long sum = 0;
        for(long i=min; i <= max; i++){
            if(i%2!=0) sum++;
        }
        return sum;
    }

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        long min, max, n, sum;
        while(scanner.hasNext()){
            min = scanner.nextLong();
            max = scanner.nextLong();
            n = findN(min, max);
            sum = somaImpares(min,max);
            System.out.printf("min:%d, max:%d, n:%d, sum:%d\n", min, max, n, sum);
            System.out.println(sum);
        }
    }
}