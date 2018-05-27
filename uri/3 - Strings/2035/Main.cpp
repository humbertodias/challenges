#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
struct tree{
	int team[2];
	string st;
	struct tree *child[26];
	tree()
	{
		st="";
		team[0]=team[1]=0;
		for(int i=1;i<26;i++)
			child[i]=NULL;
	}
};
string input;
long long int ans;
 
void insert(tree *head,string val,int index)
{
	for(int i=0;i<val.length();i++)
	{
		if(head->child[val[i]-'A']==NULL)
		{
			head->child[val[i]-'A']=new tree;
			head->st+=val[i];
		}
		head=head->child[val[i]-'A'];
		head->team[index]++;
	//	printf("team0-> %d, team1->%d\n",head->team[0],head->team[1]);
	}
}
 
void traverse(tree *head)
{
	if(head->team[0]!=0 && head->team[1]!=0)
		ans+=min(head->team[0],head->team[1]);
	else
		return;
 
	for(int i=0;i<head->st.length();i++)
		traverse(head->child[head->st[i]-'A']);
}
 
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		ans=0;
		tree *head=new tree;
		for(int i=0;i<n;i++)
		{
			cin>>input;
			insert(head,input,0);
		}
		for(int i=0;i<n;i++)
		{
			cin>>input;
			insert(head,input,1);
		}
		for(int i=0;i<head->st.length();i++)
			traverse(head->child[head->st[i]-'A']);
		printf("%lld\n",ans);
	}
	return 0;
}