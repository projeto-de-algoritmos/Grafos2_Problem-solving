#include <iostream>
#include <cstdio>
#define Vertex int
#define maxV 10000

using namespace std;

int cnt, lbl[maxV];
int V, A, adj[25][25];
string spaces = "";
int entry = 0;

void pathR(Vertex v, string spaces)
{
  Vertex w;
  lbl[v] = cnt++;
  spaces = spaces + "  ";
  for (w = 0; w < V; w++)
  {
    if (adj[v][w] == 1)
    {
      entry = 1;
      cout << spaces << v << "-" << w;
      if (lbl[w] == -1)
      { // se nao percorreu ainda
        cout << " pathR(G," << w << ")" << endl;
        pathR(w, spaces);
      }
      else
      {
        cout << endl;
        ;
      }
    }
  }
}

int DIAGRAPHpath(void)
{
  Vertex v;
  for (v = 0; v < V; v++)
  {
    lbl[v] = -1;
  }

  cnt = 0;
  for (v = 0; v < V; v++)
  {
    if (lbl[v] == -1)
    {
      entry = false;
      pathR(v, spaces);
      if (entry)
        cout << endl;
    }
  }
}

int main()
{
  int orig, dest;
  int cases;
  cin >> cases;

  for (int u = 1; u <= cases; u++)
  {
    cin >> V;

    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        adj[i][j] = 0;
      }
    }
    cin >> A;
    for (int i = 0; i < A; i++)
    {
      cin >> orig >> dest;
      adj[orig][dest] = 1;
    }
    cout << "Caso " << u << ":" << endl;
    DIAGRAPHpath();
  }
  return 0;
}