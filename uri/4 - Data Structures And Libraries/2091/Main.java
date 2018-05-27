import java.util.*;

public class Main{

    public static void main(String [] args){
        Map<Long,Long> map = new HashMap<>();
        long N,K, alone = -1;
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext()){

            N = scanner.nextLong();

            if(N==0) break;

            for(long i=0; i<N; i++){
                K = scanner.nextLong();
                if(map.containsKey(K)){
                    map.put(K,map.get(K)+1);
                }else{
                    map.put(K,1L);
                }
            }


            for (Map.Entry<Long,Long> entry : map.entrySet())
            {
                alone = entry.getKey();
                if(entry.getValue() % 2 != 0){
                    break;
                }
            }
            map.clear();

            System.out.println(alone);
        }
    }
}