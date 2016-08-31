#define TASKNAME "problem3"
#include <bits/stdc++.h>

#define MAXN int(1e5 + 100)
#define MOD int(1e9 + 7)
#define INF int(1e9)
#define all(A) A.begin(), A.end()
#define pb push_back
#define mp make_pair
#define sz(A) (int)(A).size()
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
#define x fghsdhgjfshgkjfdhgjfs
#define y jhfjghjfdsghsjfd
#define prev fhjhajaghkjashgjkashgkjashgkjashfjkahfkjd
#define out(x) cout<<(x)<<" " << "\n"
#define DB(x) cerr<<#x<<" = "<<(x)<<"\n"
#define DB2(a,b)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"

using namespace std;
typedef long long ll;

int n, k, m, u, v, t;
int state[MAXN], used[MAXN], used_ter[MAXN];
int cycle[MAXN]; // вершина на цикле
char value;
string str;
int ans, d[MAXN];
int dp[MAXN];
int g[MAXN][27], gr[MAXN][27];
vector<int> order;
bool is_cycle = false;

void add(int& a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}


void dfs(int v){
  used[v] = 1;
  for(int i = 0; i < 26; i++){
    int to = g[v][i];
    if(to == 0)
      continue;
    if(used[to] == 1){
     // cycle[v] = 1;
      cycle[to] = 1;
      is_cycle = true;
    }
    else if(used[to] == 0) dfs(to);
  }
  used[v] = 2;
  order.pb(v);
}


// dfs from terminal vertexs, to mark all vertes, which are in cycle and
void dfs1(int v){
  used_ter[v] = 1;
//  DB(v);
  for(int i = 0; i < 26; i++){
    int to = gr[v][i];
  //  DB(to);
    if(to == 0 || used_ter[to] == 1)
      continue;
    else if(used_ter[to] == 0){
    //  DB("fgsjhhjdf");
    //  DB(to);
      dfs1(to);
    }
  }
  used_ter[v] = 2;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++){
    cin >> t;
    state[t] = 1;
  }
  for(int i = 0; i < m; i++){
    cin >> u >> v >> value;
    g[u][value - 'a'] = v;
    gr[v][value - 'a']  = u;

  }
  dfs(1);
  for(int i = 1; i <= n; i++)
    if(state[i] == 1 && used_ter[i] == 0)
      dfs1(i);

  for(int v = 1; v <= n; v++){
   // cerr << v << " " << used[v] << " " << used_ter[v] << " " << cycle[v] << "\n";
    if(used[v] == 2 && used_ter[v] == 2 && cycle[v] == 1){
      cout << -1;
      return 0;
    }
  }
  reverse(all(order));
  dp[1] = 1;
  //calc dp after topsort  in array d
  for(int i = 0; i < sz(order); i++){
    int v = order[i];
    for(int j = 0; j < 26; j++){
      int to = g[v][j];
      if(to != 0)
        add(dp[to], dp[v]);
    }
  }
  /*
    ДКА конечно, когда не существует такой ситуации:
    1. v достижима из start
    2. из v достижима terminal вершина
    3. из v по одному или более переходам достижима v
    Если нет, то можем найти цикл, который достижим из start, но не ведёт в terminal и наоборот
  */
  for(int i = 1; i <= n; i++)
    if(state[i] == 1 && used[i] == 2)
      add(ans, dp[i]);
  cout << ans;
  return 0;
}
