import java.util.*;

class Main{

	public static void main(String []argv)
	{
		int n, x, max, i;
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext())
		{
			n = scanner.nextInt();
			max = 0;

			for( i = 0; i < n; i++)
			{
				x = scanner.nextInt();
				if(max < x)
					max = x;
			}

			if(max < 10) System.out.printf("1\n");
			else if(max >= 10 && max < 20) System.out.printf("2\n");
			else System.out.printf("3\n");
		}

	}

}