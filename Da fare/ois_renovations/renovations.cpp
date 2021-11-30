// https://training.olinfo.it/#/task/ois_renovations/statement
#include <bits/stdc++.h>

using namespace std;
#define C 1000000007;

using namespace std;

int count(int range, int tot) { // Quanti spazi e quanti devo metterne
	int res = 0;
	if (range < 0 || tot < 0)
		return res;
	if (range > 0)
		for (int i = 0; i <= tot; i++) {
			res += count(range - 1, tot - i) % C;
			}
	else if (range == 0 && tot == 0)
		return 1;
	return res % C;
	}

// input data
int N, Q, K, type;
vector<int> V;

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }

	cin >> N >> Q >> K;
	V.resize(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];

	for (int i = 0; i < Q; i++) {
		cin >> type;
		if (type == 1) {
			// building update
			int a, b;
			cin >> a >> b;
			V[a - 1] = b;
			}
		else {
			// redevelopment planning
			int l, r, s;
			cin >> l >> r >> s;
			int tot = 0;
			int range = r - l + 1;
			//cerr << l - 1 << "-" << r - 1 << " k:" << K << " s:" << s << endl;
			// print
			for (int o = 0; o < N; o++) {
				//cerr << V[o] << " ";
				}
			//cerr << endl;
			for (int j = l - 1; j < r; j++) {
				tot += (V[j] < K) ? K : V[j];
				}
			tot = s - tot;
			//cerr << "tot:" << tot << " range:" << range << endl;
			cout << count(range, tot) << endl; // print the result of the query
			}
		}
	return 0;
	}
