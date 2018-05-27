import java.util.*;
class Main{
	public static void main(String [] args)
	{
	    double a,b,c=1,d=3,e,f;
	    int x;
	    for(a=0; a<=1.9; a=a+.2)
	    {
	        for(b=1.0; b<=3.0; b++)
	        {
	            e=b+a;
	            if(a==0.0||a==1.0) System.out.printf("I=%.0f J=%.0f",a,e);
	            else if(e==3.0||e==4.0||e==5.0) System.out.printf("I=%.0f J=%.0f",a,e);
	            else System.out.printf("I=%.1f J=%.1f",a,e);
	            System.out.printf("\n");
	        }
	    }
	    for(x=3; x<=5; x++) System.out.printf("I=2 J=%d\n",x);
	}
}