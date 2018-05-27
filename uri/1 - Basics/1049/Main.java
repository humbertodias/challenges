import java.util.*;

class Main{
  public static void main(String [] args){

      Scanner scanner = new Scanner(System.in);
      String input  = scanner.next();
      String input2 = scanner.next();
      String input3 = scanner.next();
      
      if(input.equals("vertebrado")){
          if(input2.equals("ave")){
               if(input3.equals("carnivoro")){ 
                  System.out.printf("aguia\n");
               }
               if(input3.equals("onivoro")){ 
                  System.out.printf("pomba\n");
               }        
          }
          if(input2.equals("mamifero")){
               if(input3.equals("onivoro")){ 
                  System.out.printf("homem\n");
               }
               if(input3.equals("herbivoro")){ 
                  System.out.printf("vaca\n");
               }        
          }
      }
      
      if(input.equals("invertebrado")){
          if(input2.equals("inseto")){
             if(input3.equals("hematofago")){ 
                System.out.printf("pulga\n");
             }
             if(input3.equals("herbivoro")){ 
                System.out.printf("lagarta\n");
             }        
          }
          if(input2.equals("anelideo")){
             if(input3.equals("hematofago")){ 
                System.out.printf("sanguessuga\n");
             }
             if(input3.equals("onivoro")){ 
              System.out.printf("minhoca\n");
             }        
          }
      }

  }
}