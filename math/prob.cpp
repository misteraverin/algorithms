#define TASKNAME "lottery"
#include <bits/stdc++.h>

#define MAXN int(1e5 + 100)
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
int n, m;
double total_sum, total_prob = 1.0;
double a[MAXN], b[MAXN];


int main(){
  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++)
    scanf("%lf%lf", &a[i], &b[i]);
  for(int  i = 0; i < m - 1; i++){
    total_prob /= a[i];
    total_sum +=  total_prob * b[i] * (a[i + 1] - 1)/ a[i + 1];
  }
  total_sum += total_prob/a[m - 1] * b[m - 1];
  //DB(total_sum);
  printf("%.3lf", double(n) - total_sum);
  return 0;
}
