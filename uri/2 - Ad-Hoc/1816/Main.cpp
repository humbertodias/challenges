#include <cstdio>
#include <vector>
 
using namespace std;
 
vector<char> L(int('Z'-'A'+1));
 
inline void init()
{
	for(int i=0; i+'A'<='Z'; i++)
		L[i]='A'+i;
}
 
int main()
{
	int n,t=0;
	while(scanf(" %d",&n)>0 && n)
	{
		printf("Instancia %d\n",++t);
		init();
		for(int i=0; i<n; i++)
		{
			int l;
			scanf(" %d",&l);
			l--;
			char ll = L[l];
			printf("%c",ll);
			L.erase(L.begin()+l);
			L.insert(L.begin(),ll);
		}
		printf("\n\n");
	}
	return 0;
}