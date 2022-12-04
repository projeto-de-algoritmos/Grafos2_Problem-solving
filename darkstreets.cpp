#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct
{
  int origin;
  int destiny;
  int Weight;
} edge;

bool pay(edge A, edge B)
{
  return (A.Weight < B.Weight);
}

int cycleCheck(int p[], int origin, int destiny)
{
  while (p[origin] > -1)
  {
    origin = p[origin];
  }

  while (p[destiny] > -1)
  {
    destiny = p[destiny];
  }

  if (origin != destiny)
  {
    p[destiny] = origin;

    return 1;
  }

  return 0;
}

int main()
{
  int vertixAmount, edgeAmount;

  int p[200000];
  edge edges[200000];

  while (cin >> vertixAmount >> edgeAmount)
  {
    if (vertixAmount == 0 and edgeAmount == 0)
    {
      return 0;
    }

    int cost = 0, allCost = 0;

    for (int i = 0; i < vertixAmount; i++)
    {
      p[i] = -1;
    }

    for (int i = 0; i < edgeAmount; i++)
    {
      cin >> edges[i].origin >> edges[i].destiny >> edges[i].Weight;
      allCost += edges[i].Weight;
    }

    sort(edges, edges + edgeAmount, pay);

    int i = 0;
    int j = 1;

    while (j < vertixAmount and i < edgeAmount)
    {
      if (cycleCheck(p, edges[i].origin, edges[i].destiny))
      {
        j++;
        cost = cost + edges[i].Weight;
      }

      i++;
    }

    cout << allCost - cost << endl;
  }

  return 0;
}