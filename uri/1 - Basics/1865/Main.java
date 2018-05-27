import java.util.*;

class Main{
    public static void main(String []args){

        final String THOR = "Thor";
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int force_applied;
        String person;

        while(N-- > 0){
            person = scanner.next();
            force_applied = scanner.nextInt();
            System.out.println( (( person.equals(THOR) ) ? 'Y' : 'N') );

        }

    }
}