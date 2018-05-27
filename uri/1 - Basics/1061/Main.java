import java.util.*;

class Main{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        scanner.next();
        int d = scanner.nextInt();
        int h = scanner.nextInt(); scanner.next();
        int m = scanner.nextInt(); scanner.next();
        int s = scanner.nextInt(); 

        scanner.next();
        int df = scanner.nextInt();
        int hf = scanner.nextInt(); scanner.next();
        int mf = scanner.nextInt(); scanner.next();
        int sf = scanner.nextInt();
        
        long dur = (df*86400 + hf*3600 + mf*60 + sf) - (d*86400 + h*3600 + m*60 + s);
        System.out.printf( "%d dia(s)\n", dur/86400);
        System.out.printf( "%d hora(s)\n", (dur%86400)/3600 );
        System.out.printf( "%d minuto(s)\n", ((dur%86400)%3600)/60 );
        System.out.printf( "%d segundo(s)\n", ((dur%86400)%3600)%60  );
    }
}