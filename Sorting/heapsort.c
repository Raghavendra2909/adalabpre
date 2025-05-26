#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i)
{
  int parent = i;
  int lchild = 2 * parent + 1;
  int rchild = 2 * parent + 2;

  if (lchild < n && arr[parent] < arr[lchild])
  {
    parent = lchild;
  }
  if (rchild < n && arr[parent] < arr[rchild])
  {
    parent = rchild;
  }

  if (parent != i)
  {
    int temp = arr[i];
    arr[i] = arr[parent];
    arr[parent] = temp;

    heapify(arr, n, parent);
  }
}


void heapsort(int arr[], int n){
  
  for(int i= n-1 ; i>0; i--){
    heapify(arr,n,i);
  }

  for(int i=n-1; i>0; i--){
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i,0);
  }
}

int main() {
    int a[] = {8, 3, 7, 5, 6, 1};
    int n = sizeof(a) / sizeof(a[0]);

    heapsort(a,n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
