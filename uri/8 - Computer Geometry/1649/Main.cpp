#include <iostream>
using namespace std;

char A[200][200];
char CC[200][200];

int Y,X,R,C;

int apply(const int sx,const int sy){
  for (int x=0;x<C;x++)
    for (int y=0;y<R;y++){
      const int px=x+sx,py=y+sy;
      if(px>=X || py>=Y) return false;
      CC[px][py]=(CC[px][py]=='0'?'1':'0');
    }
  return 1;
}

int main(){
  while(1){
    cin>>Y>>X>>R>>C>>ws;
    if (X==0 && Y==0 && R==0 && C==0) break;
    for (int y=0;y<Y;y++)
      for (int x=0;x<X;x++){
        cin>>A[x][y]>>ws;
        CC[x][y]='0';
      }
    int c=0;
    for (int y=0;y<Y;y++)
      for (int x=0;x<X;x++)
        if (A[x][y]!=CC[x][y]){
          c++;
          if (!apply(x,y)){
            cout<<-1<<endl;
            goto done;
          }
        }
    cout<<c<<endl;
  done:;
  }
}