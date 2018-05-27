import java.util.*;

class Main{
	public static void main(String args[]){
	    int j = 7, i;
	    for(i = 1; i <= 9; i++){
	        System.out.printf("I=%d J=%d\n",i,j);
	        System.out.printf("I=%d J=%d\n",i,j-1);
	        System.out.printf("I=%d J=%d\n",i,j-2);
	        i++;
	        j+=2;
	    }
	}
}