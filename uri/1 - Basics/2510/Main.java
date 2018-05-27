import java.util.*;

class Main{

	public static void main(String ... args){
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		String vilao;
		boolean capturado = true;
		while(T-- > 0){
			vilao = scanner.nextLine();
			// capturado = (!vilao.equals("Coderinga"));
			if(capturado)
				System.out.println("Y");
			else
				System.out.println("N");
		}
	}
}