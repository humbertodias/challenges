#include <iostream>
#include <string>
#include <map>
 
 
using namespace std;
 
 
int main(){
    int m = 0, n = 0, t = 0;
    string japones, straux, traducao;
    map<string, string> mapDic;
    map<string, string>::iterator it;
 
    cin >> t;
    for (int i = 0; i < t; ++i){
 
        mapDic.clear();
        cin >> m;  cin >> n;
        getline(cin, japones);
 
        for(int i=0;i<m;i++){
            getline(cin, japones);  getline(cin, traducao);
            mapDic.insert(pair<string,string>(japones, traducao));
        }
 
        for(int i=0;i<n;i++){
            getline(cin, japones);
 
            for(int j=0;j<japones.size();j++){
                if(japones.at(j)!=' '){
                    straux+=japones.at(j);
                }else{
 
                    it=mapDic.find(straux);
 
                    if(it!=mapDic.end()){
                        cout<<it->second<<" ";
                    }else{
                        cout<<straux<<" ";
                    }
                    straux.clear();
                }
            }
 
            it = mapDic.find(straux);
 
            if(it != mapDic.end())
                cout<<it->second<<endl;
            else
                cout<<straux<<endl;
            straux.clear();
 
        }
 
        cout<<endl;
    }
 
return 0;
}