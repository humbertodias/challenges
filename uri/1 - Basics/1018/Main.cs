using System; 

class URI{
    static void Main(string [] args){
        int inteiro = Int32.Parse( System.Console.ReadLine().Trim() );
        Console.Write("{0}\n", inteiro);
        int[] banknotes = {100, 50, 20, 10, 5, 2, 1};
        int aux = inteiro;
        foreach(int div in banknotes){
            Console.Write("{0} nota(s) de R$ {1},00\n", aux/div, div );
            aux = aux % div;
        }
    }
}