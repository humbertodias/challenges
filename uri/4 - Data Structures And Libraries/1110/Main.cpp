#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n, i;
    
    while(1){
             cin >> n;
             if(n == 0) break;
             deque<int> cartas;
             for(i = 1; i <= n; i++){
               cartas.push_back(i);
             }
             
             cout << "Discarded cards: ";
             while(cartas.size() > 1){
                  if(cartas.size() != 2) cout << cartas.front() << ", ";
                  else cout << cartas.front() << "\n";
                  cartas.pop_front();
                  cartas.push_back(cartas.front());
                  cartas.pop_front();
             }
             cout << "Remaining card: " << cartas.front() << "\n";
    }
    return 0;
}