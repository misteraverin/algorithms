#define TASKNAME "prefix"
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

int pref[MAXN];
string str;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  cin >> str;
  for(int i = 1; i < sz(str); i++){
    int j = pref[i - 1];// because of 0-index
    while(j > 0 && str[j] != str[i])
      j = pref[j - 1];
    if(str[i] == str[j]) j++;
    pref[i] = j;
  }
  for(int i = 0; i < sz(str); i++)
    cout<< pref[i] << " ";
  return 0;
}
