import java.util.*;
import java.text.*;

class Main{

    public static void main(String [] args) throws Exception{
        Scanner scanner = new Scanner(System.in);
        int m, d;
        while(scanner.hasNext()){
            m = scanner.nextInt();
            d = scanner.nextInt();

         if(m==12){
            if(d<24)System.out.printf("Faltam %d dias!\n", 25-d);
            else{
               if(d==24)System.out.printf("E vespera de natal!\n");
               else{
                  if(d>25)System.out.printf("Ja passou!\n");
                  else System.out.printf("E natal!\n");
               }
            }
         }
         if(m==11)System.out.printf("Faltam %d dias para o natal!\n", 25+30-d);   
         if(m==10)System.out.printf("Faltam %d dias para o natal!\n", 31+25+30-d);
         if(m==9)System.out.printf("Faltam %d dias para o natal!\n", 30+31+25+30-d);
         if(m==8)System.out.printf("Faltam %d dias para o natal!\n", 31+30+31+25+30-d);
         if(m==7)System.out.printf("Faltam %d dias para o natal!\n", 31+31+30+31+25+30-d);
         if(m==6)System.out.printf("Faltam %d dias para o natal!\n", 30+31+31+30+31+25+30-d);
         if(m==5)System.out.printf("Faltam %d dias para o natal!\n", 31+30+31+31+30+31+25+30-d);
         if(m==4)System.out.printf("Faltam %d dias para o natal!\n", 30+31+30+31+31+30+31+25+30-d);
         if(m==3)System.out.printf("Faltam %d dias para o natal!\n", 31+30+31+30+31+31+30+31+25+30-d);
         if(m==2)System.out.printf("Faltam %d dias para o natal!\n", 29+31+30+31+30+31+31+30+31+25+30-d);
         if(m==1)System.out.printf("Faltam %d dias para o natal!\n", 31+29+31+30+31+30+31+31+30+31+25+30-d);
        }
    }
}