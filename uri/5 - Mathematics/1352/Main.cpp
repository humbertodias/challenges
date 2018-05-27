#include <iostream>
#include <cstdio>
using namespace std;
enum {
    SIZ = 102,
};
 
int sum[SIZ];
void init() {
    sum[0] = 0;
    for(int i=1;i<SIZ;i++) {
        sum[i] = i * (i-1)*(2*i-1)/6;
        for(int j=1;j<i-1;j++){
            for(int k=1;k<i-j;k++){
                sum[i] += (i-j-k)*(i-j-k);
            }
        }
    }
}
int num;
double p;
 
void fun() {
    double val = p;
    p = num * num;
    for(int i=0;i<4;i++) {
        val *= (p-i);
    }
    for(int i=1;i<=4;i++) {
        val /= i;
    }
    p = sum[num];
    val /= p;
    val /= 100;
    printf("%.2lf\n", val);
}
 
int main() {
    init();
    while(cin>>num>>p && num + p) {
        fun();
    }

    return 0;
}