import java.util.*;
class Main{
    
    public static void main(String []args){
        int n, i, j, k, zero, cont;
        long num;
        char number[] = new char[101];
        Scanner scanner = new Scanner(System.in);
        // while(cin >> n){
        while(scanner.hasNext()){
            n = scanner.nextInt();
            number = scanner.nextLine().toCharArray();
            // cin >> number;
            
            if(n == 0 && number[0] == '0') break;
            
            char changed[] = new char[101];
            i = 0;
            j = 0;
            zero = 0;
            num = 0;
            cont = 0;
            while(true){
                if(number[i] == '\0'){
                    break;
                }
                else if(number[i] == n+48){
                    i++;
                }
                else{
                    changed[j] = number[i];
                    if(j == zero) cont++;
                    if(number[i] == '0') zero++;
                    i++;
                    j++;
                }
            }
            changed[j] = '\0';
            
            // stringstream f(changed);
            // f >> num;
            // StringBuilder f = new StringBuilder(changed);
            num = Integer.parseInt(new String(changed));
            
            if(j == 0){ System.out.printf("0\n"); }
            else if(j == zero){ System.out.printf("%d\n",num); }
            else if(cont > 0){
                for(k = cont-1; changed[k] != '\0'; k++){
                    //cout << changed[k]-48;
                    System.out.printf("%c", changed[k]-48);
                }
                System.out.printf("\n");
            }
            else 
                // cout << changed << "\n";
                System.out.printf("%s\n", changed.toString());
        }
        
    }

}