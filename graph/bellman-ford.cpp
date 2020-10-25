#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;

const int inf = 0x3f3f3f3f;

int dist[maxn];

vector<vector<int>> graph(maxn, vector<int>(maxn));

bool bellman_ford(int n){
	dist[1] = 0;
	for(int k = 1; k < n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				/*
				 * relax:
				 *		if v.d > u.d + w(u, v)
				 *			v.d = u.d + w(u, v)
				 */
				if(graph[i][j] < inf){
					if(dist[j] > graph[i][j] + dist[i]){
						dist[j] = graph[i][j] + dist[i];
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(graph[i][j] < inf){
				if(dist[j] > graph[i][j] + dist[i]){
					cout << "negative weight cycle detacted" << endl;
					return true;
				}
			}
		}
	}
	return false;
} 

int main(){
	memset(dist, 0x3f, sizeof(dist));
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			graph[i][j] = i == j ? 0 : inf;
		}
	}
	while(m-- > 0){
		int x, y, w;
		cin >> x >> y >> w;
		graph[x][y] = min(graph[x][y], w);
	}
	bellman_ford(n);
	for(int i = 2; i <= n; i++){
		cout << "min dist from 1 to " << i << ": " << dist[i] << endl;
	}
	return 0;
}
