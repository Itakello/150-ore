//https://training.olinfo.it/#/task/viaggio/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MAX 100001

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

vii adj[MAX];
vi dist(MAX, INT32_MAX);
int n, m;

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push(MP(dist[start], start));
	while (!pq.empty()) {
		int u = pq.top().second,
			d = pq.top().first;
		pq.pop();
		// if (d > dist[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].F,
				w = adj[u][i].S;
			if (w + dist[u] < dist[v]) {
				dist[v] = w + dist[u];
				pq.push(MP(dist[v], v));
				}
			}
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		adj[a].push_back(MP(b, w));
		adj[b].push_back(MP(a, w));
		}
	dijkstra(1);
	cout << ((dist[n] == INT32_MAX) ? -1 : dist[n]) << endl;
	return 0;
	}