#include <iostream>
#include <iomanip>      // std::setprecision
 
using namespace std;
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
    double PI = 3.14159;
    double R,A;
    cin >> R;
    A = PI * R * R;
     
    cout << "A=" <<  fixed << setprecision(4) << A << endl;
 
    return 0;
}