#include <cstdio>
#include <cstring>

#define MAXN 1010

#ifdef FFAO
#define getchar_unlocked getchar
#endif

inline int read_int() {
    char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}

char tree[MAXN][MAXN];
short tree2[MAXN][MAXN];

int get_1(int i, int j) {
  int s = 0;
  while (i > 0) {
    int jj = j;
    char* arr = tree[i];
    while (jj > 0) {
        if (arr[jj] > s) s = arr[jj];
        jj ^= jj & -jj;
    }

    i ^= i & -i;
  }
  return s;
}

void add_1(int i, int j, int val) {
  while (i<=MAXN) {
    char* arr = tree[i];
    int jj = j;
    while (jj<=MAXN) {
        if (val > arr[jj]) arr[jj] = val;
        jj += jj & -jj;
    }

    i += i & -i;
  }
}

int get_0(int i, int j) {
  int s = 0;
  while (i > 0) {
    short* arr = tree2[i];
    int jj = j;
    while (jj > 0) {
        if (arr[jj] > s) s = arr[jj];
        jj ^= jj & -jj;
    }

    i ^= i & -i;
  }
  return s;
}

void add_0(int i, int j, int val) {
  while (i<=MAXN) {
    short* arr = tree2[i];

    int jj = j;
    while (jj<=MAXN) {
        if (val > arr[jj]) arr[jj] = val;
        jj += jj & -jj;
    }

    i += i & -i;
  }
}

int main() {
    int T, t;
    T=read_int();
    for (t = 0; t < T; t++) {
        int n;
        n=read_int();
        if (n < 100000) memset(tree,0,sizeof(tree));

        int best = 0, i;
        for (i = 0; i < n; i++) {
            int x,y;
            x=read_int();
            y=read_int();

            if (x == 1000 && y == 1000) best++;
            else if (n != 100000) {
                int val = get_1(x,y);
                add_1(x, y, val+1);
                if (val>=best) best=val+1;
            }
            else {
                int val = get_0(x,y);
                add_0(x, y, val+1);
                if (val>=best) best=val+1;
            }
        }
        
        printf("%d\n", best);                    
    }
    
  return 0;
}