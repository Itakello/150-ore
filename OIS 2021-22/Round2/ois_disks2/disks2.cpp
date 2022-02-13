//https://training.olinfo.it/#/task/ois_disks2/statement
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

int n, t;
vi A, B;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> t;
	A.resize(n);
	B.resize(n);
	for (size_t i = 0; i < n; i++) {
		// cout << "OK" << endl;
		cin >> A[i] >> B[i];
		}
	bool ok = true;
	for (size_t i = 0; i < n - 1; i++) {
		int val = (24 - B[i]) + A[i + 1];
		// cout << val << endl;
		if (val >= t) {
			ok = false;
			cout << i << endl;
			break;
			}
		}
	if (ok) cout << -1 << endl;
	return 0;
	}