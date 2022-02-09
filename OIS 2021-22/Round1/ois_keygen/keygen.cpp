// https://training.olinfo.it/#/task/ois_keygen/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

void solve() {
	int K;
	string s;
	cin >> K >> s;
	vector<vector<short>>ar;
	vector<short>supp;
	for (int i = 0;i < (int)s.size();i++) {

		if (s[i] == '(' || s[i] == '^' || s[i] == '&')continue;
		if (s[i] == '!') {
			i++;
			supp.push_back(-(s[i] - 'a' + 1));
			}
		else if (s[i] == ')') {
			ar.push_back(supp);
			supp.clear();
			}
		else {
			supp.push_back(s[i] - 'a' + 1);
			}
		}

	// Stampa riga + valori
	/* cout << s << " : ";
	for (auto t : ar) {
		cout << "[";
		for (auto t1 : t) {
			cout << t1 << " ";
			}
		cout << "]";
		}
	cout << endl; */

	int riss = 0;
	for (int i = 0;i < (1 << K);i++) {
		bool ris;
		// cout << i << ": ";
		for (int j = 0;j < (int)ar.size();j++) {
			bool ok = true;
			for (short x : ar[j]) {
				if (x > 0) {
					if (!(i & (1 << (x - 1)))) {
						ok = false;
						break;
						}
					}
				else {
					if (i & (1 << (-x - 1))) {
						ok = false;
						break;
						}
					}
				}
			// cout << (ok ? "T" : "F") << "\t";
			if (j == 0)ris = ok;
			else ris ^= ok;
			}
		// cout << endl;
		if (ris)riss++;
		}

	cout << riss << endl;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
		}
	return 0;
	}