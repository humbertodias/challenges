using System;

public class URI {
 
    public static void Main(string[] args){

        double A = Convert.ToDouble( System.Console.ReadLine().Trim());
        double B = Convert.ToDouble( System.Console.ReadLine().Trim());
        double C = Convert.ToDouble( System.Console.ReadLine().Trim());
        double MEDIA = (A*2 + B*3 + C*5) / 10D;
        Console.Write("MEDIA = {0:F1}\n", MEDIA);
 
    }
 
}
