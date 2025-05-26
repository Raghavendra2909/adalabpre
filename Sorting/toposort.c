#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int stack[20];
int adj[20][20];
int visited[20];
int top = -1;
int n;

void push(int num)
{
  stack[++top] = num;
}

int pop()
{
  return stack[top--];
}

void dfs(int v)
{
  visited[v] = 1;
  for (int i = 0; i < n; i++)
  {
    if (adj[v][i] && !visited[i])
    {
      dfs(i);
    }
  }
  push(v);
}

void topologicalsort()
{
  for (int i = 0; i < n; i++)
  {
    visited[i] = 0;
  }
  top = -1;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      dfs(i);
    }
  }
  printf("Topological sort of the arry is : \n");
  printf("Topological Sort Order:\n");
  while (top != -1)
  {
    printf("%d ", pop());
  }
  printf("\n");
}

int main()
{
  int e, u, v;
  printf("Enter number of vertices: ");
  scanf("%d", &n);
  printf("Enter number of edges: ");
  scanf("%d", &e);

  // Initialize adjacency matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      adj[i][j] = 0;
    }
  }

  printf("Enter edges (u v) where u and v are vertex indices (0 to %d):\n", n - 1);
  for (int i = 0; i < e; i++)
  {
    scanf("%d %d", &u, &v);
    adj[u][v] = 1;
  }

  topologicalsort();

  return 0;
}
