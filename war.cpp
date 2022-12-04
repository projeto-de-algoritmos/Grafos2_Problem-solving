#include <iostream>
#include <cstdio>
#define MAX 999999999
#define max 501

using namespace std;

int g[max][max], vert;

int dijkstra(int origin, int destiny)
{
  int minimum, action;
  int pass[max], pred[max], cost[max];
  for (int i = 1; i <= vert; i++)
  {
    pred[i] = -1;
    cost[i] = MAX;
    pass[i] = 0;
  }
  cost[origin] = 0;
  action = origin;
  while (action != destiny)
  {
    for (int i = 1; i <= vert; i++)
    {
      if (cost[i] > cost[action] + g[action][i])
      {
        cost[i] = cost[action] + g[action][i];
      }
    }
    minimum = MAX;
    pass[action] = 1;
    for (int i = 1; i <= vert; i++)
    {
      if ((cost[i] < minimum) && (!pass[i]))
      {
        minimum = cost[i];
        action = i;
      }
    }
    if (minimum == MAX)
    {
      return MAX;
    }
  }
  return cost[destiny];
}

int main()
{

  int i, j, edges, origin, destiny, weight, queries;
  cin >> vert >> edges;
  while (vert != 0 || edges != 0)
  {

    for (int i = 1; i <= vert; i++)
    {
      for (int j = 1; j <= vert; j++)
      {
        g[i][j] = MAX;
      }
    }
    for (i = 1; i <= edges; i++)
    {
      cin >> origin >> destiny >> weight;
      g[origin][destiny] = weight;
      if (g[destiny][origin] != MAX)
      {
        g[origin][destiny] = 0;
        g[destiny][origin] = 0;
      }
    }
    cin >> queries;
    for (int i = 1; i <= queries; i++)
    {
      cin >> origin >> destiny;

      if (dijkstra(origin, destiny) == MAX)
      {
        cout << "Unable to deliver the letter\n";
      }
      else
      {
        cout << dijkstra(origin, destiny) << endl;
      }
    }
    cin >> vert >> edges;
    cout << endl;
  }
  return 0;
}