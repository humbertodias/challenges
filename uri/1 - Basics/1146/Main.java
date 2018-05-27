import java.util.*;
import java.io.*;
class Main{
    public static void main(String []args) throws Exception{
        
        Integer n,i;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while(true){
            n = Integer.parseInt(br.readLine());
            if(n == 0) {                 
                bw.flush();
                break;
            }
            else
            {
                for(i=1; i<n; i++)
                    bw.write( i.toString() + " " );
            }
            bw.write(n + "\n");
        }

    }
}