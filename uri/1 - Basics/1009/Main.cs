using System;

public class URI{

	public static void Main(string [] args) {
	    double f1, f2, f3;
	    System.Console.ReadLine().Trim();
        f1 = Convert.ToDouble( System.Console.ReadLine().Trim() );
        f2 = Convert.ToDouble( System.Console.ReadLine().Trim() );
	    f3 = f1 + (15.0*f2/100.0);
	    Console.Write("TOTAL = R$ {0:F2}\n", f3);
	}
}