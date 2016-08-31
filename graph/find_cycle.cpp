#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

#define TASK_NAME "cycle2"
#define MAXN int(1e5 + 100)
#define pb push_back

using namespace std;

vector<int> g[MAXN];
vector<int> ans, num;
int color[MAXN], pred[MAXN];
int n, m, tmp, tmp1, cycle_st, cycle_fin;
bool cycle = false;


int dfs (int v) {
  color[v] = 1;
  for(int i = 0; i < int(g[v].size()); i++)
    if(color[g[v][i]] == 0 || color[g[v][i]] == 1){
      if(color[g[v][i]] == 1){
        cycle = true;
        cycle_st =  g[v][i];
        cycle_fin = v;
      }
      else{
        pred[g[v][i]] = v;
        dfs(g[v][i]);
      }
    }
  color[v] = 2;
  return 0;
}


void find_cycle() {
  for(int i = 1; i <= n; i++)
    if(color[i] == 0)
      dfs(i);
   if(cycle){
    cout << "YES\n";
    for(int v = cycle_fin; v != cycle_st; v = pred[v])
      ans.pb(v);
    reverse(ans.begin(), ans.end());
    cout << cycle_st << " ";
    for(int i = 0; i < int(ans.size()); i++)
      cout << ans[i] << " ";
   }
   else
    cout << "NO\n";
}


int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
      cin >> tmp >> tmp1;
      g[tmp].pb(tmp1);
    }
    find_cycle();
    return 0;
}
