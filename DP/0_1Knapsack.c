#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int main()
{
  int n, capacity;
  int weights[MAX_ITEMS];
  int values[MAX_ITEMS];
  int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

  printf("Enter the number of items: ");
  scanf("%d", &n);

  printf("Enter the weights of the items: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &weights[i]);
  }

  printf("Enter the values of the items: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &values[i]);
  }

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= capacity; j++)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      else if (weights[i - 1] <= j)
      {
        dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  printf("Maximum value possible: %d\n", dp[n][capacity]);

  printf("dp table is: \n");
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= capacity; j++)
    {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }

  return 0;
}
