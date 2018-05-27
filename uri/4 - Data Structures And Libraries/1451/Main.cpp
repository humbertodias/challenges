#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

int main() {
    char c;
    list <char> line;
    list <char>::iterator it;
    bool home = false;

    while (scanf("%c", &c) != EOF) {
        if (c == '[') {
            home = true;
            it = line.begin();
            continue;
        } else if (c == ']') {
            home = false;
            it = line.end();
            continue;
        } else if (c == '\n') {
            for (it = line.begin(); it != line.end(); it++) {
                printf("%c", *it);    
            }
            if (line.size() > 0)
                printf("\n");

            line.clear();
            home = false;
            continue;
        }

        if (home)
            line.insert(it, c);
        else
            line.push_back(c);    
    }
    
    return 0;    
}