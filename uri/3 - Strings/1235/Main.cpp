#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int casos; cin >> casos; cin.ignore(256, '\n');
    for (int i = 0; i < casos; i++) {
        string linha;
        getline(cin, linha);
        int meio = linha.size() / 2;
        reverse(linha.begin(), linha.begin() + meio);
        reverse(linha.begin() + meio, linha.end());
        cout  << linha << endl;
    }

    return 0;
}