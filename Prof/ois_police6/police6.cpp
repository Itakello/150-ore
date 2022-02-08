//https://training.olinfo.it/#/task/ois_police6/statement
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

int N;
ll M, L;
vector<ll> D;

int countInRange(ll pos) {
	auto low = lower_bound(D.begin(), D.end(), pos - M);
	auto up = upper_bound(D.begin(), D.end(), pos + M);
	int before = low - D.begin();
	int after = D.end() - up;
	return N - before - after;
	}

ll findMaxDist() {
	ll maxDist = 0;
	ll sPos;
	for (int i = 0; i < N - 1; i++) {
		maxDist = max(maxDist, D[i + 1] - D[i]);
		}
	if (D[0] != 0)
	}

// Inserirli come range
// Scannerizzarli in questo senso

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> L;
	D.resize(N);
	for (int i = 0; i < N; i++)
		cin >> D[i];

	// cout << countInRange(30) << endl;

	int maxDis = findMaxDist();

	return 0;
	}

