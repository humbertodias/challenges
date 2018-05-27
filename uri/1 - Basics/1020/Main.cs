using System;

class URI{
	public static void Main(string [] args){
	    int a = Int32.Parse( System.Console.ReadLine().Trim());
	    Console.Write( a/365 + " ano(s)\n" );
	    Console.Write( (a%365)/30 + " mes(es)\n");
	    Console.Write( (a%365)%30 + " dia(s)\n");
	}
}