#define TASKNAME "knapsack"
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
#define MAXN int(1010)
#define MAX_WEIGHT int(10010)
int dp[MAXN][MAX_WEIGHT];     // dp[i][j] - max. cost of knapsack if we look first i elements and fix the capacity j
int weight[MAXN], cost[MAXN], prev[MAXN];
int maxw, n;
vector<int> answer;


void print_ans(int size, int w, vector<int>&answer){
  if(size < 0) return;
  if(dp[size][w] == dp[size - 1][w])
    print_ans(size - 1, w, answer);
  else if(dp[size][w] == 0)
    return;
  else {
    print_ans(size - 1, w - weight[size], answer);
    answer.pb(size);
  }
}


int main()
{

  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  cin >> n;
  cin >> maxw;
  for(int i = 1; i <= n; i++)
    cin >> weight[i];
  for(int i = 1; i <= n; i++)
    cin >> cost[i];
  for(int i = 0; i <= maxw; i++)
    dp[0][i] = 0;
  for(int i = 1; i <= n; i++)
    for(int w = 0; w <= maxw; w++){
      dp[i][w] = dp[i - 1][w];
      if(w - weight[i] >= 0 && dp[i - 1][w - weight[i]] + cost[i] > dp[i][w]){
        dp[i][w] = dp[i - 1][w - weight[i]] + cost[i];
      }
    }
  print_ans(n, maxw, answer);
  cout << sz(answer) << "\n";
  for(int i = 0; i < sz(answer); i++)
    cout << answer[i] << " ";
  return 0;
}
