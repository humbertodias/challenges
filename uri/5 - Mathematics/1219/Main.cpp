#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#define PI 3.1415926535897
int a,b,c;
double r,p;
double S,V,R; //sunflowers, violets, roses

void sunflowers(){
    r = a*b*c/(V*4.0);
    S = PI*r*r;
}

void roses(){
    r = (V*2.0)/(a+b+c);
    R = PI*r*r;
}

void violets(){
    p = (a+b+c)/2.0;
    V = sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
    while(cin >> a >> b >> c){
        violets();
        sunflowers();
        roses();
        printf("%.4f %.4f %.4f\n", S-V, V-R, R);
    }
}