// Problem   Economic phone calls
// Algorithm Dynamic Programming
// Runtime   O(n^2)

#include <cstdio>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring> //strlen 
using namespace std;

#define MAXN 1000

int call_times[MAXN];
int year[MAXN];
int dp[MAXN];
char wanted[MAXN];

int ndays(int m) {
  if (m == 2)
    return 28;
  if (m <= 7)
    return 30+(m%2);
  return 31-(m%2);
}

int main() {
  int n;
  while(1) {
    assert(scanf("%d",&n) == 1);
    if (n == 0)
      break;
    assert(n > 0 && n <= 1000);
    int m,d,h,M;
    char num[20];
    for (int i=0; i<n; i++) {
      assert(scanf("%d:%d:%d:%d %s %c",&m,&d,&h,&M,num,&wanted[i]) == 6);
      assert(strlen(num) <= 16);
      assert(m >= 1 && m <= 12);
      assert(d >= 1 && d <= ndays(m));
      assert(h >= 0 && h <= 23);
      assert(M >= 0 && M <= 59);
      assert(wanted[i] == '+' || wanted[i] == '-');
      for (int j=0; num[j]; j++)
        assert(isdigit(num[j]));
      // convert the time to minutes
      // for simplicity assume all months have 31 days
      call_times[i] = (((m * 31 + d) * 24 + h) * 60 + M);
    }
    // recovery of years (how many years back each call is dated)
    year[n-1] = 0;
    for (int i=n-2; i>=0; i--) {
      year[i] = year[i+1];
      if (call_times[i] >= call_times[i+1])
        year[i]++;
    }
    bool lastplus = false;
    for (int i=n-1; i>=0; i--) {
      // calculate minimum number of calls to keep from the last n-i phone calls if we keep phone call i
      dp[i] = n-i; // first assume we need all phone calls
      if (year[i] == 0 && !lastplus)
        dp[i] = 1;
      if (wanted[i] == '+') lastplus = true;
      for (int j=i+1; j<n && year[i]-year[j] <= 1; j++) { // find a phone call to keep which is at most 1 year later

        // same year?
        if (year[j] == year[i]) { // delete all phone calls i+1 to j-1 and keep phone call j
          dp[i] = min(dp[i],dp[j] + 1); // refer to the best result starting with phone call j
        }
        else { // next year
          if (call_times[j] > call_times[i]) { // would look like the same year
            break;
          }
          dp[i] = min(dp[i],dp[j] + 1);
        }
        if (wanted[j] == '+')
          break;
      }
    }
    // find first phone call which has to be kept
    int result = -1;
    for (int i=0; i<n; i++)
      if (wanted[i] == '+') {
        result = dp[i];
        break;
      }
    assert(result >= 0);
    printf("%d\n",result);
  }
  return 0;
}