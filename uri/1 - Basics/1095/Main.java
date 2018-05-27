import java.util.*;

class Main{

	public static void main(String args[]){
	    int i = 1, j;
	    for(j = 60; j >= 0; j--){
	        System.out.printf("I=%d J=%d\n", i, j);
	        i += 3;
	        j -= 4;
	    }
	}

}