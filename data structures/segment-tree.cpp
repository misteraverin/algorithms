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
#define MAXN int(1e5)
#define pb push_back
#define mk make_pair
#define INF int(1e9)
#define pi 3.1415926535897932384626433832795
#define sqr(a) ((a) * (a))
#define TASKNAME "segment-tree"
using namespace std;



struct Tnode{
  int l, r;
  long long sum, val;
  int child_left = - 1, child_right = -1;
  Tnode() {
    sum = -1;
    val = 0;
  }
};


Tnode tree[8 * MAXN];
int mas[MAXN], n, cnt = 0, k, a, b, number, l, r, add;
char value;

int new_node(){
  return cnt++;
}


int buildTree(int left, int right){
  int node = new_node();
  tree[node].l = left;
  tree[node].r = right;
  if(right - left == 1){
    tree[node].sum = mas[left];
    return node;
  }
  int mid = (left + right) / 2;
  tree[node].child_left = buildTree(left, mid);
  tree[node].child_right = buildTree(mid, right);
  tree[node].sum = tree[tree[node].child_left].sum + tree[tree[node].child_right].sum;
  return node;
}


void push(int v){
  if(tree[v].r - tree[v].l == 1){
    tree[v].sum += tree[v].val;
    tree[v].val = 0;
    return ;
  }
  tree[v].sum += (tree[v].r - tree[v].l) * tree[v].val;
  tree[tree[v].child_left].val += tree[v].val;
  tree[tree[v].child_right].val += tree[v].val;
  tree[v].val = 0;
}

void update(int v, int add, int l, int r){
  push(v);
  if(tree[v].l >= r || tree[v].r <= l)
    return;
  if (tree[v].l >= l && tree[v].r <= r){
    tree[v].val += add;
    return;
  }
  update(tree[v].child_left, add, l, r);
  update(tree[v].child_right, add, l, r);
}


long long get(int v, int l, int r){
  push(v);
  if(tree[v].l >= r || tree[v].r <= l)
    return 0;
  else if (tree[v].l >= l && tree[v].r <= r)
    return tree[v].sum;
  return (get(tree[v].child_left, l, r) + get(tree[v].child_right, l, r));
}


int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &mas[i]);
  buildTree(0, n);
  scanf("%d\n", &k);
  for(int i = 0; i < k; i++){
    scanf("%c ", &value);
    if(value == 'g'){
      scanf("%d\n", &number);
    // cout << "DEBUG" << "\n";
      //for(int i = 0 ; i < 2 * n - 1; i++)
        //cout << tree[i].l << " " << tree[i].r << " " << "value -> " << tree[i].sum << "\n";
      printf("%lld\n", get(0, number - 1, number));
    }
    else if(value == 'a'){
      scanf("%d %d %d\n", &a, &b, &add);
      update(0, add, a - 1, b);
    }

  }
  return 0;
}                                     
