using System; 
 
public class URI {
 
    public static void Main(string[] args) {
 
        double PI = 3.14159;
        double R = double.Parse( System.Console.ReadLine().Trim() );
        double A = PI * R * R;
        Console.Write("A={0}\n", A.ToString(".0000") );

    }
 
}
