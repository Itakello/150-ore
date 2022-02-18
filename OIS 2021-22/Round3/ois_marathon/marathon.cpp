//https://training.olinfo.it/#/task/ois_marathon/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 250005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int n, q;
vector<vi> adj(MAXN);

struct treeNode {
	int par,
		depth,
		size,
		pos_segbase,
		chain;
	}
node[MAXN];

struct edge {
	int weight,
		deeper_end;
	}
edge[MAXN];

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	int type, x, y, sum = 0;
	bool running;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		adj[x].push_back({ y,0 });
		adj[y].push_back({ x,0 });
		}
	while (q--) {
		cin >> type >> x >> y;
		if (type == 1) {

			}
		else {

			}
		}

	return 0;
	}