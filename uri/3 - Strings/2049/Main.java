import java.util.*;

class Main{
    public static void main(String []args){
        Scanner scanner = new Scanner(System.in);
        int h=1;
        String a, seq;
        while(scanner.hasNext()){
            a = scanner.nextLine();
            if("0".equals(a)) break;
            else if(h>1) System.out.println();
            seq = scanner.nextLine();
            System.out.format("Instancia %d\n", h++);
            System.out.format("%s\n", seq.indexOf(a)!=-1?"verdadeira":"falsa");
        }
    }
}