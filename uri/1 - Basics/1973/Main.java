import java.util.*;
import java.io.*;
class Main{
    public static void main(String []args) throws Exception 
    {  
        int N, i;  
        double sum_trak=0, sum_sheep=0;  
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        N = Integer.parseInt(br.readLine());
        double star[] = new double[N];
        double sheep[] = new double [N];  
        String dd[] = br.readLine().split(" ");
        for(i=0; i<N;i++)
        {  
            sheep[i] = Double.parseDouble(dd[i]);
            star[i]=0;  
        }  
        i=0;  
        while(true)  
        {  
            if(i==0 && sheep[i]%2==0)  
            {  
                star[i]=1;  
                if(sheep[i]>0)  
                    sheep[i]--;  
                break;  
            }  
            else if(i==N-1 && sheep[i]%2==1)  
            {  
                star[i]=1;  
                if(sheep[i]>0)  
                    sheep[i]--;  
                break;  
            }  
            else if(sheep[i]%2==1)  
            {  
                sheep[i]--;  
                star[i]=1;  
                i++;  
            }  
            else if(sheep[i]%2==0)  
            {  
                star[i]=1;  
                if(sheep[i]>0)  
                    sheep[i]--;  
                i--;  
            }  
      
      
        }  
        for(i=0; i<N; i++)  
        {  
            sum_sheep += sheep[i];  
            sum_trak += star[i];  
        }  
        out.printf("%.0f %.0f\n", sum_trak, sum_sheep);  
        out.flush();
    }  
}