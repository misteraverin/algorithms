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

#define TASK_NAME "distance"
#define MAXN int(5010)
#define INF (1e15)
#define pb push_back
#define x dfgdsjfgdsj
#define y fsdjfjashfas

using namespace std;


struct edge{
  int to;
  long long value;
};


int n, m, fin, st, value, a, b, used[MAXN], pr[MAXN];
long long dist[MAXN];
vector<edge> g[MAXN];
vector<int> path;


void dijkstra(int start){
    pr[start] = -1;
    dist[start] = 0;
    for(int i = 1; i <= n; i++){
      long long mini = INF;
      int index1 = 0;

      for(int k = 1; k <= n; k++)
       if(dist[k] < mini && !used[k]){
        mini = dist[k];
        index1 = k;
       }

      int v = index1;

      used[v] = 1;
      for(int j = 0; j < int(g[v].size()); j++){
          int to = g[v][j].to;
          if(dist[to] > dist[v] + g[v][j].value){
            dist[to] = dist[v] + g[v][j].value;
            pr[to] = v;
          }
      }
    }
}


int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%d%d", &st, &fin);
    for(int i = 0; i < MAXN; i++)
      dist[i] = INF;
    for(int i = 0; i < m ; i++){
      scanf("%d %d %d\n", &a, &b, &value);
      edge tmp = {b, value};
      g[a].pb(tmp);
      tmp.to = a;
      g[b].pb(tmp);
    }
    dijkstra(st);
    if(dist[fin] != INF){
      printf("%lld\n", dist[fin]);
      for(int v = fin; v != -1; v = pr[v])
        path.pb(v);
      reverse(path.begin(), path.end());
      for(int i = 0; i < int(path.size()); i++)
        printf("%d ", path[i]);
    }
    else
      printf("-1");
    return 0;
}
