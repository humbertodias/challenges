#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
 
using namespace std;
 
int priority(char symbol)
{
    switch(symbol)
    {
 //   case '(':
      //  return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
   // case '%':
        return 2;
    case '^':
        return 3;
    default :
        return 0;
    }
}
int main()
{
 
    string ara;
    stack <char> mystack;
    vector <char> output;
    int tc;
 
    cin>>tc;
    while(tc--){
    cin>>ara;
 
    for(int i=0;i<ara.length();i++){
 
            if( ara[i] == '+' || ara[i] == '-' || ara[i] == '*' || ara[i] == '/' || ara[i] == '^'){
                while( !mystack.empty() && priority(mystack.top()) >= priority(ara[i]) ){
                    output.push_back(mystack.top());
                    mystack.pop();
                }
                mystack.push(ara[i]);
            }
            else if(ara[i] == '('){
                mystack.push(ara[i]);
            }
            else if( ara[i]==')' ){
                while( mystack.top() !='(' ){
                      output.push_back(mystack.top());
                      mystack.pop();
                }
                mystack.pop();
            }
            else {
                output.push_back(ara[i]);
            }
 
    }
 
        while( !mystack.empty() ){
            output.push_back(mystack.top());
            mystack.pop();
        }
        //printStack(mystack);
 
        for(int i=0;i<output.size();i++){
            cout<<output[i];
        }
        cout<<endl;
        while(!output.empty()){
            output.pop_back();
        }
 
    }
 
    return 0;
}