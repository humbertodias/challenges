#include <iostream>
#include <queue>
using namespace std;
 
int main() {
    queue<int> Fila;
    vector<int> Original;
    int i,index,goes,j,tmp,T,N,Q,op;
    cin >> T;
    for(i=0;i<T;++i){
        while(!Fila.empty()) Fila.pop();
        Original.clear();
        cin >> N >> Q;
        for(j=0;j<N;++j){
            cin >> tmp;
            Original.push_back(tmp);
            Fila.push(tmp);
        }
        op=1;
        while(Fila.size()!=1){
            if(op){
                index=Fila.front();
                Fila.pop();
                goes=Fila.front();
                Fila.pop();
                Fila.push(index+goes);
                op=0;
            }else{
                index=Fila.front();
                Fila.pop();
                goes=Fila.front();
                Fila.pop();
                Fila.push(index-goes);
                op=1;
            }
        }
        //Caso de teste par -> Primeiro jogador Rusa (0)
        //Caso de teste ímpar -> Primeiro jogador Sanches (1)
        //Resultado ímpar -> Primeiro jogador vence (1)
        //Resultado par -> Segundo jogador vence (0)
        if(i%2){
            if(Fila.front()%2){
                cout << Fila.front() << " Sanches" << endl;
            }else{
                cout << Fila.front() << " Rusa" << endl;
            }
        }else{
            if(Fila.front()%2){
                cout << Fila.front() << " Rusa" << endl;
            }else{
                cout << Fila.front() << " Sanches" << endl;
            }
        }
        for(j=0;j<Q;++j){
            cin >> index >> goes;
            Original[index]=goes;
            //while()
        }
    }
    return 0;
}
