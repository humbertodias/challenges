import java.util.*;


class Main{
    static int N=99999;
    static char str[] = new char [N];
    static char asci[] = new char[N];
    static char freq[] = new char[N];
    static int len, l;

    static void copyArray(String s){
        char arr[]=s.toCharArray();
        for(int i=0;i<arr.length;i++){
            str[i] = arr[i];
        }
    }
    public static void main(String []args)
    {
        String s;
    	int	i, j, f = 1, flag, count;
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            s = scanner.nextLine(); 
            len = s.length();
            copyArray(s);
    		if (f > 1)
    			System.out.printf("\n");
    		bubsort(str);
    		j = 0;
    		for (i = 0; i < len; i++) {
    			count = 0;
    			flag = 0;
    			asci[j] = str[i];
    			while (asci[j] == str[i] && i < len) {
    				count++;
    				freq[j] = (char)count;
    				i++;
    				flag = 1;
    			}
    			if (flag == 1)
    				i -= 1;
    			j++;
    		}
    		l = j;
    		mulbubsort();
    		for (i = 0; i < j; i++)
    			System.out.printf("%d %d\n", (int)asci[i], (int)freq[i]);
    		f++;
    	}

    }

    static void bubsort(char str[])
    {
    	int	t = len - 1, i, j, temp;
    	for (i = 0; i < t; i++) {
    		for (j = 0; j < t - i; j++) {
    			if (str[j] > str[j + 1]) {
    				temp = str[j];
    				str[j] = str[j + 1];
    				str[j + 1] = (char)temp;
    			}
    		}
    	}
    }

    static void mulbubsort()
    {
    	int	t = l - 1,	i, j;
    	char temp1, temp2;
    	for (i = 0; i < t; i++) {
    		for (j = 0; j < t - i; j++) {
    			if (freq[j] > freq[j + 1]) {
    				temp1 = freq[j];
    				temp2 = asci[j];
    				freq[j] = freq[j + 1];
    				asci[j] = asci[j + 1];
    				freq[j + 1] = temp1;
    				asci[j + 1] = temp2;
    			} else if (freq[j] == freq[j + 1]) {
    				if (asci[j] < asci[j + 1]) {
    					temp2 = asci[j];
    					asci[j] = asci[j + 1];
    					asci[j + 1] = temp2;
    				}
    			}
    		}
    	}
    }

}