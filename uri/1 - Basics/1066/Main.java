import java.util.*;
class Main{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int par = 0;
        int impar = 0;
        int pos = 0;
        int neg = 0;
        int a = scanner.nextInt();
        if(a%2 == 0){par++;}else{impar++;}
        if(a > 0){pos++;}else if(a < 0){neg++;}
        int b = scanner.nextInt();
        if(b%2 == 0){par++;}else{impar++;}
        if(b > 0){pos++;}else if(b < 0){neg++;}
        int c = scanner.nextInt();
        if(c%2 == 0){par++;}else{impar++;}
        if(c > 0){pos++;}else if(c < 0){neg++;}
        int d = scanner.nextInt();
        if(d%2 == 0){par++;}else{impar++;}
        if(d > 0){pos++;}else if(d < 0){neg++;}
        int e = scanner.nextInt();
        if(e%2 == 0){par++;}else{impar++;}
        if(e > 0){pos++;}else if(e < 0){neg++;}
        
        System.out.printf("%d valor(es) par(es)\n", par);
        System.out.printf("%d valor(es) impar(es)\n", impar);
        System.out.printf("%d valor(es) positivo(s)\n", pos);
        System.out.printf("%d valor(es) negativo(s)\n", neg);

    }
}