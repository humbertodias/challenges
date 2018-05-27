import java.io.*;
import java.util.ArrayList;
public class Main {

    public static void main(String[] args) throws IOException{
      //   BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      // BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        ArrayList <Integer> list = new ArrayList();
        int n,q,i,opc,x,y;
        String[] aux;
        String w;
        boolean maior,menor;
        Scanner scanner = new Scanner(System.in);
        // while( (w = in.readLine()) != null){
        while( scanner.hasNext() ) {
          n = scanner.nextInt();
           // n = Integer.parseInt(w);
           // aux = in.readLine().split(" ");
           aux = scanner.next().split(" ");
           for(i = 0; i < n; i++){
                   list.add(Integer.parseInt(aux[i]));
           }
           q = Integer.parseInt(in.readLine());
           while(q > 0){
                    aux = in.readLine().split(" ");
                     opc = Integer.parseInt(aux[0]);
                     x = Integer.parseInt(aux[1]);
                     if(opc == 0){
                   y = Integer.parseInt(aux[2]);
                       list.set(x - 1, list.get(y - 1));
                     }
               if(opc == 1){
                  y = Integer.parseInt(aux[2]);
                  list.set(x - 1, y);
               }
                    if(opc == 2){
                  y = Integer.parseInt(aux[2]);
                  list.add(x - 1, list.get(y-1));
                    }
                    if(opc == 3){
                  list.remove(x - 1);
                    }
                    if(opc == 4){
                  y = Integer.parseInt(aux[2]);
                  maior = menor = false;
                   for(i = x - 1; i < y - 1; i++){
                           if(list.get(i) < list.get(i+1)){
                        menor = true;
                           }
                            if(list.get(i) > list.get(i+1)){
                        maior = true;
                            }
                   }   
                   if(menor == true && maior == false){
                       out.write("NON DECREASING\n");
                   }
                   else if(maior == true && menor == false){
                       out.write("NON INCREASING\n");
                   }
                   else if(maior == true && menor == true){
                       out.write("NONE\n");
                   }
                   else out.write("ALL EQUAL\n");

                   }
                  q--;
        }
        list.clear();
        }
        out.flush();
    }
}
