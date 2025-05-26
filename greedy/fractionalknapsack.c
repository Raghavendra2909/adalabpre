#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct items
{
  int weight;
  int value;
};

// sort items;

void sortitems(struct items item[], int n)
{
  for (int i = 0; i < n-1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      double r1 = (double)item[i].value / item[i].weight;
      double r2 = (double)item[j].value / item[j].weight;

      if (r1 < r2)
      {
        struct items temp = item[i];
        item[i] = item[j];
        item[j] = temp;
      }
    }
  }
}

int main()
{
  int n, capacity;
  struct items items[20];

  printf("Enter the number of items: ");
  scanf("%d", &n);

  printf("Enter the weights of the items: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &items[i].weight);
  }

  printf("Enter the values of the items: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &items[i].value);
  }

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  sortitems(items, n);
  double total = 0;
  int remaining = capacity;

  for (int i = 0; i < n && remaining > 0; i++)
  {
    if (items[i].weight <= remaining)
    {
      total += items[i].value;
      remaining -= items[i].weight;
      printf("Remaining space is %f \n", (float)remaining/capacity *100);
    }
    else
    {
      double fractional = (double)remaining / items[i].weight;
      total += fractional * items[i].value;
      printf("Taking %.2f%% of item %d\n", fractional * 100, i + 1);

      break;
    }
  }
  printf("Maximum value possible: %.2f\n", total);

  return 0;
}