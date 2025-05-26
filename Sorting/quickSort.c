#include <stdio.h>
#include <limits.h>

int horepartition(int a[], int l, int r)
{
  int p = a[l];
  int i = l - 1;
  int j = r + 1;

  while (1)
  {
    // move i right until a[i] >= pivot
    do
    {
      i++;
    } while (a[i] < p);

    // move j left until a[j] <= pivot
    do
    {
      j--;
    } while (a[j] > p);

    if (i >= j)
      return j;

    // swap a[i] and a[j]
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
}

void quickSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int p = horepartition(arr, l, r);
    quickSort(arr, l, p);
    quickSort(arr, p + 1, r);
  }
}

int main()
{
  int a[] = {8, 3, 7, 5, 6, 1};
  int n = sizeof(a) / sizeof(a[0]);

  quickSort(a, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}