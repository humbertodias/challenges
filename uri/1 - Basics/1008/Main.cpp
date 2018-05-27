#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     int NUMBER,HOURS; 
     double HOUR_VALUE, SALARY;
     cin >> NUMBER >> HOURS >> HOUR_VALUE;
     SALARY = HOURS * HOUR_VALUE;

     cout << "NUMBER = " <<  NUMBER << endl;
     cout << "SALARY = U$ " << fixed << setprecision(2) << SALARY << endl;
 
     return 0;
}
