#include <cstdio>
#include <cstring>

#define MAX 80

int perm[54];
char seq[MAX + 1];

typedef void (*perm_fn)();

void rot4(int a, int b, int c, int d) {
    int t = perm[d];
    perm[d] = perm[c];
    perm[c] = perm[b];
    perm[b] = perm[a];
    perm[a] = t;
}

void turn_L() {
    rot4(0, 9, 18, 27);
    rot4(3, 12, 21, 30);
    rot4(6, 15, 24, 33);

    rot4(36, 38, 44, 42);
    rot4(37, 41, 43, 39);
}

void turn_R() {
    rot4(29, 20, 11, 2);
    rot4(32, 23, 14, 5);
    rot4(35, 26, 17, 8);

    rot4(45, 47, 53, 51);
    rot4(46, 50, 52, 48);
}

void turn_U() {
    rot4(9, 36, 35, 45);
    rot4(10, 37, 34, 46);
    rot4(11, 38, 33, 47);

    rot4(0, 2, 8, 6);
    rot4(1, 5, 7, 3);
}

void turn_D() {
    rot4(15, 51, 29, 42);
    rot4(16, 52, 28, 43);
    rot4(17, 53, 27, 44);

    rot4(18, 20, 26, 24);
    rot4(19, 23, 25, 21);
}

void turn_F() {
    rot4(6, 45, 20, 44);
    rot4(7, 48, 19, 41);
    rot4(8, 51, 18, 38);

    rot4(9, 11, 17, 15);
    rot4(10, 14, 16, 12);
}

void turn_B() {
    rot4(0, 42, 26, 47);
    rot4(1, 39, 25, 50);
    rot4(2, 36, 24, 53);

    rot4(27, 29, 35, 33);
    rot4(28, 32, 34, 30);
}

void init() {
    int i;
    for (i = 0; i < 54; i++) {
        perm[i] = i;
    }
}

void find_perm() {
    perm_fn fn;
    int i;
    for (i = 0; i < strlen(seq); i++) {
        switch (seq[i] & ~0x20) {
            case 'L': fn = turn_L; break;
            case 'R': fn = turn_R; break;
            case 'U': fn = turn_U; break;
            case 'D': fn = turn_D; break;
            case 'F': fn = turn_F; break;
            case 'B': fn = turn_B; break;
        }
        fn();
        if ((seq[i]&0x20)!=0) { //lower case
          fn();
          fn();
        }
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }

void solve() {
    int order = 1, cycle;
    int i, j;
    for (i = 0; i < 54; i++) {
        j = i;
        cycle = 0;
        do {
            j = perm[j];
            cycle++;
        } while (j != i);
        order = lcm(order, cycle);
    }
    printf("%d\n", order);
}

int main() {
    while (scanf(" %s", seq) != EOF) {
        init();
        find_perm();
        solve();
    }
    return 0;
}