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

#define TASK_NAME "time"
#define MAXN int(1100)
#define INF (1e9 + 10)
#define pb push_back
#define mp make_pair
#define x dfgdsjfgdsj
#define y fsdjfjashfas

using namespace std;


struct edge{
  int from, to, time_from, time_to;
};


int n, m, fin, st, value, a, b, timefrom, timeto;
int time_arr[MAXN];
vector<edge> g;


void ford_bellman(int start){
  time_arr[start] = 0;
  if(n == 1)
    n = m;
  for(int i = 0; i <=  n; i++)
    for(int j = 0; j < m; j++){
    //  cerr << time_arr[g[j].to] << " " <<  g[j].time_to << "\n";
      if(time_arr[g[j].to] > g[j].time_to && time_arr[g[j].from] <= g[j].time_from){
        time_arr[g[j].to] = g[j].time_to;
      }
    }
}


int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
    scanf("%d", &n);
    scanf("%d%d", &st, &fin);
    scanf("%d", &m);
    for(int i = 1; i < MAXN; i++)
      time_arr[i] = INF;
    for(int i = 0; i < m ; i++){
      scanf("%d %d %d %d\n", &a, &timefrom, &b, &timeto);
      edge tmp = {a, b, timefrom, timeto};
      g.pb(tmp);
    }
    ford_bellman(st);
    if(st == fin)
      printf("%d ", time_arr[st]);
    else
      printf("%d ", time_arr[fin]);
    return 0;
}
