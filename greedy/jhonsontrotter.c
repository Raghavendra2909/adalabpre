#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LEFT -1
#define RIGHT 1

int findmobile(int dir[], int a[], int n)
{
  int mobile = 0;
  int mobileindex = -1;

  for (int i = 0; i < n; i++)
  {
    if (dir[i] == LEFT && i != 0 && a[i] > a[i - 1] && a[i] > mobile)
    {
      mobile = a[i];
      mobileindex = i;
    }
    if (dir[i] == RIGHT && i != n - 1 && a[i] > a[i + 1] && a[i] > mobile)
    {
      mobile = a[i];
      mobileindex = i;
    }
  }

  return mobileindex;
}

void printPermutation(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void jhonsontrotter(int n)
{
  int a[n];
  int dir[n];

  for (int i = 0; i < n; i++)
  {
    a[i] = i + 1;
    dir[i] = LEFT;
  }
  printPermutation(a, n);

  while (1)
  {
    int mobileindex = findmobile(dir, a, n);
    if (mobileindex == -1)
      break;

    int swapIndex = (dir[mobileindex] == LEFT) ? (mobileindex - 1) : (mobileindex + 1);

    int temp = a[mobileindex];
    a[mobileindex] = a[swapIndex];
    a[swapIndex] = temp;

    int temp1 = dir[mobileindex];
    dir[mobileindex] = dir[swapIndex];
    dir[swapIndex] = temp1;

    mobileindex = swapIndex;

    for (int i = 0; i < n; i++)
    {
      if (a[i] > a[mobileindex])
      {
        dir[i] = -dir[i];
      }
    }

    printPermutation(a,n);
  }
}



int main()
{
  int n;
  printf("Enter the value of n: ");
  scanf("%d", &n);

  printf("All permutations using Johnson-Trotter algorithm:\n");
  jhonsontrotter(n);

  return 0;
}