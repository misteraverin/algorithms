#define TASKNAME "z"
#include <bits/stdc++.h>

#define MAXN int(1e6 + 100)
#define INF int(1e9)
#define pb push_back
#define mp make_pair
#define sz(A) (int)(A).size()
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
#define x fghsdhgjfshgkjfdhgjfs
#define y jhfjghjfdsghsjfddfkhfjkdash
#define hash fhjfshdjkfhsfjkdhsjfkshfskjfdhskj
#define prev fhjhajaghkjashgjkashgkjashgkjashfjkahfkjd
#define forn(i, n) for(int i = 0 ; (i) < (n); i++)
#define out(x) cout<<(x)<<" " << "\n"
#define DB(x) cerr<<#x<<" = "<<(x)<<"\n"
#define DB2(a,b)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"

using namespace std;
typedef long long ll;

int z[MAXN];
string str;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  cin >> str;
  for(int i = 1, l = 0, r = 0; i < sz(str); i++){
    if(i <= r)
      z[i] = max(0, min(z[i - l], r - i + 1));
    while(z[i] + i < sz(str) && str[z[i]] == str[z[i] + i])
      z[i]++;
    if(i + z[i] - 1 > r){
      l = i;
      r = z[i] + i - 1;
    }
  }
  for(int i = 1; i < sz(str); i++)
    cout<< z[i] << " ";
  return 0;
}
