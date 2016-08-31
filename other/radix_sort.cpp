#define TASKNAME "radixsort"
#include <bits/stdc++.h>

#define MAXN int(3000)
#define INF int(1e9)
#define pb push_back
#define mp make_pair
#define sz(A) (int)(A).size()
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
#define x fghsdhgjfshgkjfdhgjfs
#define y jhfjghjfdsghsjfd
#define out(x) cout<<(x)<<" " << "\n"
#define DB(x) cerr<<#x<<" = "<<(x)<<"\n"
#define DB2(a,b)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"

using namespace std;
int a[MAXN], n, m, k;
string str[MAXN];
int used[30];

void radix_sort(int ind){

   string b[MAXN];
   for(int i = 0; i < 26; i++)
    used[i] = 0;
   for(int i = 0; i < n; i++){
    int digit = (str[i][ind]) - 'a';
    used[digit]++;
   }
   int cnt = 0;
   for(int i = 0; i < 26; i++){
    int t = used[i];
    used[i] = cnt;
    cnt += t;
   }
   for(int i = 0; i < n; i++){
    int digit = (str[i][ind]) - 'a';
    b[ used[digit] ] = str[i];
    used[digit]++;
   }
   for(int i = 0; i < n; i++){
    str[i] = b[i];
   }
}


int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++)
    cin >> str[i];
  for(int i = m - 1; i >= 0; i--){
    radix_sort(i);
  }
  for(int i = 0; i < n; i++)
    cout << str[i] << "\n";
  return 0;
}
