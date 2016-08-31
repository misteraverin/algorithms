#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cassert>

#define TASK_NAME "floyd"
#define MAXN int(2 * 1e3 + 100)
#define INF int(1e9)
using namespace std;

int n, d[MAXN][MAXN];

int floyd()
{
  for (int k=0; k<n; ++k)
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j)
        d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
   return 0;
}


int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        scanf("%d", &d[i][j]);

    floyd();
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        printf("%d ", d[i][j]);
      printf("\n");
    }

    return 0;
}
