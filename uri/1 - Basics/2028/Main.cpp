#include<iostream>

using namespace std;

int main()
{
    int i, k, sum,n, TC=0;

      while(cin>> n)
    {
        TC++;
        sum=0;
        if(n==0)
        {
            sum++;
            cout<<"Caso "<<TC<<": "<<sum<<" numero"<<endl;
            cout<<"0"<<endl;
        }
        else
        {
            for(i=0; i<=n; i++)
            {
                for(k=1; k<=i; k++)
                {
                    sum++;
                }
            }
            cout<<"Caso "<<TC<<": "<<sum+1<<" numeros"<<endl;
            cout<<"0 ";
            for(i=0; i<=n; i++)
            {
                for(k=1; k<=i; k++)
                {
                    cout<<i;
                    if(k<n) cout<< " ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}