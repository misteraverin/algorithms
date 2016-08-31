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

#define TASK_NAME "dist"
#define MAXN int(1e5 + 10)
#define INF (1e15)
#define pb push_back
#define mp make_pair
#define x dfgdsjfgdsj
#define y fsdjfjashfas

using namespace std;


struct edge{
  int to;
  long long value;
};


int n, m, fin, st, value, a, b, used[MAXN];
long long dist[MAXN];
set<pair<long long, int> > dist_min;
vector<edge> g[MAXN];


void dijkstra(int start){
    dist[start] = 0;
    dist_min.erase(mp(INF, start));
    dist_min.insert(mp(0, start));
    for(int i = 1; i <= n; i++){
      int v = (*dist_min.begin()).second;
      used[v] = 1;
      dist_min.erase(mp(dist[v],v));
      for(int j = 0; j < int(g[v].size()); j++){
          int to = g[v][j].to;
          if(dist[to] > dist[v] + g[v][j].value){
            dist_min.erase(mp(dist[to], to));
            dist[to] = dist[v] + g[v][j].value;
            dist_min.insert(mp(dist[v] + g[v][j].value, to));
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
    for(int i = 1; i < MAXN; i++){
      dist[i] = INF;
      dist_min.insert(mp(INF, i));
    }
    for(int i = 0; i < m ; i++){
      scanf("%d %d %d\n", &a, &b, &value);
      edge tmp = {b, value};
      g[a].pb(tmp);
      tmp.to = a;
      g[b].pb(tmp);
    }
    dijkstra(st);
    if(dist[fin] != INF)
      printf("%lld\n", dist[fin]);
    else
      printf ("-1");
    return 0;
}
