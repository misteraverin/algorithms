#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

#define TASK_NAME "mst"
#define MAXN int(2 * 1e4 + 100)
#define INF int(1e9)
#define pb push_back
#define mp make_pair

using namespace std;
int parent[MAXN], used[MAXN], n, m, a, b, value, index1, cnt, dist[MAXN];
long long ans = 0;
set<pair<int, int> > dist_min;


struct edge{
  int to, value;
};


vector<edge> g[MAXN];

int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
      cin >> a >> b >> value;
      edge e = {b, value};
      g[a].push_back(e);
      e.to = a;
      g[b].push_back(e);
    }
    for(int i = 1; i <= n; i++){
      dist_min.insert(make_pair(INF, i));
      dist[i] = INF;
    }
    int v = 1;
    used[v] = 1;
    cnt = 1;
    while (n != cnt){
      for(int j = 0; j < int(g[v].size()); j++)
        if(used[g[v][j].to] == 0 && g[v][j].value < dist[g[v][j].to]){
         dist_min.erase(make_pair(dist[g[v][j].to], g[v][j].to));
         dist_min.insert(make_pair(g[v][j].value, g[v][j].to));
         dist[g[v][j].to] = g[v][j].value;

      }
      int mini = (*dist_min.begin()).first;
      ans += mini;
      index1 = (*dist_min.begin()).second;
      dist_min.erase(dist_min.begin());

      used[index1] = 1;
      v = index1;
      cnt++;
    }
    cout << ans;
    return 0;
}
