#include <cstdio>
#include <iostream>
using namespace std;
 
int n;
int leng[1000];//the depth
bool v[100];//is this node in the tree or removed!!
long long mx, ans;
long long freq[1000];//the ferq for every char
 
int get() {
  int deps = 0, pos;
  long long mnFreq;
  //chose the node with the max depth and small ferq
  for (int i = 0; i < n; i++)
    if (v[i] && (leng[i] > deps || (leng[i] == deps && freq[i] < mnFreq)))
      pos = i, deps = leng[i], mnFreq = freq[i];
 
  if (!mnFreq)//if this node is leave then add it's freq to the result
    ans += mx, freq[pos] = mx;
 
  v[pos] = 0; // delete the node
  return pos;
}
 
int main() {
  while (~scanf("%d" , &n)) {
    for (int i = 0; i < n; i++)
      scanf("%d", &leng[i]);
 
    for (int i = 0; i < n; i++)
      freq[i] = 0, v[i] = 1; // at fisrt all nodes are in the tree!
 
    ans = 0, mx = 1;
    //we need (n-1) iteration to compress all the tree
    for (int i = 1; i < n; i++) {
      int x = get(), y = get(); // get the largest 2 nodes
      mx = max(freq[x], freq[y]);
      leng[x]--; // when we compress 2 subtrees the depth decrease by 1
      freq[x] += freq[y];
      v[x] = 1;//create new node and this node is non-leave node
    }
    cout << ans << endl;
  }
  return 0;
}