#define TASKNAME "hash"


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
using namespace std;
long long t, r;
int n;
string str;
long long hash[MAXN], pt[MAXN];

void power(){
  pt[0] = 1;
  for(int i = 1; i <= int(str.size()); i++)
    pt[i] = (pt[i - 1] * t) % r;
}


int main()
{

  freopen("hash.in", "r", stdin);
  freopen("hash.out", "w", stdout);
  cin >> t >> r;
  cin >> str;
  power();

  long long v = 0;
  n = int(str.size());
  for(int i = 0; i < n; i++){
     v = (v * t + (str[i])) % r;
     hash[i] = v;
  }
  for(int i = 0; i < n; i++)
    cout << hash[i] << "\n";
  return 0;
}
