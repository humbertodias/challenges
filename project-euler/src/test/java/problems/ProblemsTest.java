package problems;


import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class ProblemsTest
{
    @Test
    public void problem001()
    {
        assertEquals(23, Problem001.solve(10));
        assertEquals(233168, Problem001.solve(1000));
    }

    @Test
    public void problem002()
    {
        assertEquals(4613732, Problem002.solve(4_000_000));
    }

    @Test
    public void problem003()
    {
        assertEquals(29, Problem003.solve(13195L));
        assertEquals(6857, Problem003.solve(600851475143L));
    }

    @Test
    public void problem004()
    {
        assertEquals(906609, Problem004.solve());
    }

    @Test
    public void problem005()
    {
        assertEquals(2520, Problem005.solve(10));
        assertEquals(232792560, Problem005.solve(20));
    }

    @Test
    public void problem006()
    {
        assertEquals(2640, Problem006.solve(10));
        assertEquals(25164150, Problem006.solve(100));
    }

    @Test
    public void problem007()
    {
        assertEquals(13, Problem007.solve(6));
        assertEquals(104743, Problem007.solve(10_001));
    }

    @Test
    public void problem008()
    {
        assertEquals(5832, Problem008.solve(4));
        assertEquals(23514624000L, Problem008.solve(13));
    }

    @Test
    public void problem009()
    {
        assertEquals(31875000, Problem009.solve(1000));
    }

    @Test
    public void problem010()
    {
        assertEquals(17, Problem010.solve(10));
        assertEquals(142913828922L, Problem010.solve(2_000_000));
    }

    @Test
    public void problem011()
    {
        assertEquals(70600674, Problem011.solve());
    }

    @Test
    public void problem012()
    {
        assertEquals(28, Problem012.solve(5));
        assertEquals(76576500, Problem012.solve(500));
    }


    @Test
    public void problem013()
    {
        assertEquals("5537376230", Problem013.solve(10));
    }

    @Test
    public void problem014()
    {
        assertEquals(837799, Problem014.solve(1_000_000));
    }

    @Test
    public void problem015()
    {
        assertEquals(6, Problem015.solve(2));
        assertEquals(137846528820L, Problem015.solve(20));
    }

    @Test
    public void problem016()
    {
        assertEquals(26, Problem016.solve(15));
        assertEquals(1366, Problem016.solve(1000));
    }

    @Test
    public void problem017()
    {
        assertEquals(39, Problem017.solve(10));
        assertEquals(21124, Problem017.solve(1000));
    }

    @Test
    public void problem018()
    {
        assertEquals(1074, Problem018.solve());
    }

    @Test
    public void problem019()
    {
        assertEquals(171, Problem019.solve());
    }

    @Test
    public void problem0120()
    {
        assertEquals(27, Problem020.solve(10));
        assertEquals(648, Problem020.solve(100));
    }

}

