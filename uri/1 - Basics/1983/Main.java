import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x, s = 0;
		float f = 0, m = 0;
		int n = in.nextInt();
		
		for (int i = 0; i < n; i++) {
			try{
				x = in.nextInt();
				f = in.nextFloat();
			}catch(NoSuchElementException e){ break; }
			if(m < f) {
				m = f;
				s = x;
			}
		}

		if(m >= 8.0) System.out.println(s);
		else System.out.println("Minimum note not reached");
	}
}