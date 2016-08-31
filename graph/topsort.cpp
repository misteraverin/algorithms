#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

#define TASK_NAME "topsort"
#define MAXN int(1e5 + 100)
#define pb push_back

using namespace std;

vector<int> a[MAXN];
vector<int> ans, num;
int used[MAXN], color[MAXN];
int n, m, tmp, tmp1;

bool dfs (int v) {
  used[v] = 1;
  color[v] = 1;
  for (int i = 0; i < int(a[v].size()); ++i) {
    int to = a[v][i];
      if (!used[to])
        if(dfs (to))
          return true;
    if(color[to] == 1)
      return true;

  }
  color[v] = 2;
  ans.push_back (v);
  return false;
}


void topological_sort() {
  for (int i = 1;i <= n; ++i)
    color[i] = false;
  ans.clear();
  bool cycle = false;
  for (int i = 1; i <= n; ++i)
    if (!color[i])
      cycle = max(cycle, dfs (i));

  if(cycle){
      printf("-1");
  }
  else{
     reverse (ans.begin(), ans.end());
     for(int i = 0; i < int(ans.size()); i++)
       printf("%d ", ans[i]);
  }
}


int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
      scanf("%d%d", &tmp, &tmp1);
      a[tmp].push_back(tmp1);
    }
    topological_sort();
    return 0;
}
