import java.util.*;

public class Main {
	public static void main(String ... args){
		try( Scanner scanner = new Scanner(System.in) ) {

			int n = scanner.nextInt();
			int arr [] = new int [n]; 
			for(int i=0; i < n; i++){
				arr[i] = scanner.nextInt();
			}

			int grades [] = gradingStudents(arr);
			printArray(grades);

		}
	}

	static void printArray(int []arr){
		for(int n: arr){
			System.out.println(n);
		}
	}

	static int[] gradingStudents(int[] grades) {
		int outGrades [] = new int[grades.length];
		for(int i=0; i< grades.length; i++){
			int grade = grades[i];
			int next5 = roundup5(grade);
			int diff = next5 - grade;
			//System.out.printf("%d - %d = %d\n", next5, grade, diff);
			if(diff < 3 && next5 >= 40){
				outGrades[i] = next5;
			} else {
				outGrades[i] = grade;
			}
		}
		return outGrades;
	}

	static int roundup5(int n) {
		return ((n - 1) / 5 + 1) * 5;
	}
}