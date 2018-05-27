#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef int ull;
int sieve_par=1000;
ull prime[1000] , my_array[1001],counter=0,save_k[1000001];
vector<int> myvector[13];
void sieve()
{
    for(int i=1;i<sieve_par;i++)
        my_array[i]=1;

    my_array[0]=0;
    ull j;
    for(ull i=2;i<=sieve_par;i++)
    {
        if(my_array[i-1]==1)
        {
            prime[counter]=i;
            for(j=i*i;j<=sieve_par;j+=i)
                my_array[j-1]=0;
            counter++;
        }
    }
}
ull factorise(ull n)
{
    ull i=0,total=0;
    while(i!=counter && prime[i]*prime[i]<=n)
    {
        if(n%prime[i]==0)   
        {
            total+=prime[i];
            while(n%prime[i]==0)
                n/=prime[i];
        }
        i++;
    }
    if(n!=1)
        total+=n;
    return total;
}
void constant()
{
    int tot;
    memset(save_k,0,sizeof(save_k));
    for(int i=0;i<counter;i++){
        save_k[prime[i]]=1;
        myvector[1].push_back(prime[i]);
    }
    for(int i=4;i<=1000000;i++)
        if(save_k[i])   continue;
        else{
            tot=factorise(i);
            save_k[i]=1+save_k[tot];
            myvector[save_k[i]].push_back(i);
        }
}
int main()
{
    int left,right,k,sub,left_ans,right_ans;
    sieve();

    constant();
    int test;
    scanf("%d",&test);
    while(test--){
        sub=0;
        scanf("%d %d %d",&left,&right,&k);
        left--;
        if(k>12)
            printf("0\n");
        else{
            vector<int>::iterator low,up;
            low=lower_bound(myvector[k].begin(), myvector[k].end(), left);
            up=lower_bound (myvector[k].begin(), myvector[k].end(), right);
            left_ans=low-myvector[k].begin();
            right_ans=up-myvector[k].begin();
            if((*low)!=left)    left_ans-=1;
            if((*up)!=right)    right_ans-=1;
            printf("%d\n",-left_ans+right_ans);
        }
    }
    return 0;
}