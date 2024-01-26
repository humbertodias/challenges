using System;

class URI {
	static void Main(string[] args) {
		var l1 = Array.ConvertAll(Console.ReadLine().Split(" "),double.Parse);
		var l2 = Array.ConvertAll(Console.ReadLine().Split(" "),double.Parse);
		double x1 = l1[0];
	    double y1 = l1[1];
	    double x2 = l2[0];
	    double y2 = l2[1];

		double distance = Math.Sqrt(Math.Pow( (x2-x1),2) + Math.Pow( (y2-y1),2));
		Console.WriteLine($"{distance:F4}");
	}	
}
