import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);

        int g, i, j, angulo, test;
        while(true){
            
                if (!scanner.hasNext())
                    break;
                g = scanner.nextInt();

                j = 0;
                test = 0;
                for(i = 0; i < 60; i++){
                      if(i%5 == 0) j++;
                      angulo = i*6 - j*6;
                      if(g == angulo || g == -angulo){
                           test = 1;
                           break;
                      }
                }
                if(test == 1) System.out.format("Y\n");
                else System.out.format("N\n");
        }

    }
 
}
