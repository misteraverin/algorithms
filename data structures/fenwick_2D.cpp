#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <cstddef>

#define TASK_NAME "camomiles"
#define MAXN int(1e3 + 10)
#define x dfgdsjfgdsj
#define y fsdjfjashfas

using namespace std;
int w, h, n, k, t;
long long fenvik[MAXN][MAXN];
long long ans;

struct point{
  int x, y;
};


void update(int x, int y, int value){
  for(int i = x; i <= w; i |= i + 1)
    for(int j = y; j <= h; j |= j + 1)
      fenvik[i][j] += value;
}


long long sum(int x3, int y3){
  long long ans = 0;
  for(int i = x3; i >= 0;   i &= (i+1), i--)
    for(int j = y3; j >= 0; j = (j & (j + 1)) - 1)
      ans += fenvik[i][j];
  return ans;
}


long long get_sum(int x, int y, int x2, int y2){

  //  cerr << sum(x2, y2) << " " << sum(x - 1, y - 1) << " " <<  sum(x2, y - 1) << " " << sum(x - 1, y2);
    return sum(x2, y2) + sum(x - 1, y - 1) - sum(x2, y - 1) - sum(x - 1, y2);


}


point pt, pt1, pt2;


int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
    scanf("%d%d", &w, &h);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &t);
      if(t == 1){
        scanf("%d%d%d", &pt.x, &pt.y, &k);
        update(pt.x, pt.y, k);
      }
      else if(t == 2){
        scanf("%d%d%d%d", &pt1.x, &pt1.y, &pt2.x, &pt2.y);
        printf("%lld\n", get_sum(pt1.x, pt1.y, pt2.x, pt2.y));
      }
    }
    return 0;
}
