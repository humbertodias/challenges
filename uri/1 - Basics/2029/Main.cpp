#include <iostream>
using namespace std;
 
int main() {
  double v,d,alt,area;
 
  while(cin >> v >> d){
    area = 3.14 * (d/2.0) * (d/2.0);
    alt = v / area;
 
    printf("ALTURA = %.2f\nAREA = %.2f\n",alt,area);
  }
  return 0;
}