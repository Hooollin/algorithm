#include <iostream>

using namespace std;

const int maxn = 1e4 + 5;
int dis[maxn];
int graph[maxn][maxn];

void floyd(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int from, to, cost;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
            }
            else
                graph[i][j] = 0x3f3f3f3f;
        }
    }
    while (cin >> from >> to >> cost)
    {
        graph[from][to] = cost;
        graph[to][from] = cost;
    }
    floyd(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << ends;
        }
        cout << endl;
    }
    return 0;
}