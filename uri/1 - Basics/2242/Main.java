import java.util.*;

class Main{
	static StringBuilder voyals(String word){
		StringBuilder sb = new StringBuilder();
		for(char c : word.toCharArray())
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
				sb.append(c);

		return sb;
	}
    public static void main(String [] args){
        String line = new Scanner(System.in).next();
        StringBuilder sbVoyals = voyals(line);
        String natural = sbVoyals.toString();
        String reverse = sbVoyals.reverse().toString();
        if(sbVoyals.length() > 0)
	        System.out.printf("%c\n", natural.equals(reverse) ? 'S' : 'N' );
	    else
	    	System.out.println("N");
    }


}