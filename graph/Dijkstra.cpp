#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 1e5 + 5;
vector<vector<pair<int, int>>> graph;
int dis[maxn];
int vis[maxn];
struct cmp
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second < p2.second;
    }
};

void dij(int n, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    dis[start] = 0;
    pq.push(make_pair(start, 0));
    while (!pq.empty())
    {
        pair<int, int> u = pq.top();
        pq.pop();
        if (vis[u.first])
        {
            continue;
        }
        int from = u.first, cost = u.second;
        dis[from] = cost;
        for (int i = 0; i < graph[from].size(); i++)
        {
            pq.push(make_pair(graph[from][i].first, graph[from][i].second + dis[from]));
        }
        vis[start] = 1;
    }
}

void slowDij(int n, int start)
{
    dis[start] = 0;
    for (int i = 0; i < n; i++)
    {
        int k = 0x3f3f3f3f;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && (k > 10000 || dis[j] < dis[k]))
            {
                k = j;
            }
        }
        for (int j = 0; j < graph[k].size(); j++)
        {
            if (!vis[graph[k][j].first] && dis[k] + graph[k][j].second < dis[graph[k][j].first])
            {
                dis[graph[k][j].first] = dis[k] + graph[k][j].second;
            }
        }
        vis[k] = 1;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        graph.push_back(vector<pair<int, int>>());
        vis[i] = 0;
        dis[i] = 0x3f3f3f3f;
    }
    int from, to, cost;
    while (cin >> from >> to >> cost)
    {
        graph[from].push_back(make_pair(to, cost));
    }
    slowDij(n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << ends;
    }
    cout << endl;
}