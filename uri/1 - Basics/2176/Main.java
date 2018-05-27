import java.util.*;
class Main{
    public static void main(String []args)
    {
        char str[] = new char[150];
        int i, cnt=0;
        char str2 [] = new Scanner(System.in).next().toCharArray();

        for(i=0; i< str2.length; i++)
            str[i] = str2[i];

        for(i=0; str[i] != '\0'; i++)
            if(str[i]=='1')
                cnt++;

        if(cnt%2 == 0)
            str[i] = '0';
        else 
            str[i] = '1';

        str[i+1] = '\0';
        System.out.printf("%s\n", new String(str).trim() );
    }
}