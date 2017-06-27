package problems;


import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class ProblemsTest
{
    @Test
    public void problem01Solve()
    {
        assertEquals(23, Problem001.solve(10));
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
        assertEquals(29, Problem003.solve(13195L));
        assertEquals(6857, Problem003.solve(600851475143L));
    }

    @Test
    public void problem04Solve()
    {
        assertEquals(906609, Problem004.solve());
    }

    @Test
    public void problem05Solve()
    {
        assertEquals(2520, Problem005.solve(10));
        assertEquals(232792560, Problem005.solve(20));
    }

    @Test
    public void problem06Solve()
    {
        assertEquals(2640, Problem006.solve(10));
        assertEquals(25164150, Problem006.solve(100));
    }

    @Test
    public void problem07Solve()
    {
        assertEquals(13, Problem007.solve(6));
        assertEquals(104743, Problem007.solve(10_001));
    }

    @Test
    public void problem08Solve()
    {
        assertEquals(5832, Problem008.solve(4));
        assertEquals(23514624000L, Problem008.solve(13));
    }

}

