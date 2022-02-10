//https://training.olinfo.it/#/task/ois_martianwar/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int N, M, Q;
int x, y, dfsNumberCounter;
int bridges;
vector<vi> adj;
vi dfs_num, dfs_low, dfs_parent;

void findBridges(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (size_t i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		// cout << u << "->" << v << endl;
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			findBridges(v);

			if (dfs_low[v] > dfs_num[u]) {
				bridges++;
				// printf("Edge (%d, %d) is a bridge\n", u, v);
				}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			}
		else if (v != dfs_parent[u]) // back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> Q;

	adj.resize(N);

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
		}

	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
		bridges = 0;
		dfs_num.assign(N, -1);
		dfs_low.assign(N, 0);
		dfs_parent.assign(N, 0);
		dfsNumberCounter = 0;
		for (size_t i = 0; i < N; i++) {
			if (dfs_num[i] == -1) {
				findBridges(i);
				}
			}
		cout << bridges << endl; // print the result
		}
	return 0;
	}


