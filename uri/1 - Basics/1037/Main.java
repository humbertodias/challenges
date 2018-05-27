import java.util.*;

class Main{
    public static void main(String args[]){
        
        float f = new Scanner(System.in).nextFloat();
        if(f < 0.0000)
         System.out.format("Fora de intervalo\n");
        else if(f >= 0.0000 && f <= 25.0000)
         System.out.format("Intervalo [0,25]\n");
        else if(f > 25.0000 && f <=50.0000)
         System.out.format("Intervalo (25,50]\n");
        else if(f > 50.0000 && f <=75.0000)
         System.out.format("Intervalo (50,75]\n");
        else if(f > 75.0000 && f <=100.0000)
         System.out.format("Intervalo (75,100]\n");
        else if(f > 100.0000)
         System.out.format("Fora de intervalo\n");
    }
}