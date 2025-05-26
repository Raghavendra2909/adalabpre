#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct edge
{
  int u, v, w;
};

struct edge edge[20], results[20];

int parent[20];
int n, e;
int enconter = 0;
int cost = 0;

int findparent(int node)
{
  if (parent[node] != node)
  {
    parent[node] = findparent(parent[node]);
  }
  return parent[node];
}

void sortedges()
{
  for (int i = 0; i < e - 1; i++)
  {
    for (int j = 0; j < e - i - 1; j++)
    {
      if (edge[j].w > edge[j + 1].w)
      {
        struct edge temp = edge[j];
        edge[j] = edge[j + 1];
        edge[j + 1] = temp;
      }
    }
  }
}

void union_sets(int u, int v)
{
  int root_u = findparent(u);
  int root_v = findparent(v);
  parent[root_u] = root_v;
}

void krushkal()
{
  sortedges();

  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  int k = 0;

  while (enconter < n - 1 && k < e)
  {
    struct edge currentedge = edge[k++];
    int u = currentedge.u;
    int v = currentedge.v;

    if (findparent(u) != findparent(v))
    {

      cost += currentedge.w;
      results[enconter] = currentedge;
      union_sets(u, v);

      enconter++;
    }
  }
}

int main()
{
  int i, j, w;

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the cost adjacency matrix (enter 0 for no edge):\n");
  e = 0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &w);
      if (w != 0 && i < j)
      { // Avoid duplicates
        edge[e].u = i;
        edge[e].v = j;
        edge[e].w = w;

        e++;
      }
    }
  }

  krushkal();

  printf("Edges of the Minimal Spanning Tree:\n");
  for (i = 0; i < enconter; i++)
  {
    printf("(%d, %d) - %d\n", results[i].u, results[i].v, results[i].w);
  }
  printf("Sum of Minimal Spanning Tree: %d\n", cost);

  return 0;
}