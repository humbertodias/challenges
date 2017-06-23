import org.junit.*;

import static org.junit.Assert.assertEquals;

public class PPrimeV4Test 
{
    
    @Test
    public void testPPrimeV4()
    {
        assertEquals( 159323951L , PPrimeV4.find(1661L) );
    }

}
