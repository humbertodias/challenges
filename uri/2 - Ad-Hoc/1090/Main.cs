using System;

namespace acp
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string[] s = Console.ReadLine().Split(' ');
                if (Convert.ToInt32(s[0]) == 0 & Convert.ToInt32(s[1]) == 0 & Convert.ToInt32(s[2]) == 0)
                {
                    break;
                }
                if ((Convert.ToInt32(s[1]) - Convert.ToInt32(s[0])) == (Convert.ToInt32(s[2]) - Convert.ToInt32(s[1])))
                {
                    Console.WriteLine("AP  " + ((Convert.ToInt32(s[1]) - Convert.ToInt32(s[0])) + Convert.ToInt32(s[2])));
                }
                else
                { Console.WriteLine("GP  " +(((Convert.ToInt32(s[2]))*((Convert.ToInt32(s[1]) / Convert.ToInt32(s[0])) ))));
                }
            }
        }
    }
}
