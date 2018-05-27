using System;

class URI{
	public static void Main(string [] args){
	    int a = Int32.Parse( System.Console.ReadLine().Trim() );
	    Console.Write( a/3600 +  ":" +  (a%3600)/60 +  ":" + a%60 + "\n");
	}
}