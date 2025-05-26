#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int adj[20][20];
int weight[20];
int result[20][2];
int n;

void dijstas(int s)
{
  int d[20], p[20], visited[20];

  for (int i = 0; i < n; i++)
  {
    d[i] = INT_MAX;
    p[i] = s;
    visited[i] = 0;
  }
  
  d[s] = 0;
  visited[s] = 1;
  for (int i = 0; i < n; i++)
  {
    int mini = INT_MAX;
    int u = 0;

    for (int j = 0; j < n; j++)
    {
      if (d[j] < mini && visited[j] != 1)
      {
        mini = d[j];
        u = j;
      }
    }
    visited[u] = 1;

    for (int v = 0; v < n; v++)
    {
      if (visited[v] == 0 && (d[u] + adj[u][v] < d[v]))
      {
        d[v] = d[u] + adj[u][v];
        p[v] = u;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    result[i][0] = p[i];
    result[i][1] = i;
    weight[i] = d[i];
  }
}




int main()
{
    int i, j, s;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    dijstas(s);
    printf("Path:\n");
    for (i = 1; i < n; i++)
    {
        printf("(%d, %d) with weight %d ", result[i][0], result[i][1], weight[result[i][1]]);
    }
    return 0;
}