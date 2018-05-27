import java.util.*;
class Main{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int n;
        int aux = 0;
        int pos = 0;
        for(int i = 0; i < 100 && scanner.hasNextInt(); i++){
            n = scanner.nextInt();
            if(n > aux){
             aux = n;
             pos = i;
            }
        }
        System.out.printf("%d\n%d\n", aux, pos+1);        
    }
}