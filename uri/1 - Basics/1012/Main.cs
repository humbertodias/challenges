using System;

class URI
{

	static void Main(string[] args)
	{

		string[] vet = Console.ReadLine().Split(' ');
		float a = float.Parse(vet[0]);
		float b = float.Parse(vet[1]);
		float c = float.Parse(vet[2]);

		const double pi = 3.14159;

		Console.WriteLine($"TRIANGULO: {((a * c) / 2.0):F3}");
		Console.WriteLine($"CIRCULO: {((pi * c * c)):F3}");
		Console.WriteLine($"TRAPEZIO: {(((a + b) * c) / 2.0):F3}");
		Console.WriteLine($"QUADRADO: {(b * b):F3}");
		Console.WriteLine($"RETANGULO: {(a * b):F3}");
	}

}
