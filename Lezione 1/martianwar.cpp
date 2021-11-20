// https://training.olinfo.it/#/task/ois_martianwar/statement

#include <bits/stdc++.h>

using namespace std;

class Graph {
	int V;
	list<int>* adj;
	public:
	Graph(int V);
	void addEdge(int v, int w);
	int find_riskyes();
	};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
	}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
	}

int Graph::find_riskyes() {
	int res = 0;
	vector<int> degree(V, 0);
	for (int u = 0; u < V; u++) {
		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
			degree[*itr]++;
		}
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (degree[i] == 1)
			q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
			if (--degree[*itr] == 1)
				q.push(*itr);
			}
		res++;
		}
	return res;
	}


int main() {
	freopen("input.txt", "r", stdin);

	int N, M, Q, x, y;
	cin >> N >> M >> Q;
	Graph g(N);

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		g.addEdge(--x, --y);
		}

	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		g.addEdge(--x, --y);
		cout << g.find_riskyes() << endl;
		}

	return 0;
	}
