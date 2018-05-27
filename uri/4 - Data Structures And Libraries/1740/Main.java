import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		List <Integer> list = new ArrayList();
		int n, q, i, opc, x, y;
		boolean	maior, menor;
		Scanner	scanner = new Scanner(System.in);
		while (scanner.hasNext()) {
			n = scanner.nextInt();
			for (i = 0; i < n; i++) {
				list.add(scanner.nextInt());
			}
			q =	scanner.nextInt();
			while (q > 0) {
				opc = scanner.nextInt();
				x = scanner.nextInt();

				if (opc == 0) {
					y = scanner.nextInt();
					list.set(x - 1, list.get(y - 1));
				}
				if (opc == 1) {
					y = scanner.nextInt();
					list.set(x - 1, y);
				}
				if (opc == 2) {
					y = scanner.nextInt();
					list.add(x - 1, list.get(y - 1));
				}
				if (opc == 3) {
					list.remove(x - 1);
				}
				if (opc == 4) {
					y = scanner.nextInt();
					maior = menor = false;
					for (i = x - 1; i < y - 1; i++) {
            if((i + 1) <=list.size()){
  						if (list.get(i) < list.get(i + 1)) {
  							menor = true;
  						}
  						if (list.get(i) > list.get(i + 1)) {
  							maior = true;
  						}
            }
					}
					if (menor == true && maior == false) {
						System.out.println("NON DECREASING");
					} else if (maior == true && menor == false) {
						System.out.println("NON INCREASING");
					} else if (maior == true && menor == true) {
						System.out.println("NONE");
					} else
						System.out.println("ALL EQUAL");

				}
				q--;
			}
			list.clear();
		}
	}
}
