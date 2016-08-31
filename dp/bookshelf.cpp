#define TASKNAME "bookshelf"
#include <bits/stdc++.h>

#define MAXN int(2100)
#define MAXM int(1e5 + 100)
#define pb push_back
#define mp make_pair
#define sz(A) (int)(A).size()
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
#define x fghsdhgjfshgkjfdhgjfs
#define y jhfjghjfdsghsjfd
#define out(x) cout<<(x)<<" " << "\n"
#define DB(x) cerr<<#x<<" = "<<(x)<<"\n"
#define DB2(a,b)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"

using namespace std;
typedef long long ll;
const long long INF = (1e12);
int n;
ll l;
ll w[MAXN], sum[MAXN], h[MAXN];
ll dp[MAXN]; // min. height in order to put i books


int main()
{

  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  cin >> n >> l;
  for(int i = 1; i <= n; i++)
    cin >> h[i] >> w[i];
  for(int i = 1; i <= n; i++)
    sum[i] = w[i] + sum[i - 1];
  for(int i = 1; i <= n; i++) dp[i] = INF;
  dp[1] = h[1];
  for(int i = 2; i <= n; i++){
    set<ll> heights;
    for(int j = i; j >= 1; j--){
      heights.insert(h[j]);
      if(sum[i] - sum[j - 1] <= l)
        dp[i] = min(dp[i], dp[j - 1] + *(heights.rbegin()));
    }
  }
  cout << dp[n];
  return 0;
}
