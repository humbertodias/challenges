import java.util.*;
class Main{
    public static void main(String []args){
        int x, y, aux, i;
        int soma = 0;
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextInt();
        y = scanner.nextInt();
        
        if(x > y){
            aux = y;
            y = x;
            x = aux;
        }
        
        for(i = x; i <= y; i++){
            if(i%13 != 0)
              soma += i;
        }
        System.out.println(soma);

    }
}