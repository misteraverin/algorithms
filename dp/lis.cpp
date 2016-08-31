#define TASKNAME "lis"
#include <bits/stdc++.h>

#define MAXN int(5100)
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
int n, a[MAXN], dp[MAXN], prev[MAXN];

int main()
{

  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  for(int i = 1; i <= n; i++){
    d[i] = 1;
    prev[i] = -1;
    for(int j = 1; j < i; j++)
      if(a[i] > a[j] && dp[j] + 1 > dp[i]){
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
  }
  int ans = 1;
  int max_ind = 1;
  for(int i = 1; i <= n; i++){
    if(dp[i] >= ans){
      ans = dp[i];
      max_ind = i;
    }
  }
  cout << ans << "\n";
  vector<int> recover;
  for(int to = max_ind; to != -1; to = prev[to])
    recover.pb(to);
  reverse(recover.begin(), recover.end());
  for(int i = 0; i < sz(recover); i++)
    cout << a[recover[i]] << " ";
  return 0;
}
