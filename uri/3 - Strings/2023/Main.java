import java.util.*;

class Main{

    public static void main(String [] args){
        List <String> children = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext()){
            children.add( scanner.nextLine() );
        }
        Collections.sort(children, String.CASE_INSENSITIVE_ORDER);
        System.out.println(children.get(children.size()-1));
    }
}