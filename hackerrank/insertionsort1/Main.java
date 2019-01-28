import java.util.*;

public class Main {
	public static void main(String ... args){
		try( Scanner scanner = new Scanner(System.in) ) {

			int n = scanner.nextInt();
			int arr [] = new int [n]; 
			for(int i=0; i < n; i++){
				arr[i] = scanner.nextInt();
			}

			insertionSort1(arr);
		}
	}

	static void insertionSort1(int[] ar) {
        int last = ar[ar.length-1];
        int i = ar.length-2;
        while (i + 1 > 0 && last <= ar[i]){
            ar[i+1] = ar[i--];
            printArray(ar);
        }
        ar[i+1] = last;
        printArray(ar);
	}

	static void printArray(int arr[]){
		for(int n : arr){
			System.out.printf("%d ",n);
		}
		System.out.println();
	}

}