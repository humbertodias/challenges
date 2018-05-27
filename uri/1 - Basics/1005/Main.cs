using System;

public class URI {
 
    public static void Main(string[] args){

        double A = Convert.ToDouble( System.Console.ReadLine().Trim());
        double B = Convert.ToDouble( System.Console.ReadLine().Trim());
        double MEDIA = (A*3.5 + B*7.5) / 11D;
        Console.Write("MEDIA = {0:F5}\n", MEDIA);
 
    }
 
}
