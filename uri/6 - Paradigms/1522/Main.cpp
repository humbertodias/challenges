#include <iostream>
#include <cstring>
using namespace std;

int pilha[101][3];
int pd[101][101][101];

bool func(int q[3]){

  if(q[0] == 0 && q[1] == 0 && q[2] == 0)
    return true;

  if(pd[q[0]][q[1]][q[2]] == -1){
    bool resp = false;

    for(int i = 1;i<=7;i++){
      bool flag = true;
      int sum = 0;
      int q2[3];
      
      for(int j = 0; j < 3; j++){
        q2[j]=q[j];
        if((i&(1<<j))!=0){
          if(q[j]==0){
            flag = false;
            break;
          }
          q2[j]--;
          sum+=pilha[q[j]][j];
        }
      }
      if(flag && sum%3 == 0){
        resp = (resp || func(q2));
        if(resp == true) break;
      }
    }
    pd[q[0]][q[1]][q[2]] = resp;

  }
  return (pd[q[0]][q[1]][q[2]]);
}

int main(){
  int n;

  while(cin >> n, n){
    memset(pd,-1,sizeof pd);
    for(int i = n;i>=1;i--)
      cin>>pilha[i][0]>>pilha[i][1]>>pilha[i][2];
    int q[3] = {n,n,n};
    if(func(q)){
      cout<<1<<endl;
    }else{
      cout<<0<<endl;
    }
  }
}