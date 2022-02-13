//https://training.olinfo.it/#/task/ois_police5/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 10005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

struct info {
	int to, weight, bomb;
	};

int N, M, T;
vi dist(MAXN, INT_MAX);
vector<vector<info>> adj(MAXN);

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push(make_pair(dist[start], start));
	while (!pq.empty()) {
		int u = pq.top().second,
			d = pq.top().first;
		pq.pop();
		if (d > dist[u]) continue;
		for (auto x : adj[u]) {
			int new_dist = dist[u] + x.weight;
			if (!x.bomb || new_dist <= T) {
				if (new_dist < dist[x.to]) {
					dist[x.to] = new_dist;
					pq.push({ dist[x.to], x.to });
					}
				}
			}
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> T;

	info e;
	int a;
	for (int i = 0; i < M; i++) {
		cin >> a >> e.to >> e.weight >> e.bomb;
		adj[a].push_back(e);
		}

	dijkstra(0);

	if (dist[N - 1] == INT_MAX)
		cout << -1 << endl;
	else
		cout << dist[N - 1] << endl;
	return 0;
	}
