#define TASKNAME "pathbge1"
#include <bits/stdc++.h>

#define MAXN int(1e4 * 3 + 10)
#define INF int(1e9)
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
int d[MAXN], a, b, used[MAXN], n, m;
vector<int> g[MAXN];


void bfs(int st){
  used[st] = 1;
  queue<int> q;
  q.push(st);
  d[st] = 0;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    //used[v] = 1;
    for(int i = 0; i < sz(g[v]); i++){
      int to = g[v][i];
      if(used[to] == 0){
        used[to] = 1;
        d[to] = d[v] + 1;
        q.push(to);
      }
    }
  }
}


int main()
{

  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  cin >> n >> m;
  for(int i = 0; i < m; i++){
     cin >> a >> b;
     g[a].pb(b);
     g[b].pb(a);
  }
  bfs(1);
  for(int i = 1; i <= n; i++)
    cout << d[i] << " ";
  return 0;
}
