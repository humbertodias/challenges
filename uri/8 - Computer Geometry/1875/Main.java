import java.io.IOException;
import java.util.Scanner;
 

public class Main {

/*
Jogam três equipes ao mesmo tempo: Red, Green e Blue.

A partida tem um tempo de trinta minutos.
A equipe que fizer um gol no adversário do sentido anti-horário ao mesmo, é um gol normal.
A equipe que fizer um gol no adversário do sentido horário ao mesmo, vale o dobro.
Se as três equipes fizerem a mesma quantidade de gols, ocorre um trempate
Se as duas equipes que fizerem mais gols tiverem feito a mesma quantidade, ocorre um empate, e o jogo é decidido por pênaltis.
A equipe que fizer mais gols, vence.
*/    
 
    public static void main(String[] args) throws IOException {
 
        Scanner scanner = new Scanner(System.in);
        String M,S, line;


        int C = scanner.nextInt();
        for(int i=0, P; i< C; i++){

            P = scanner.nextInt();
            int R=0,G=0,B=0;
            for(int j=0; j< P; j++ ){
                M = scanner.next();
                S = scanner.next();
//                System.out.println("M:" + M + ",S:" + S);

                if("R".equals(M) && "G".equals(S))
                    R+=2;

                if("R".equals(M) && "B".equals(S))
                    R++;

                if("G".equals(M) && "B".equals(S))
                    G+=2;

                if("G".equals(M) && "R".equals(S))
                    G++;

                if("B".equals(M) && "R".equals(S))
                    B+=2;

                if("B".equals(M) && "G".equals(S))
                    B++;

            }

//          System.out.println("R:" + R + ",G:" + G + ",B:" + B);

            if( R==G && G==B && B==R)
                System.out.println("trempate");
            else if( (R>0&&R==G && R!=B) || (B>0&&B==R && B!=G) || (G>0&&G==B && G!=R) )
                System.out.println("empate");
            else {

                if(R > 0 && R >= G && R >= B)
                    System.out.println("red");
                else if(G > 0 && G >= R && G >= B)
                    System.out.println("green");
                else if(B > 0 && B >= R && B >= G)
                    System.out.println("blue");
            }

        }
    }
 
}
