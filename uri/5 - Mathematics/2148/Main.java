import java.util.*;

public class Main{
static int s,d;
static long [][] memo = new long[100][100];

static long solve(int sum, int dados){
	if(dados==d)
		return sum == s ? 1 : 0;
	if(sum >= s)
		return 0L;
	if(memo[sum][dados] != -1)
		return memo[sum][dados];

	long ans = 0;
	for(int i=1; i <= 6; i++)
		ans += solve(sum+i, dados+1);

	return memo[sum][dados]=ans;
}
static void memset(long a[][], long value){

	for(int i=0; i < a.length; i++){
		for(int j=0; j < a[i].length; j++){
			a[i][j] = value;
		}
	}

}
public static void  main(String [] args){
	Scanner scanner = new Scanner(System.in);
	int tc = scanner.nextInt();
	while( (tc--) > 0 ){
		s = scanner.nextInt();
		d = scanner.nextInt();
		memset(memo, -1);
		System.out.printf("%.15f\n", solve(0,0) / Math.pow(6,d));
	}

}

}