import java.util.*;
class Main{
	public static void main(String []args) {
		double R, H, V, G;
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext() ){
			R = scanner.nextDouble();
			H = scanner.nextDouble();
			V = scanner.nextDouble();
			G = scanner.nextDouble();
			System.out.printf( "%s\n", V/G*Math.sqrt( V*V + 2.0*H*G ) - R > 0.01 ? "Y" : "N" );
		}
	}
}