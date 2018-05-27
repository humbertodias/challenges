import java.util.*;

class Main{
  public static void main(String [] args){

      Scanner scanner = new Scanner(System.in);

      int a = scanner.nextInt();
      int b = scanner.nextInt();
      int c = scanner.nextInt();
      int d = scanner.nextInt();

      int inicio = a *60 + b;
      int dfinal = c * 60 + d;
      int duracao = 0;
      
      if(a <= c){
        duracao = dfinal - inicio;
        if(duracao == 0)
            System.out.printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",24,duracao%60);
        else
            System.out.printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",(duracao - duracao%60)/60,duracao%60);
      }else{
        duracao = (24*60 - inicio) + dfinal;
        System.out.printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",(duracao - duracao%60)/60,duracao%60);
      }
      
      
  }
}