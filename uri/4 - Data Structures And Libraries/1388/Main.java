import java.io.*;
import java.util.*;
 
public class Main{

    static boolean swap(int i, int j, int[] arr) {
        boolean is_swapped = false;
        if(arr[i] < arr[j]) {
           int t  = arr[i];
           arr[i] = arr[j];
           arr[j] = t;
           is_swapped = true;
        }
        return is_swapped;
    }

    public static void main(String ... args) throws Exception
    {
        int elements, turns, i, j,k;
        int [] array;
        int [] turns_array;

        PrintWriter out = new PrintWriter(System.out, false);

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while((line = in.readLine()) != null)
        {
            elements = Integer.parseInt(line.split(" ")[0]);
            turns = Integer.parseInt(line.split(" ")[1]);

            if(elements == 0 && turns == 0) break;

            array = new int[elements];
            turns_array = new int[turns];
     
            for (i = 0; i < elements; i++)
            {
                array[i] = i + 1;
            }

            line = in.readLine();
            i = 0;
            for(String t : line.split(" ")){
                turns_array[i++] = Integer.parseInt(t);
            }

            for (i = turns; i > 0; --i)
            {
                for (j = 0; j < turns_array[i - 1]; ++j)
                {
                    k = i - 1 + j;
                    if (!swap(k, k+1, array))
                        break;
                }
            }
     
            for (i = 0; i < elements; i++)
            {
                out.print(array[i]);
                if (i < elements-1 )
                  out.print(" ");              
            }
            out.println();
            array = null;
            turns_array = null;
        }
        out.flush();
    }

}