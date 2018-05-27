import java.util.*;
class Main{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
	    int win;
	    int p = scanner.nextInt();
	    int j1 = scanner.nextInt();
	    int j2 = scanner.nextInt();
	    int r = scanner.nextInt();
	    int a = scanner.nextInt();

	    int sum = j1 + j2;
	    if((sum%2==0 && p==1) || (sum%2==1 && p==0)) win = 1;
	    else win = 2;
	    if((r==1 && a==0) || (r==0 && a==1)) win = 1;
	    else if(r==1 && a==1) win=2;
	    System.out.format("Jogador %d ganha!\n", win);
	}
}