#include <iostream>     /// cin/cout/cin.get
#include <string>       /// string/size

using namespace std;

int main() {
    int times;
    string word;
    
    cin >> times;
    /// limpa o buffer da linha nova
    cin.get();
    
    for (int i = 1; i <= times; i++) {
        getline(cin, word);
        
        int s = word.size();
        
        /// primeira volta: troca todo caractere por 3 a sua frente
        for (int x = 0; x < s; x++) {
            if (isalpha(word[x])) {
                word[x] = (word[x] + 3);
            }
        }
        
        /// segunda volta: inverte a string
        string rev = "";
        
        for (int x = s-1; x >= 0; x--) {
            rev = rev + word[x];
        }
        
        word = rev;
        
        /// terceira volta: deslocada qualquer caractere da metade em diante para esquerda
        int mid = s/2;
        
        for (int x = mid; x < s; x++) {
            word[x] = (word[x] - 1);
        }
        
        /// mostra o valor final
        cout << word << endl;
    }
}