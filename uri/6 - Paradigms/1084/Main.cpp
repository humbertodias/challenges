#include <iostream>
#include <cstdio>
using namespace std;

const int cstMax = 100005;
const int cstEmptyStack = -1;
char vstack[cstMax], number[cstMax];

int main()
{
  int n, i, d, top;

  while ( cin >> n >> d && (n || d))
    {
        top = cstEmptyStack;
        cin >> number;
        for(i = 0; i < n; i++)
        {
            char current = number[i];
            while ( d > 0 && top != cstEmptyStack && vstack[top] < current )
                --top, --d;
            vstack[++top] = current;
        }
        top -= d;
        vstack[top+1] = 0;
        cout << vstack << "\n";
    }

    return 0;
}