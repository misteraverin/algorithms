
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>


#define TASK_NAME "qsort"
#define MAXN int(1e6) + 10

using namespace std;

int n, k, a[MAXN], b[MAXN], c[MAXN];


void merge(int low, int mid, int high){
        int h,i,k;
        i = 0;
        int pos1 = low;
        int pos2 = mid + 1;

        while((pos1 <= mid)&&(pos2 <= high)){
          if(a[pos1] <= a[pos2]){
                    b[i] = a[pos1];
                    pos1++;
                }
                else{
                    b[i] = a[pos2];
                    pos2++;
                }
                i++;
        }

        if(pos1 > mid){
            for(int j = pos2;j <= high; j++){
                b[i] = a[j];
                i++;
            }
        }
        else{
            for(int j = pos1; j <= mid; j++){
                b[i] = a[j];
                i++;
            }
        }

        for(int j = 0;j <= high - low; j++)
              a[j + low] = b[j];


}


void mergesort(int l, int r){
  int mid;
  if(l < r){
    mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, mid, r);
  }
}




int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
    mergesort(0, n);
	for(int i = 0; i < n; i++)
		printf("%d", a[i]);
    return 0;
}
