import java.util.*;

class Main{

    public static void main(String [] args) throws Exception{
        Scanner scanner = new Scanner(System.in);
        int N, M, net, i; boolean cndtn;
        int bill[] = {7, 12, 22, 52, 102, 15, 25, 55, 105, 30, 60, 110, 70, 120, 150};

        while(scanner.hasNext()){
            N = scanner.nextInt();
            M = scanner.nextInt();

            if(N==0 && M==0) break;
            net = M - N;
            for(i=0, cndtn = false; i<15; i++)
            {
                if(bill[i] == net)
                {
                    cndtn = true;
                    break;
                }
            }
             if(cndtn)System.out.println("possible");
             else System.out.println("impossible");
        }
    }
}
