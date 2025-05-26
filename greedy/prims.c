#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

int n;
int graph[20][20];

int finminval(int key[], bool visited[])
{
  int mini = INT_MAX;
  int miniindexd = -1;

  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && key[i] < mini)
    {
      mini = key[i];
      miniindexd = i;
    }
  }
  return miniindexd;
}

void prims()
{
  int key[n];
  bool visited[n];
  int parent[n];
  for (int i = 0; i < n; i++)
  {
    key[i] = INT_MAX;
    visited[i] = false;
  }
  parent[0] = -1;
  key[0] = 0;

  for (int i = 0; i < n; i++)
  {
    int u = finminval(key, visited);
    visited[u] = true;

    for (int j = 0; j < n; j++)
    {
      if (graph[u][j] && !visited[j] && graph[u][j] < key[j])
      {
        key[j] = graph[u][j];
        parent[j] = u;
      }
    }
  }

  printf("Edge   Weight\n");
  for (int i = 1; i < n; i++)
  {
    printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
  }
}

int main()
{
  n = 5;

 
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }
  printf("Hence the minimum spannig tree is: ");
  prims();
}