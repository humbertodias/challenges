import java.util.*;

class Main{

    public static void main(String args[]) {
        char[] word;
        Scanner scanner = new Scanner(System.in);
        int times = scanner.nextInt();
        for (int i = 0; i <= times; i++) {
            word = scanner.nextLine().toCharArray();
            int s = word.length;
            
            /// primeira volta: troca todo caractere por 3 a sua frente
            for (int x = 0; x < s; x++) {
                // if (isalpha(word[x])) {
                if( Character.isLetter(word[x]) ){
                    word[x] = (char)(word[x] + 3);
                }
            }
            
            /// segunda volta: inverte a string
            String rev = "";
            
            for (int x = s-1; x >= 0; x--) {
                rev = rev + word[x];
            }
            
            word = rev.toCharArray();
            
            /// terceira volta: deslocada qualquer caractere da metade em diante para esquerda
            int mid = s/2;
            
            for (int x = mid; x < s; x++) {
                word[x] = (char)(word[x] - 1);
            }
            
            /// mostra o valor final
            if(word.length > 0)
            System.out.println(word);
        }
    }

}