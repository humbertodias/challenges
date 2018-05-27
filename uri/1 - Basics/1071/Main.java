import java.util.*;
class Main{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int aux;
        if(x > y){
         aux = x;
         x = y;
         y = aux;
        }
        int soma = 0;
        for(int i = x+1; i < y; i++){
            if(i%2 != 0){
               soma += i;
            }
        }
        System.out.printf("%d\n", soma);
    }
}