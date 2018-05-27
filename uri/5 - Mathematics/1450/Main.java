import java.util.*;

public class Main{

    static int max(int a,int b, int c){
        List<Integer> all = new ArrayList<>();
        all.add(a+b+c);
        all.add(a+b);
        all.add(a+c);
        all.add(b+c);
        all.add(c+b);

        Collections.sort(all, new Comparator<Integer>() {
        @Override
        public int compare(Integer a, Integer b)
        {
            return  a.compareTo(b);
        }
        });

        return all.get(all.size()-1);
    }
    public static void main(String [] args){

        Scanner scanner = new Scanner(System.in);
        int T,N;
        int X,Y,Z;
        T = scanner.nextInt();
        while(scanner.hasNext()){
            N = scanner.nextInt();
            int A,B,C,MAX=-1;
            for(int i=0; i< N; i++){
                X = scanner.nextInt();
                Y = scanner.nextInt();
                Z = scanner.nextInt();

                // A=X+Y+Z;
                // B=X+Y;
                // C=X+Z;
                int tMAX = max(X,Y,Z);
                if(tMAX > MAX) MAX = tMAX;
            }
            System.out.println(MAX);
        }
    }
}