import java.util.*;

public class Main{

	public static void main(String []args){
		Scanner scanner = new Scanner(System.in);
		// row 1
		// A primeira linha consiste de dois inteiros N e M, que representam a quantidade de bairros e a quantidade de ruas, respectivamente. Os bairros são enumerados de 1 até N. (2 <= N <= 100, 1 <= M <= (N * (N - 1)) / 2)
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		// row 2
		// A segunda linha consiste de dois inteiros P e D, que representam o bairro de partida e o bairro de destino, respectivamente. (1 <= P, D <= N e P != D)
		int P = scanner.nextInt();
		int D = scanner.nextInt();
		// row 3
		// A terceira linha contém um inteiro B, o qual representa a quantidade de borracha inicial no solado de Fofão. (1 <= B <= 1000).
		int B = scanner.nextInt();
		// row M
		// As M linhas seguintes descrevem as ruas (e o muro presente em cada rua). Cada rua é descrita por quatro inteiros: Xi, Yi, Fi e Si, que representam, respectivamente, o primeiro bairro que é conectado à rua, o segundo bairro que é conectado à rua, a quantidade de felicidade que o muro presente na rua proporciona aos fãs quando um mortal é aplicado por Fofão e a quantidade de borracha do solado de Fofão que é gasta quando um mortal é aplicado no muro da rua. (1 <= Xi, Yi <= N, 1 <= Si <= 1000, 1 <= Fi <= 10^9 e Xi != Yi)
		int Xi, Yi, Fi, Si;
		int MAX = 100;
		int bairros [][] = new int[N][M]; 


		while(scanner.hasNext()){
			Xi = scanner.nextInt();
			Yi = scanner.nextInt();
			Fi = scanner.nextInt();
			Si = scanner.nextInt();

			bairros[Xi][Yi] = Fi;
		}
		for(int i=0; i< bairros.length; i++){

			for(int j=0; j< bairros[i].length; j++){
				if(bairros[i][j] != 0)
				System.out.format("[%d,%d]=%d\n", i,j, bairros[i][j] );
			}
		}


	}

}