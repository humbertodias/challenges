import java.util.*;

public class Main{

	static int replaceCount(String s, char c){
		return s.length() - s.replace(""+c, "").length();
	}

    public static void main(String args[]){
        Scanner scanner  = new Scanner(System.in);
        String vogais, frase;
        int sum=0;
        while(scanner.hasNext()){
        	vogais = scanner.nextLine();
        	frase = scanner.nextLine();
        	for(char c: vogais.toCharArray()){
        		sum += replaceCount(frase, c);
        	}
            System.out.println(sum);
            sum=0;
        }
    }
}