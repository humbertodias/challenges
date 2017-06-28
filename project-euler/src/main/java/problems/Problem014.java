package problems;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem014 {

    static long solve(int max){
        long sequenceLength = 0;
        long startingNumber = 0;
        long sequence;

        for (int i = 2; i <= max; i++) {
            int length = 1;
            sequence = i;
            while (sequence != 1) {
                if ((sequence % 2) == 0) {
                    sequence = sequence / 2;
                } else {
                    sequence = sequence * 3 + 1;
                }
                length++;
            }

            //Check if sequence is the best solution
            if (length > sequenceLength) {
                sequenceLength = length;
                startingNumber = i;
            }
        }
        return startingNumber;
    }

    public static void main(String ... args) {
        System.out.println(solve(1_000_000));
    }

}
