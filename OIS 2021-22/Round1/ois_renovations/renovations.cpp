// https://training.olinfo.it/#/task/ois_renovations/statement
// https://forum.olinfo.it/t/city-redevelopment-renovations/6805/2
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007;

using namespace std;

// input data
int N, Q, K, type;
vector<int> V;

int binomialCoeff(int n, int k) {
	// Base Cases
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	// Recur
	return binomialCoeff(n - 1, k - 1)
		+ binomialCoeff(n - 1, k) % mod;
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }

	cin >> N >> Q >> K;
	V.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
		V[i] = max(V[i], K);
		}

	for (int i = 0; i < Q; i++) {
		cin >> type;
		if (type == 1) {
			// building update
			int a, b;
			cin >> a >> b;
			V[a] = max(b, K);
			}
		else {
			// redevelopment planning
			int l, r, s;
			cin >> l >> r >> s;
			for (int j = 0; j <= r; j++) {
				s -= V[j];
				}
			cout << "s:" << s << endl;
			if (s < 0)
				cout << "s<0: " << 0 << endl;
			else if (s == 0 || l == r)
				cout << "s == 0 || l == r: " << 1 << endl;
			else if ((r - 1) == 1)
				cout << "(r - 1) == 1: " << s + 1 << endl;
			else if (s == 1)
				cout << "s == 1: " << r - l + 1 << endl;
			else
				cout << "ok " << binomialCoeff(s + (r - l) - 1, s) << endl;
			}
		}
	return 0;
	}
