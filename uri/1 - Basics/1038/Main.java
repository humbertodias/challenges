import java.util.*;
class Main{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        float valor = 0f;
        
        if(a == 1) valor = 4.00f*b;
        else if(a ==2) valor = 4.50f*b;
        else if(a ==3) valor = 5.00f*b;
        else if(a ==4) valor = 2.00f*b;
        else if(a ==5) valor = 1.50f*b;
        
        System.out.format("Total: R$ %.2f\n", valor);
    }
}