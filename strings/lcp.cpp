#define TASKNAME "lcp"


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

#define x fdfsdsdf
#define y jbvhfdgfdhj
#define MAXN int(1e5 +10)
#define pb push_back
#define mk make_pair
#define eps int(1e-9)
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
#define forn(i,n) for(int i=0;i<int(n);++i)
using namespace std;
long long t = 857, R = int(1e9 + 7), left1, right1;
int n, m;
string str;
long long hash[MAXN], pt[MAXN];
typedef long long LL;

void power(){
  pt[0] = 1;
  for(int i = 1; i <= int(str.size()); i++)
    pt[i] = (pt[i - 1] * t) % R;
}

void build_hash(){
  long long v = 0;
  n = int(str.size());
  for(int i = 0; i < n; i++){
     v = (v * t + (str[i])) % R;
     hash[i] = v;
  }
}


long long get_hash(int left, int right){
  LL vr = hash[right];
  LL vl;
  if(left == 0)
    vl = 0;
  else
   vl = hash[left - 1];
  LL ans = (vr - vl * pt[right - left + 1]) % R;
  if(ans < 0) //так быстрее, потому что предсказатель решений
    ans += R;
  return ans;
}


long long lcp(int a, int b){
  int l = 0; //ok, всегда будет пустая lcp
  n = int(str.size());
  int r = min(n - a + 1, n - b + 1);
  int mid;
  while(l < r - 1){
    mid = (l + r)/2;
    if(get_hash(a, a + mid - 1) == get_hash(b, b + mid - 1))
      l = mid;
    else
      r = mid;
  }

  return (long long)l;
}


int main()
{

  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  cin >> str;
  cin >> m;
  power();
  build_hash();
  n = int(str.size());
  forn(i, m){
    cin >> left1 >> right1;
    cout << lcp(left1, right1) << "\n";
  }
  return 0;
}
