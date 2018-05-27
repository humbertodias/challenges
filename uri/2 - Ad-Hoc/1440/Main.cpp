#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int main()
{
    int n;
    int t=1;
    while(t==1)
    {
        scanf("%d",&n);
        std::map<int, int> r;
        if(n==0)
            break;
        string s;
        char c;
        int sum = 0;
        int no = 0;
        for(int i=0;i<n;i++)
        {
            cin>>s>>c;
            int time = ((s[0]-'0')*10 + (s[1]-'0'))*3600 + ((s[3]-'0')*10 + (s[4]-'0'))*60 + (s[6]-'0')*10 + (s[7]-'0') ;
            if(c == 'E')
                r[time] = 1;
            if(c == 'X')
                r[time] = -1;
            if(c == '?')
            {   
                no++;
                r[time] = 0;
            }
            sum += r[time];
        }
        int req_x = (no+sum)/2;
        int req_e = (no-sum)/2;
        map<int, int>::iterator it = r.begin();
        for(;it!=r.end();it++)
        {
            if(it->second==0)
            {
                if(req_e>0)
                {
                    it->second = 1;
                    req_e--;
                }
                else
                {
                    it->second = -1;
                    req_x--;
                }
            }
        }
        int max = 0, current = 0;
        for(it=r.begin();it!=r.end();it++)
        {
            current += it->second;
            if(current > max)
                max = current;
        }
    cout<<max<<endl;
    }
 
}