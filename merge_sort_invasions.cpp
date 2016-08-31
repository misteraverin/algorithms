#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <time.h>

#define TASK_NAME "qsort"
#define MAXN int(1e6) + 10

using namespace std;
int n, z, k, a[MAXN], b[MAXN], sum_invers = 0;


void merge(int low, int high){
        int mid = (low + high) / 2;
        int i = 0;
        int pos1 = low;
        int pos2 = mid + 1;
        while((pos1 <= mid)&&(pos2 <= high)){
          if(a[pos1] <= a[pos2]){
                    sum_invers += pos2 - mid - 1;
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
                sum_invers += pos2 - mid - 1;
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
    merge(l, r);
  }
}


int main()
{
    freopen(TASK_NAME".in", "r", stdin);
    freopen(TASK_NAME".out", "w", stdout);
    srand(time(0));
    while(1){
        int sum = 0;
        n = rand() % 10;
        for(int i = 0; i < n; i++)
            a[i] = rand() % 1000;
        for(int i = 0; i < n; i++)
          for(int j = i + 1; j < n; j++)
            if(a[i] > a[j])
              sum++;
        fprintf(stderr, "%d%d%d-> ", z);
        for(int i = 0; i < n; i++)
          fprintf(stderr, "%d ",a[i]);
        fprintf(stderr,"\n");
        mergesort(0, n - 1);
        if(sum == sum_invers)
           fprintf(stderr, "TEST\n");
        else{
           fprintf(stderr, "Fail %d %d\n", sum, sum_invers);
        break;
        }
        sum_invers = 0;
        z++;
    }
    return 0;
}
