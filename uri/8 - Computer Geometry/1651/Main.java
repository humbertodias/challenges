import java.util.*;

class Main{

  static double MAX(double a,double b) { return a>b?a:b; }
  static double MIN(double a,double b) { return a<b?a:b; }
  static final double PI = 3.14159265358979323846;

  public static void main(String []args){
    int a,b;
    double r1,r2,V1,V2,h1,h2;
    Scanner scanner = new Scanner(System.in);
    while(true){
      a = scanner.nextInt();
      b = scanner.nextInt();
      if(a == 0 && b == 0) break;
      //Fall 1: 
      r1=a/(2.*PI);
      r1=MIN(r1,a/2.) ;
      h1=(double)b -2*r1;
      V1=PI*r1*r1*h1;
      //Fall 2:
      r2=((double)b)/(2*PI+2);
      r2=MIN(a/2.,r2);
      h2=a;
      V2=PI*r2*r2*h2;
      System.out.printf("%.3f\n",MAX(V1,V2));
    }
  }

}