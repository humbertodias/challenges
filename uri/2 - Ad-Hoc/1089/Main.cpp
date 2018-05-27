#include <cstdio>
#include <iostream>
using namespace std;

int i,n,pc;
bool sobe;
int v[10005];

int main(){

    while (scanf("%d",&n)){
        if (n==0) break;

        for (i=1; i<=n; i++)
            scanf("%d",&v[i]);
        v[0] = v[n];
        v[n+1] = v[1];

        pc = 0;
        sobe = v[1]>v[0];
        for (i=2; i<=n+1; i++){
            if (sobe && v[i]<v[i-1]){
                pc++;
                sobe = false;
            } else if (!sobe && v[i]>v[i-1]){
                pc++;
                sobe = true;
            }
        }
        printf("%d\n",pc);
    }

    return 0;

}
