#define TASKNAME "exam"
#include <bits/stdc++.h>

#define MAXN int(1e6 + 100)
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
int n, k;
double final_prob = 0;
double p[MAXN], m[MAXN];


int main(){
  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  scanf("%d%d", &k, &n);
  for(int i = 0; i < k; i++){
    scanf("%lf%lf", &p[i], &m[i]);
    p[i] = p[i]/(1.0 * n);
    m[i] = m[i] * 0.01;
  }
  for(int i = 0; i < k; i++){
    final_prob += p[i] * m[i];
  }
  printf("%.5lf", final_prob);
  return 0;
}
