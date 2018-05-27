import java.util.*;
class Main{
    public static void main(String []args){
        Scanner scanner = new Scanner(System.in);
        int n, i;
        int x, y, aux;
        int soma;
        
        while(true){
            x = scanner.nextInt();
            y = scanner.nextInt();        

            if(x <= 0) break;
            if(y <= 0) break;
            
            if(x > y){
                 aux = x;
                 x = y;
                 y = aux;
            }
            soma = 0;
            for(i = x; i <= y; i++){
                System.out.printf("%d ",i);
            soma += i;
            }
            
            System.out.printf("Sum=%d\n", soma);
        }

    }

}