#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    string str;
    int ASCII[128];
    stack<int> order;
    while(cin >> str)
    {
        memset(ASCII, 0, sizeof(ASCII));
        for(int m=0;m<str.size();m++)
            ASCII[ (int)str[m] ]++;
        for(int m=str.size();m>=1;m--)
        {
            for(int o=1;o<=127;o++)
                if(ASCII[o] == m)
                    order.push(o);
        }
        while(!order.empty())
        {
            cout << order.top() << " " << ASCII[order.top()] << endl;
            order.pop();
        }
        cout << endl;
    }
    return 0;
}