//https://training.olinfo.it/#/task/ois_pickup/statement
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

int a, b;
ll k, ret = 0;

ll foo(int digits, int target) {
	if (digits == 1) {
		if (target >= 1 && target <= 9)
			return 1;
		else
			return 0;
		}
	ll ret = 0;
	for (int i = 1; i < 10; i++) {
		ret += foo(digits - 1, target - i);
		}
	return ret;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> k;
	int i = 1;
	while (ret < k) {
		ret += foo(i++, b);
		}
	}