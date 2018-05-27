#include <iostream>
#include <cstdlib>

using namespace std;

int ascending(void const *a, void const *b )
{
    return (*(int*)a - *(int*)b );
}

int achar(int ac[], int len, int comp)
{
    for(int k = 0; k < len; k++){
        if(ac[k] == comp){
             return k+1;
        }
    }
    return 0;
}

int main(){
    int n,f,q,j,l;
    n = 0;    
    for(;;){
            cin >> f >> q;
            if(f == 0 && q == 0) break;
            int vet[f+1];
            
            for(j = 0; j < f; j++){
                cin >> vet[j];
            }
            
            qsort(vet, f, sizeof(int), ascending);
            
            cout << "CASE# " << n+1 << ":\n";
            for(j = 0; j < q; j++){
                cin >> l;
                
                int m = achar(vet,f,l);
                
                if(m != 0) cout << l << " found at " << m << "\n";
                else cout << l << " not found\n";
            }
            n++;  
    }
    return 0;
}