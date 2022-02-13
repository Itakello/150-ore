//https://training.olinfo.it/#/task/ois_christmasballs/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

struct node {
	int color = -1, max_freq = 0, num_color = 1;
	};

vector<vi> adj(MAXN);
vector<node> I(MAXN);
unordered_map<int, int> arr_um[MAXN];
int ris = 0;

void dfs(int nodo) {
	int ma = nodo;
	for (int x : adj[nodo]) {
		dfs(x);
		if (arr_um[x].size() > arr_um[ma].size()) // prendo quello con più colori diversi
			ma = x;
		}
	swap(arr_um[ma], arr_um[nodo]);
	I[nodo].max_freq = I[ma].max_freq;
	I[nodo].num_color = I[ma].num_color;
	for (int x : adj[nodo]) {
		if (x == ma)continue;
		for (auto k : arr_um[x]) {
			arr_um[nodo][k.first] += k.second;
			if (arr_um[nodo][k.first] > I[nodo].max_freq) {
				I[nodo].max_freq = arr_um[nodo][k.first];
				I[nodo].num_color = 1;
				}
			else if (arr_um[nodo][k.first] == I[nodo].max_freq) {
				I[nodo].num_color++;
				}
			}
		}
	arr_um[nodo][I[nodo].color]++;
	if (arr_um[nodo][I[nodo].color] > I[nodo].max_freq) {
		I[nodo].max_freq = arr_um[nodo][I[nodo].color];
		I[nodo].num_color = 1;
		}
	else if (arr_um[nodo][I[nodo].color] == I[nodo].max_freq) {
		I[nodo].num_color++;
		}
	// cout << nodo << " " << I[nodo].max_freq << " " << I[nodo].num_color << endl;
	ris = max(ris, I[nodo].num_color);
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node n;
		cin >> n.color;
		I[i] = n;
		}
	for (int i = 1; i < n; i++) {
		int tmp;
		cin >> tmp;
		adj[tmp].push_back(i);
		}

	dfs(0);
	cout << ris << endl;

	return 0;
	}
