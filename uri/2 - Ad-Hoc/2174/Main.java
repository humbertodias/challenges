import java.util.*;

public class Main{

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int N;
        String pokeName;
        Map<String,Integer> map = new HashMap<String,Integer>();
        int total = 151;
        while(scanner.hasNext()){
            N = scanner.nextInt();
            for(int i=0; i < N; i++){
                pokeName = scanner.next();

                if(!map.containsKey(pokeName))
                    map.put(pokeName, 1);
            }

            for (Map.Entry<String,Integer> entry : map.entrySet()) {
                total -= entry.getValue();
            }

            System.out.format("Falta(m) %d pomekon(s).\n", total);
        }
    }

}