#define TASKNAME "sort"
#include <bits/stdc++.h>

#define MAXN int(1e5 + 100)
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
int sorted[MAXN], x, n, heap[MAXN], cnt;
vector<int> ans;


void add(int value){
  heap[cnt++] = value;
  int i = cnt - 1;
  while(i > 0 && heap[(i - 1)/2] > heap[i]){
    swap(heap[(i - 1)/2], heap[i]);
    i = (i - 1)/2;
  }
}


void removeMin(){
  swap(heap[0], heap[cnt - 1]);
  cnt--;
  int i = 0;
  while(2 * i + 1 < cnt){
    int j = 2 * i + 1;
    if(2 * i + 2 < cnt && heap[j + 1] < heap[2 * i + 1])
      j = 2 * i + 2;
     if(heap[j] < heap[i]){
        swap(heap[i], heap[j]);
        i = j;
     }
     else break;
  }
}


int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    sorted[i] = x;
    add(x);
  }
  sort(sorted, sorted + n);
 // for(int i = 0; i < n; i++)
 //   cout << "parent: " << heap[i] << " sons ->" << heap[2 * i + 1] << " " << heap[2 * i + 2] << "\n";
  for(int i = 0; i < n; i++){
    ans.pb(heap[0]);
   // for(int j = 0; j < cnt; j++)
   //     cout << heap[j] << " ";
   // cout << "\n";
    removeMin();
  }
//  for(int i = 0; i < n; i++)
   // if(sorted[i] != ans[i]){
   //   DB("failed");
  //    break;
  //  }
  for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
  return 0;
}
