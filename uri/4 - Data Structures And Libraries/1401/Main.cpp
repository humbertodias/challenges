#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> split(const string &line);

int main() {
    int n;
    string line;
    vector <char> to_permute;

    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> line;
        to_permute = split(line);
    
        sort(to_permute.begin(), to_permute.end());
        do {
            cout << string(to_permute.begin(), to_permute.end()) << endl;    
        } while (next_permutation(to_permute.begin(), to_permute.end()));
        cout << endl;
    }

    return 0;    
}

vector<char> split(const string &line) {
    vector <char> my_vector;
    stringstream ss(line);
    char var;
    
    while (ss >> var)
        my_vector.push_back(var);
    
    return my_vector;
}