using System;

class URI
{

	static void Main(string[] args)
	{

		string[] vet = Console.ReadLine().Split(' ');
		int a = int.Parse(vet[0]);
		int b = int.Parse(vet[1]);
		int c = int.Parse(vet[2]);

        int aux=0;

		if(a > b)
            aux = a;
        else
            aux = b;
        
        if(aux < c)
            aux = c;
        
        Console.WriteLine($"{aux} eh o maior");
	}

}
