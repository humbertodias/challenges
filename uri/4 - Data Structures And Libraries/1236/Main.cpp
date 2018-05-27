#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_sames(const string &line, int i, char c);
void substitution(int aux, char c);
vector <char> split(const string &line);

vector <char> compacted;

int main() {
    int nTests, repeat, aux;
    string line;

    cin >> nTests;
    while (getchar() != '\n');
    for (int nt = 0 ; nt < nTests ; nt++) {
        getline(cin, line);
        compacted.clear();

        for (int i = 0 ; i < line.size() ; i++) {
            if (line[i] == '0' or line[i] == ' ') {
                repeat = count_sames(line, i, line[i]);
                if (repeat <= 2) {
                    compacted.push_back(line[i]);
                } 
                else {
                    substitution(repeat, line[i]);
                    i += repeat - 1;
                }
            } 
            else {
                compacted.push_back(line[i]);     
            }
        }

        cout << string(compacted.begin(), compacted.end()) << endl;
    }

    return 0;    
}

int count_sames(const string &line, int i, char c) {
    int count = 1;
    int len = line.size();

    while (true) {
        if (i + 1 < len and line[i + 1] == c) {
            count++;
            i++;
        }
        else {
            break;    
        }
    }

    return count;
}

void substitution(int aux, char c) {
    while (aux > 0) {
        if (c == '0')
            compacted.push_back('#');
        else
            compacted.push_back('$');
                        
        if (aux >= 255)
            compacted.push_back((char) 255);
        else
            compacted.push_back((char) (aux % 255));
        
        aux -= 255;
    }
}

vector<char> split(const string &line) {
    vector <char> my_vector;
    stringstream ss(line);
    char var;
    
    while (ss >> var)
        my_vector.push_back(var);
    
    return my_vector;
}