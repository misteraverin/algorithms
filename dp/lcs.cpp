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


#define MAXN int(1e3 +10)
#define pb push_back
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
#define TASKNAME "lcs2"
using namespace std;
string s, s1;
int dp[MAXN][MAXN];
vector<char> ans;



int main()
{
 
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  cin >> s;
  cin >> s1;
  for(int i = 0; i < int(s.size()); i++)
    for(int j = 0; j < int(s1.size()); j++)
      if(s[i] == s1[j])
          dp[i + 1][j + 1] = dp[i][j] + 1;
      else
          dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
  int i = int(s.size()), j = int(s1.size());
  while(i > 0 && j > 0){
    if(s[i - 1] == s1[j - 1]){
      ans.pb(s[i - 1]);
      i--;
      j--;
    }
    else if(dp[i - 1][j] > dp[i][j - 1])
      i--;
    else
      j--;
  }

  reverse(ans.begin(), ans.end());
  for(int i = 0; i < int(ans.size()); i++)
    cout << ans[i];          
  return 0;
}         