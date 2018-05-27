#include <cstdio>

int main() {
    char rnaa[999], s[999];
    int i, t, sp;
    while(scanf("%s", rnaa) != EOF) {
        t = 0;
        sp = -1;
        for(i = 0; rnaa[i] != '\0'; i++) {
            if(sp == -1)
                s[++sp] = rnaa[i];
            else {
                if( (rnaa[i] == 'C' && s[sp] == 'F') ||
                    (rnaa[i] == 'F' && s[sp] == 'C') ||
                    (rnaa[i] == 'B' && s[sp] == 'S') ||
                    (rnaa[i] == 'S' && s[sp] == 'B')) {
                    t++;
                    sp--;
                }
                else {
                    s[++sp] = rnaa[i]; 
                }
            }
        }
        printf("%d\n", t);
    }
    return 0;
}