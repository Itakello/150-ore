//https://training.olinfo.it/#/task/ois_kalindrome/statement
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

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for (size_t k = 1; k <= n; k++) {
		if (n % k != 0)continue;
		int ind1 = 0, ind2 = n - k;
		bool ok = true;
		while (ind1 < n) {
			for (size_t i = 0; i < k; i++) {
				if (s[ind1 + i] != s[ind2 + i]) {
					ok = false;
					break;
					}
				}
			ind1 += k;
			ind2 -= k;
			}
		if (ok) {
			cout << k << endl;
			break;
			}
		}

	return 0;
	}