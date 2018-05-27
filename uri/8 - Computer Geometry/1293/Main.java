import java.util.*;
class Main{
	static final double PI = Math.acos(-1);
	public static void main(String []args){
	    double AB,dist;
	    double x1,y1,x2,y2,CMD,ENF;
	    Scanner scanner = new Scanner(System.in);
	    while(scanner.hasNext()){
	    	x1 = scanner.nextDouble();
	    	y1 = scanner.nextDouble();
	    	x2 = scanner.nextDouble();
	    	y2 = scanner.nextDouble();
	    	CMD = scanner.nextDouble();
	    	ENF = scanner.nextDouble();

	        AB=Math.sqrt(Math.pow(x1-x2,2)+Math.pow(y1-y2,2));
	        dist=AB*(1/Math.tan(CMD*PI/180)+1/Math.tan(ENF*PI/180));
	        
	        System.out.printf("%.3f\n",dist);
	    }
	}

}