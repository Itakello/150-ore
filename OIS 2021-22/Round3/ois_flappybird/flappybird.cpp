//https://training.olinfo.it/#/task/ois_flappybird/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 10005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	ll a = 0, b = LONG_LONG_MAX, c, d;
	bool ok = true;
	while (n--) {
		cin >> c >> d;
		if ((c <= a && d >= a) || (c <= b && d >= b) || (c >= a && d <= b)) {
			}
		else {
			ok = false;
			break;
			}
		swap(a, c);
		swap(b, d);
		}
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
	}