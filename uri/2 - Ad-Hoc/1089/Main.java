import java.util.*;
class Main{
  public static void main(String []args){
      
      int n,i,v[] = new int[3];
      int resultado,p0,p1;
      Scanner scanner = new Scanner(System.in);
      while(scanner.hasNext()){
         n = scanner.nextInt();
         if(n == 0) break;
         resultado = 0;
         v[0] = scanner.nextInt();
         v[1] = scanner.nextInt();
         if(n == 2){
              if(v[0] != v[1]) resultado = 2;
         }
         else{
          p0=v[0];
          p1=v[1];
          
          for(i = 2; i < n; i++){
            v[2] = scanner.nextInt();
            if(((v[1]>v[0]) && (v[1]>v[2])) || ((v[1]<v[0]) && (v[1]<v[2]))) ++resultado;
            v[0]=v[1];
            v[1]=v[2];
          }

          if ((p0>p1 && p0>v[2]) || (p0<p1 && p0<v[2])) ++resultado;

          if ((v[2]>v[0] && v[2]>p0) || (v[2]<v[0] && v[2]<p0)) ++resultado;
         }
         System.out.printf("%d\n", resultado);
      }
  }
}