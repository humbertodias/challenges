import java.io.*;
import java.util.*;
import java.text.*;

public class Main {

	public static long daysDiff(Date from, Date to) {
	    return daysDiff(from.getTime(), to.getTime());
	}

	public static long daysDiff(long from, long to) {
	    return Math.abs(Math.round( (to - from) / 86400000D )); // 1000 * 60 * 60 * 24
	}
 
    public static void main(String[] args) throws Exception {

        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        String line;
        Date dt1, dt2;
	    SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
        int i=0;
        while(i++ <= N){
        	line = scanner.nextLine();
        	if(line == null || line.length() == 0) continue;
        	dt1 = format.parse(line.split(" ")[0]);
        	dt2 = format.parse(line.split(" ")[1]);
        	System.out.format("%d\n", daysDiff(dt1,dt2) );
    	}
 
    }
 
}
