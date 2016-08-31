#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <vector>


#define MAXN int(2*1e4 +10)
#define pb push_back
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
#define mk make_pair
#define TASKNAME "condense2"
using namespace std;
int  m, s, t, t1, n, visited[MAXN], comp[MAXN], component = 1;
vector<int> g[MAXN], gr[MAXN], order;
vector<pair<int, int> > vertex;
pair<int, int> foo;
set<pair<int, int> > myset;

int dfs1(int v){
  visited[v] = 1;
  for(int i = 0; i < int(g[v].size()); i++)
    if(visited[g[v][i]] == 0)
      dfs1(g[v][i]);
  order.pb(v);
  return 0;
}


int dfs2(int v){
  visited[v] = 1;
  comp[v] = component;
  for(int i = 0; i < int(gr[v].size()); i++)
    if(visited[gr[v][i]] == 0)
      dfs2(gr[v][i]);
  return 0;
}


int main()
{

  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    cin >> t >> t1;
    foo = mk(t, t1);
    vertex.pb(foo);
    g[t].pb(t1);
    gr[t1].pb(t);
  }
  for(int i = 1; i <= n; i++)
    if(visited[i] == 0)
      dfs1(i);
  for(int i = 1; i <= n; i++)
    visited[i] = 0;
  reverse(order.begin(), order.end());
  for(int i = 0; i < n; i++){
    int s = order[i];
    if(visited[s] == 0){
      dfs2(s);
      component++;
    }
  }
  for(int i = 0; i < int(vertex.size()); i++){
    if(comp[vertex[i].first] != comp[vertex[i].second]){
      foo = mk(comp[vertex[i].first], comp[vertex[i].second]);
      myset.insert(foo);
    }
  }
  cout<< int(myset.size());
  return 0;
}
