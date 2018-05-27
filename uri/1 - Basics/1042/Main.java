import java.util.*;

class Main{

  public static void main(String [] args){
    Scanner scanner = new Scanner(System.in);

    int a = scanner.nextInt();
    int b = scanner.nextInt();
    int c = scanner.nextInt();

    int v[] = new int[3];

    v[0] = a;
    v[1] = b;
    v[2] = c;
    
    int aux;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
          if(v[i] < v[j]){
              aux  = v[j];
              v[j] = v[i];
              v[i] = aux;
          }
      }
    }
    
    System.out.printf( "%d\n%d\n%d\n\n", v[0] , v[1], v[2] );
    System.out.printf( "%d\n%d\n%d\n", a , b , c );

  }

}