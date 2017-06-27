package problems;


import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class ProblemsTest
{
    @Test
    public void problem01Solve()
    {
        assertEquals(233168, Problem001.solve(1000));
    }

    @Test
    public void problem02Solve()
    {
        assertEquals(4613732, Problem002.solve(4_000_000));
    }

    @Test
    public void problem03Solve()
    {
        assertEquals(6857, Problem003.solve(600851475143L));
    }

}

