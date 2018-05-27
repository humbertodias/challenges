import java.util.*;
class Main{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
	    int s = scanner.nextInt();
	    int t = scanner.nextInt();
	    int f = scanner.nextInt();
	    int ans = s+t+f;
	    if(ans < 0) ans = 24 + ans;
	    System.out.format("%d\n",ans%24);
	}
}