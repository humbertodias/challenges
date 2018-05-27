import java.util.*;
class Main{

    public static void main(String []args)
    {
        char x[];
        int lnth;
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext()){
            x = scanner.next().toCharArray();
            lnth = x.length;
            if(lnth==3)
            {
                if(x[0]=='1') System.out.printf("C");
                else if(x[0]=='2') System.out.printf("CC");
                else if(x[0]=='3') System.out.printf("CCC");
                else if(x[0]=='4') System.out.printf("CD");
                else if(x[0]=='5') System.out.printf("D");
                else if(x[0]=='6') System.out.printf("DC");
                else if(x[0]=='7') System.out.printf("DCC");
                else if(x[0]=='8') System.out.printf("DCCC");
                else if(x[0]=='9') System.out.printf("CM");
                if(x[1]=='1') System.out.printf("X");
                else if(x[1]=='2') System.out.printf("XX");
                else if(x[1]=='3') System.out.printf("XXX");
                else if(x[1]=='4') System.out.printf("XL");
                else if(x[1]=='5') System.out.printf("L");
                else if(x[1]=='6') System.out.printf("LX");
                else if(x[1]=='7') System.out.printf("LXX");
                else if(x[1]=='8') System.out.printf("LXXX");
                else if(x[1]=='9') System.out.printf("XC");
                if(x[2]=='1') System.out.printf("I");
                else if(x[2]=='2') System.out.printf("II");
                else if(x[2]=='3') System.out.printf("III");
                else if(x[2]=='4') System.out.printf("IV");
                else if(x[2]=='5') System.out.printf("V");
                else if(x[2]=='6') System.out.printf("VI");
                else if(x[2]=='7') System.out.printf("VII");
                else if(x[2]=='8') System.out.printf("VIII");
                else if(x[2]=='9') System.out.printf("IX");
            }
            else if(lnth==2)
            {
                if(x[0]=='1') System.out.printf("X");
                else if(x[0]=='2') System.out.printf("XX");
                else if(x[0]=='3') System.out.printf("XXX");
                else if(x[0]=='4') System.out.printf("XL");
                else if(x[0]=='5') System.out.printf("L");
                else if(x[0]=='6') System.out.printf("LX");
                else if(x[0]=='7') System.out.printf("LXX");
                else if(x[0]=='8') System.out.printf("LXXX");
                else if(x[0]=='9') System.out.printf("XC");
                if(x[1]=='1') System.out.printf("I");
                else if(x[1]=='2') System.out.printf("II");
                else if(x[1]=='3') System.out.printf("III");
                else if(x[1]=='4') System.out.printf("IV");
                else if(x[1]=='5') System.out.printf("V");
                else if(x[1]=='6') System.out.printf("VI");
                else if(x[1]=='7') System.out.printf("VII");
                else if(x[1]=='8') System.out.printf("VIII");
                else if(x[1]=='9') System.out.printf("IX");
            }
            else if(lnth==1)
            {
                if(x[0]=='1') System.out.printf("I");
                else if(x[0]=='2') System.out.printf("II");
                else if(x[0]=='3') System.out.printf("III");
                else if(x[0]=='4') System.out.printf("IV");
                else if(x[0]=='5') System.out.printf("V");
                else if(x[0]=='6') System.out.printf("VI");
                else if(x[0]=='7') System.out.printf("VII");
                else if(x[0]=='8') System.out.printf("VIII");
                else if(x[0]=='9') System.out.printf("IX");
            }
            System.out.printf("\n");
        }

    }

}