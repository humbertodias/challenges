#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int m[1001][1001];

int main(){
  int x,y,p,q,X,Y,N,Z,W,soma;
  char op;

  for(;;){

    //scanf("%d %d %d",&x,&y,&p);
    cin >> x >> y >> p;

    if(x == 0 && y == 0 && p == 0)
      break;

    for (int i = 0; i <= x; ++i)
      for (int j = 0; j <= y; ++j)
        m[i][j] = 0;

    //scanf("%d",&q);
    cin >> q;

    while(q--){
      //scanf(" %c",&op);
      cin >> op;
      if(op == 'A'){
        //scanf("%d %d %d",&N,&X,&Y);
        cin >> N >> X >> Y;
        m[X][Y] += N;
      }
      else{
        //scanf("%d %d %d %d",&X,&Y,&Z,&W);
        cin >> X >> Y >> Z >> W;

        //colocar o menor no x e y
        if(Z < X){
          soma = Z;
          Z = X;
          X = soma;
        }
        if(W < Y){
          soma = W;
          W = Y;
          Y = soma;
        }

        soma = 0;
        for (int i = X; i <= Z; ++i)
          for (int j = Y; j <= W; ++j)
            soma += m[i][j];

        //printf("%d\n",soma*p);
        cout << soma*p << endl;
      }
    }
    //printf("\n");
    cout << endl;

  }
}