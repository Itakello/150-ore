//https://training.olinfo.it/#/task/ois_tractor/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXSIZE 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int N, K;
vector<vii> adj;
vector<bool> visited;
vi final_path;
int final_res = INT_MAX;

int firstMin(int u) {
	return (*min_element(adj[u].begin(), adj[u].end())).second;
	}

void TSPRec(int curr_bound, int curr_weight, int level, vi curr_path) {
	if (level == N && curr_weight < final_res) {
		cout << "New path :";
		for (int i = 0; i < curr_path.size(); i++) {
			cout << curr_path[i] << " ";
			}
		cout << endl;
		final_path.assign(curr_path.begin(), curr_path.end());
		final_res = curr_weight;
		return;
		}
	int u = curr_path[level - 1];
	ii v;
	for (size_t i = 0; i < adj[u].size(); i++) {
		if (!visited[i]) {
			v = adj[u][i];
			int temp = curr_bound;
			curr_weight += v.second;
			if (level == 1)
				curr_bound -= (firstMin(u) + firstMin(v.first)) / 2;
			else
				curr_bound -= (firstMin(u) + 1 + firstMin(v.first)) / 2;
			if (curr_bound + curr_weight < final_res) {
				curr_path[level] = v.first;
				visited[v.first] = true;
				TSPRec(curr_bound, curr_weight, level + 1, curr_path);
				}
			// cout << "ok" << endl;
			curr_weight -= v.second;
			curr_bound = temp;
			fill(visited.begin() + (level - 1), visited.end(), 0);
			fill(visited.begin(), visited.begin() + (level - 1), 1);
			}
		}
	}

void TSP(int start) {
	int curr_bound = 0;
	vi curr_path(N);
	visited.resize(N);
	final_path.resize(N);
	fill(curr_path.begin(), curr_path.end(), -1);
	fill(visited.begin(), visited.end(), 0);

	for (size_t i = 0; i < N; i++) {
		curr_bound += (firstMin(i) * 2 + 1); // the second should be secondMin
		}
	curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 :
		curr_bound / 2;

	visited[start] = true;
	curr_path[start] = 0;

	cout << curr_bound << " " << curr_path[0] << endl;

	// TSPRec(curr_bound, 0, 1, curr_path);
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;

	adj.resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (abs(i - j) >= K) {
				cout << i << "-" << j << endl;
				adj[i].push_back(make_pair(j, abs(i - j)));
				}
			}
		}

	TSP(0);

	cout << final_res << " " << N << endl;
	for (int i = 0; i < N; i++) {
		cout << final_path[i] << " ";
		}
	cout << endl;

	return 0;
	}