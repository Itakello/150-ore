///https://training.olinfo.it/#/task/ois_stocks/statement
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
vi V, S;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	V.resize(N);
	S.resize(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];
	for (int i = 0; i < N; i++)
		cin >> S[i];
	int best = 0;
	int temp = 0;
	if (S[0]) temp += V[0];
	best = max(temp, best);
	for (int i = 1; i < N; i++) {
		if (S[i]) {
			if (S[i - 1] && V[i - 1] > V[i])
				temp = V[i];
			else
				temp += V[i];
			best = max(temp, best);
			}
		else
			temp = 0;
		}
	cout << best << endl;
	return 0;
	}
