using System;

public class URI {
 
    public static void Main(string[] args){
 
        int NUMBER = Int32.Parse( System.Console.ReadLine().Trim() );
        int HOURS = Int32.Parse( System.Console.ReadLine().Trim() );
        double HOUR_VALUE = Convert.ToDouble( System.Console.ReadLine().Trim() );
        double SALARY = HOURS * HOUR_VALUE;

        Console.Write("NUMBER = {0}\n", NUMBER);
        Console.Write("SALARY = U$ {0:F2}\n", SALARY);
 
    }
 
}
