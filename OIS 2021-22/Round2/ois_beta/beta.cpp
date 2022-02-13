//https://training.olinfo.it/#/task/ois_beta/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int N;
map<int, int> mappa;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		mappa[temp]++;
		}
	int count = 0;
	for (auto x : mappa) {
		if (x.second > 1)
			count++;
		}
	if (count <= 1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
	}

