#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
 
struct medalhas{
    int m1,m2,m3;
    string name;
 
    medalhas(string name):name(name){
        m1=m2=m3=0;
    }
    bool operator<(const medalhas i)const{
        return (m1==i.m1)?(m2==i.m2)?(m3==i.m3)?name>i.name:(m3<i.m3):m2<i.m2:m1<i.m1;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    int k=1;
    string str;
    vector<medalhas> vet;
    map<string,int> mp;
    vet.push_back(string("0"));
    while(getline(cin,str)){
        getline(cin,str);
        if(mp[str]==0){
            mp[str]=k++;
            vet.push_back(medalhas(str));
        }
        vet[mp[str]].m1++;
        getline(cin,str);
        if(mp[str]==0){
            mp[str]=k++;
            vet.push_back(medalhas(str));
        }
        vet[mp[str]].m2++;
        getline(cin,str);
        if(mp[str]==0){
            mp[str]=k++;
            vet.push_back(medalhas(str));
        }
        vet[mp[str]].m3++;
    }
    sort(vet.begin()+1,vet.end());
    cout << "Quadro de Medalhas" << endl;
    for(int i=k-1; i>0; --i)
        cout << vet[i].name << " " << vet[i].m1 << " " << vet[i].m2 << " " << vet[i].m3 << endl;
    return 0;
}