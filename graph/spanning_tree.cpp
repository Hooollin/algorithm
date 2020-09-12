#include <bits/stdc++.h>
using namespace std;

/* psudo code
 *
 * A = {}
 * while A does not form a spanning tree
 *	find an edge<u, v> that is safe for A
 *  A = A U <u, v>
 * return A
 *
*/

struct cmp{
	bool operator()(vector<int> &a, vector<int> &b){
		return a[2] > b[2];
	}
};

const int maxn = 1e5 + 5;
const int inf = 1e9 + 3;

int p[maxn];
set<pair<int, int>> edges;


int find(int x){
	if(x == p[x]){
		return x;
	}
	return p[x] = find(p[x]);
}


bool uni(int x, int y){
	x = find(x), y = find(y);
	if(x == y){
		return false;
	}
	p[x] = y;
	return true;
}

void spanning_tree(int n, vector<vector<pair<int, int>>>& graph){
	for(int i = 1; i <= n; i++){
		p[i] = i;
	}
	priority_queue<vector<int>, vector<vector<int>>, cmp> q;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < graph[i].size(); j++){
			int x = i, y = graph[i][j].first, w = graph[i][j].second;
			if(x != y){
				vector<int> v;
				v.push_back(x);
				v.push_back(y);
				v.push_back(w);
				q.push(v);
			}
		}
	}
	while(!q.empty()){
		vector<int> now = q.top(); q.pop();
		int x = now[0], y = now[1], w = now[2];
		cout << w << endl;
		if(uni(x, y)){
			edges.insert({x, y});
		}
	}
}



int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
	while(m-- > 0){
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back({y, w});
		graph[y].push_back({x, w});
	}
	spanning_tree(n, graph);
	for(auto p : edges){
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}
