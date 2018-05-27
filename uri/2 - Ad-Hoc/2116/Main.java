import java.util.*;

public class Main{

/* Function to find the cross over point (the point before
       which elements are smaller than or equal to x and after
       which greater than x)*/
    static int findCrossOver(int arr[], int low, int high, int x)
    {
        // Base cases
        if (arr[high] <= x) // x is greater than all
            return high;
        if (arr[low] > x)  // x is smaller than all
            return low;
 
        // Find the middle point
        int mid = (low + high)/2;  /* low + (high - low)/2 */
 
        /* If x is same as middle element, then return mid */
        if (arr[mid] <= x && arr[mid+1] > x)
            return mid;
 
        /* If x is greater than arr[mid], then either arr[mid + 1]
          is ceiling of x or ceiling lies in arr[mid+1...high] */
        if(arr[mid] < x)
            return findCrossOver(arr, mid+1, high, x);
 
        return findCrossOver(arr, low, mid - 1, x);
    }

  static int near(int [] arr, int n){
    int dant, dprox, near = arr[1];
    for(int i=1; i<arr.length; i++){
      if(arr[i]>n){
        dant = Math.abs(arr[i-1] - n);
        dprox = Math.abs(arr[i] - n);
        if( dant <= dprox) near = arr[i-1];
        else near = arr[i];
        break;

      }else{
        near = arr[i];
      }
    }
    return near;
  }
// //10 15
// 10 -> 11

// 15 -> (13,17)

// //7, 11, 13, 17
  public static void main(String args[]){

    int primes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    Scanner scanner = new Scanner(System.in);
    int N, M, nearN, nearM;
    N = scanner.nextInt();
    M = scanner.nextInt();
    nearN = near(primes, N);
    nearM = near(primes, M);
    System.out.printf("NN:%d NM:%d\n", nearN, nearM);
    System.out.println(nearN*nearM);

  }
}