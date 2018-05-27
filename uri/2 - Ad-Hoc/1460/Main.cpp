#include <cstdio>
#include <algorithm>

using namespace std;

int h[500][500];
int a, b;
int M,N;

inline int get(int* pos) {
    return h[pos[0]][pos[1]];
}

inline void walk_left(int* pos) {
    while (pos[1] != 0 && h[pos[0]][pos[1]-1] >= a) pos[1]--;
}

inline void walk_down(int* pos) {
    while (pos[0] != M-1 && h[pos[0]+1][pos[1]] <= b) pos[0]++;
}

int walk_h(int* pos) {
    do {
        if (pos[0] == M-1) return 1;
        pos[0]++;
        walk_left(pos);
    } while (get(pos) > b);
    
    return 0;
}

int walk_v(int* pos) {
    do {
        if (pos[1] == 0) return 1;
        pos[1]--;
        walk_down(pos);
    } while (get(pos) < a);
       
    return 0;
}

void print(int* pos) {
    printf("LOC (%d, %d)\n", pos[0], pos[1]);
}

int main() {   
    while (scanf("%d %d", &M, &N) && M) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &h[i][j]);
            }
        }
        
        int Q;
        scanf("%d", &Q);
        
        for (int q = 0; q < Q; q++) {
            scanf("%d %d", &a, &b);
            
            int start[2] = {0, N-1};
            int maior = 0;
            int imp = 0;
            
            while (get(start) < a || get(start) > b) {
                while (start[1] > 0 && get(start) > b) start[1]--;
                while (start[0] < M-1 && get(start) < a) start[0]++;
            
                if ((get(start) > b && start[1] == 0) || (get(start) < a && start[0] == M-1)) {
                    imp = 1;
                    break;
                } 
            }
            if (imp) {
                printf("0\n"); continue;
            }
            
            int ho[2];
            int v[2];
            
            for (int i = 0; i < 2; i++) ho[i] = v[i] = start[i];
            
            walk_left(ho);
            walk_down(v);
            
            maior = min(v[0] - ho[0] + 1, v[1] - ho[1] + 1); 
            
            while (1) {
                if (v[0] - ho[0] > v[1] - ho[1]) {
                    if (walk_h(ho)) break;
                }
                else {
                    if (walk_v(v)) break;
                }
                
                maior = max(maior, min(v[0] - ho[0] + 1, v[1] - ho[1] + 1));
            }
            
            printf("%d\n", maior);
        }
        printf("-\n");
    }
}