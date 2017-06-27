package problems;

import java.util.Iterator;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

// http://antrix.net/posts/2015/streams-java-8/
class FibonacciSequence implements Iterator<Integer>, Iterable<Integer> {

    private final Integer max;
    private Integer previous;
    private Integer current;

    public FibonacciSequence(int max) {
        this.previous = -1;
        this.current = 1;
        this.max = max;
    }

    @Override
    public Integer next() {
        Integer next = previous + current;
        previous = current;
        current = next;
        return next;
    }

    @Override
    public boolean hasNext() {
        return current <= max;
    }

    @Override
    public Iterator<Integer> iterator() {
        return this;
    }

}

public class Problem002
{

    static int solve(int limit){
        FibonacciSequence fibonacciSequence = new FibonacciSequence(limit);
        Stream<Integer> fibStream = StreamSupport.stream(fibonacciSequence.spliterator(), false);
        return fibStream
                .filter(i -> i % 2 == 0)
                .mapToInt(i -> i)
                .sum();
    }

    public static void main( String ... args )
    {
        System.out.println(solve(4_000_000));
    }

}
