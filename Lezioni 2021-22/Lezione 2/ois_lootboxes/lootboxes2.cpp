// https://training.olinfo.it/#/task/ois_lootboxes/statement
#include <bits/stdc++.h>

using namespace std;
// constraints
#define MAXN 5000
#define MAXX 10000

// input data
int N, X, i;
int P[MAXN], Q[MAXN];
int r[MAXX + 1], oldR[MAXX + 1];

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }

	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> P[i] >> Q[i];
		}

	for (int i = 0;i < N;++i) {
		for (int k = 0; k < Q[i] - 1; k++) {
			cerr << "\t";
			}
		for (int j = Q[i];j <= X;++j) {
			cerr << oldR[j];
			if (P[i] + oldR[j - Q[i]] > r[j]) {
				r[j] = P[i] + oldR[j - Q[i]];
				cerr << "|" << r[j];
				}
			cerr << "\t";
			}
		cerr << "\n";
		for (int j = Q[i];j <= X;++j) // Copy of r in oldR
			oldR[j] = r[j];
		}


	cout << r[X] << endl;

	return 0;
	}
