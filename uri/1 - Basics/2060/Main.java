import java.util.*;

class Main{

	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
		int	a = 0, b = 0, c = 0, d = 0, e = 0;
		int n = scanner.nextInt();
		for (int i = 0; i < n; i++) {
			e = scanner.nextInt();
			if (e % 2 == 0)
				a++;
			if (e % 3 == 0)
				b++;
			if (e % 4 == 0)
				c++;
			if (e % 5 == 0)
				d++;

		}

		System.out.format("%d Multiplo(s) de 2\n", a);
		System.out.format("%d Multiplo(s) de 3\n", b);
		System.out.format("%d Multiplo(s) de 4\n", c);
		System.out.format("%d Multiplo(s) de 5\n", d);

	}
}