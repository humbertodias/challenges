#include <stack>
#include <iostream>

using namespace std;

int main(){
    int n,i,j, flag, flag1,flag2;
    int num[1001];
      
    while(1){
             cin >> n;
             if(n == 0) break;
             while(1){
             j = 1;
             flag = 0;
             flag1 = 0;
             stack<int> pilha;
             for(i = 1; i <= n; i++){
                   cin >> num[i];
                   if(num[i] == 0){
                          flag = 1;
                          cout << "\n";
                          break;
                   }
             }
             i = 1;
             while(1){
                   if(i > n) break;
                   if(flag1 == 1) break;
                   if(flag == 1) break;
                   while(1){
                            if(!pilha.empty() && pilha.top() == num[i]){
                                pilha.pop();
                                break;
                            }else if(j <= n){
                                  pilha.push(j);
                                  j++;
                                  if(pilha.top() == num[i]){
                                            pilha.pop();
                                            break;
                                  }
                             }else{
                                   flag1 = 1;
                                   break;
                             }
                   }
                   i++;
                     
             }
             if(flag == 1) break;
             if(pilha.empty()) cout << "Yes\n";
             else  cout << "No\n";
             }
    }
    return 0;
} 