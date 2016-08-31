#define TASKNAME "points"


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
#define MAXN int(1e5 + 10)
#define MOD 1000000007
#define pb push_back
#define mk make_pair
#define eps int(1e-9)
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
using namespace std;
int n;
long long ans = 1, power[MAXN], rev[MAXN];


long long binpow (long long a, long long n) {
  if (n == 0)
    return 1;
  if (n % 2 == 1)
    return (binpow (a, n-1) * a) % MOD;
  else {
    long long b = (binpow (a, n/2)) % MOD;
    return (b * b) % MOD;
  }
}


int main()
{

  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  cin >> n;
  for(long long i = 2; i <= n; i++){
    ans = (ans %  MOD  * i) % MOD;
    power[i] = ans;
  }
  power[0] = 1;
  power[1] = 1;
  long long MOD1 = 1000000005;
  for(int i = 1; i <= n ; i++)
    rev[i] = (binpow(power[i], MOD1)) % MOD;
  cout << 1 << "\n";
  for(int i = 1; i <= n; i++){
    cout << (((ans * rev[i]) % MOD) * rev[n - i]) % MOD << "\n";
  }
  return 0;
}
