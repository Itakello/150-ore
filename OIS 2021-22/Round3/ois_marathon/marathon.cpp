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

vi parent(MAXN), depth(MAXN), heavy(MAXN, -1), head(MAXN), pos(MAXN), Size(MAXN);
vi ar(MAXN), st(4 * MAXN); //segment tree
int cur_pos = 0;

// TODO : Test rimuovere ar

// Definisce depth e parent di ogni nodo (tramite size) e i vari heavy paths
void dfs(int nodo, int p, int h) {
	depth[nodo] = h;
	parent[nodo] = p;
	Size[nodo] = 1;
	int val = 0;
	for (int x : adj[nodo]) {
		if (x != p) { // nodo corrente non è il figlio del nodo visitato
			dfs(x, nodo, h + 1);
			Size[nodo] += Size[x];
			if (Size[x] > val) {
				val = Size[x];
				heavy[nodo] = x;
				}
			}
		}
	}

// Definisce head (head of the heavy path) e pos (position on the single segment tree) di ogni nodo
void decompose(int nodo, int h) {
	head[nodo] = h;
	// ar[cur_pos] = 0;
	pos[nodo] = cur_pos++;
	if (heavy[nodo] != -1) // imposta tutto l'heavy path
		decompose(heavy[nodo], h);
	for (int x : adj[nodo]) { // imposta gli altri paths
		if (x != parent[nodo] && x != heavy[nodo])
			decompose(x, x);
		}
	}

void update(int i, int l, int r, int poss) {
	if (l == r) {
		st[i] = 1 - st[i];
		// ar[l] = 1 - ar[l];
		return;
		}
	int mid = (l + r) / 2;
	if (poss <= mid)
		update(i * 2 + 1, l, mid, poss);
	else
		update(i * 2 + 2, mid + 1, r, poss);
	st[i] = st[i * 2 + 1] + st[i * 2 + 2];
	}

int get_max(int i, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr)
		return st[i];
	if (l > qr || r < ql)
		return 0;
	int mid = (l + r) / 2;
	return get_max(i * 2 + 1, l, mid, ql, qr) +
		get_max(i * 2 + 2, mid + 1, r, ql, qr);
	}

int query(int a, int b) {
	int ris = 0;
	for (; head[a] != head[b]; b = parent[head[b]]) { // Scorro fino a farli trovare nello stesso path
		if (depth[head[a]] > depth[head[b]])
			swap(a, b);
		ris = ris + get_max(0, 0, n - 1, pos[head[b]], pos[b]);
		}
	if (pos[a] > pos[b])
		swap(a, b);
	ris = ris + get_max(0, 0, n - 1, pos[a] + 1, pos[b]);
	return ris;
	}

// Query for maximum on a path
/* int query2(int a, int b) {
	int res = 0;
	for (; head[a] != head[b]; b = parent[head[b]]) {
		if (depth[head[a]] > depth[head[b]])
			swap(a, b);
		int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
		res = max(res, cur_heavy_path_max);
		}
	if (depth[a] > depth[b])
		swap(a, b);
	int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
	res = max(res, last_heavy_path_max);
	return res;
	} */

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	int type, x, y, sum = 0;

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		}

	dfs(1, 1, 0);
	decompose(1, 1);

	while (q--) {
		cin >> type >> x >> y;
		if (type == 1) {
			if (parent[x] == y)
				update(0, 0, n - 1, pos[x]);
			else
				update(0, 0, n - 1, pos[y]);
			}
		else {
			x = (x + sum) % n + 1;
			y = (y + sum) % n + 1;
			int tmp = query(x, y);
			if (tmp == 0) {
				sum++;
				cout << 1 << endl;
				}
			else
				cout << 0 << endl;
			}
		}
	return 0;
	}