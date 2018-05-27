import java.util.*;

public class Main{

    public static void main(String args[]){
        Scanner scanner  = new Scanner(System.in);

        List<String> books = new ArrayList<>();
        int N;
        while(scanner.hasNext()){
            N = scanner.nextInt();
            
            for(int i=0; i<N;i++){
                books.add(scanner.next());
            }

            Collections.sort(books);
            for(String book: books)
            System.out.println(book);

            books.clear();

        }
    }
}