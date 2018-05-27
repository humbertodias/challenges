import java.util.*;

class Main{
  public static void main(String []args){
      Scanner scanner = new Scanner(System.in);
      int x, y;
      int op;
      int inter = 0;
      int gremio = 0;
      int grenal = 0;
      int empate = 0;
      
      while(true){
        x = scanner.nextInt();
        y = scanner.nextInt();
        if(x > y) inter++;
        if(x < y) gremio++;
        if(x == y) empate++;
        grenal++;
        
        System.out.printf("Novo grenal (1-sim 2-nao)\n");
        op = scanner.nextInt();
        
        if(op == 2) break;
      }
      System.out.printf("%d grenais\n", grenal);
      System.out.printf("Inter:%d\n",inter);
      System.out.printf("Gremio:%d\n",gremio);
      System.out.printf("Empates:%d\n",empate);
      
      if(inter > gremio) System.out.printf("Inter venceu mais\n");
      if(inter < gremio) System.out.printf("Gremio venceu mais\n");
      if(inter == gremio) System.out.printf("Nao houve vencedor\n");
      
  }
}