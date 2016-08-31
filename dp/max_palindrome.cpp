#define TASKNAME "palindrome"
#include <bits/stdc++.h>

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
#define MAXN int(2100)
int dp[MAXN][MAXN]; // max. podpalindrome on the interval i..j
string str;


void go(int l, int r){
  string ans;
  while(l > 0  && r > 0){
     if(str[l - 1] == str[sz(str) - 1 - (r - 1)]){
       ans += str[l - 1];
       r--; l--;
     }
     else if(dp[l - 1][r] >= dp[l][r - 1])
       l--;
     else
       r--;
  }
  cout << sz(ans) << "\n" << ans;
}


int main()
{

  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  cin >> str;
  for(int i = 0; i <= sz(str); i++){
    dp[i][0] = 0;
    dp[0][i] = 0;
  }
  for(int i = 0; i <= sz(str); i++)
    for(int j = 0; j <= sz(str); j++){
      if(i == 0 || j == 0) continue;
      if(str[i - 1] == str[sz(str) - 1 - (j - 1)]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  go(sz(str), sz(str));
  return 0;
}
