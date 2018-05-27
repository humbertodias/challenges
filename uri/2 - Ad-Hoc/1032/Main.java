import java.util.*;

class Main{
  static int [] prime = new int[32650];

  static int flavious(int n) {
      int r = 0, i;
      for (i = 1; i <= n; i++){
        r = (r + prime[n-i]) % i;
      }
      return r;
  }

  static boolean isPrime(int n) { 
      int i;
      if(n == 2) return true;
      if(n%2 == 0) return false;
      for(i = 3; i*i<=n; i+=2) {
        if(n%i == 0) return false;
      }
      return true;
  }

  static void primeNumbers(){
       // memset(&prime, 0, sizeof(prime));
       int j;
       int a = 0;
       for(j = 2; j < 32650; j++){
         if(isPrime(j)){
            prime[a] = j;
            a++;
         }
       }
  }

  public static void main(String []args){
      int x;
      
      primeNumbers();
      Scanner scanner = new Scanner(System.in);
      while(true){
          x = scanner.nextInt();
          if(x == 0) break;
          System.out.printf("%d\n",flavious(x)+1);
      }
  }

}