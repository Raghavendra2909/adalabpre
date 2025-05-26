/*
Algorithm:
mergesort(arr){
  int b[n/2-1]
  int c = [n/2 -1]
  if(n>1){
  copy(a[0......n/2] = b[0....n/2]
  similarly for c also
 
  mergesort(b);
  mergesort(c);
  merge(b,c,a);
  }
}

merge(b,c,a){
  int i=0;
  int j=0;
  int k=0;
  until(i<p ; j<q){
  if(b[i]<c[j]){\
    a[k] = b[i];
    i++;
  } else{
   a[k] = c[j];
   j++;
   }
   k++;
  }


  if(i==p){
  copy(j...q-1) = a[k.....p+q-1]}else{
  viceversa}
}
*/

#include <stdio.h>
#include<time.h>

void merge(int b[], int p, int c[], int q, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (b[i] < c[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = c[j++];
        }
    }
    while (i < p) {
        a[k++] = b[i++];
    }
    while (j < q) {
        a[k++] = c[j++];
    }
}

void mergesort(int arr[], int n) {
    if (n <= 1) return;

    int mid = n / 2;

    // declare arrays b and c using VLAs (variable length arrays)
    int b[mid];
    int c[n - mid];

    // copy to b and c
    for (int i = 0; i < mid; i++) b[i] = arr[i];
    for (int i = mid; i < n; i++) c[i - mid] = arr[i];

    mergesort(b, mid);
    mergesort(c, n - mid);

    merge(b, mid, c, n - mid, arr);
}

int main() {
    int a[] = {8, 3, 7, 5, 6, 1,5,5,45,48,7,456,7,45,456,5,468,4,647,65468,4,4,54,6,7436,46,4,654,3,4,5,74,5,4,4,52,4,2,4,32,1524,4,5,4156,4,56,4,34,6514,656453,4,56,15,4,34,54,46,41,64,634,63,4156,4153,4,541,6541,354,65,415,4,4,5614,564,54,416,54,56};
    int n = sizeof(a) / sizeof(a[0]);
    
    clock_t start = clock();
    mergesort(a, n);
    for(int i=0 ; i<99999999; i++){
        int x = i+1;
    }
    clock_t end = clock();


    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    double time = ((double)(end-start)/ CLOCKS_PER_SEC);
    printf("Time taken: %f", time*1000);

    return 0;
}
