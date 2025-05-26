#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int adj[20][20];
int d[20][20];
int n;

int min(int a, int b)
{
  return (a >= b) ? b : a;
}
void floyds()
{

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      d[i][j] = adj[i][j];
    }
  }

  for (int k = 0; k < n; k++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int i = 0; i < n; i++)
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main()
{
  printf("Enter the no. of vertices:");
  scanf("%d", &n);
  printf("Enter the cost adjacency matrix:\n");
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &adj[i][j]);
    }
  }
  floyds();
  printf("Distance Matrix:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
  return 0;
}