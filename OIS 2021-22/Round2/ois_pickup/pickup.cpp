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
ll k;

ll findFirst(int rim) {
	ll val = 0;
	int digits = ceil((double)rim / 9);
	for (int i = digits - 1; i >= 0; i--) {
		int digit = rim - (9 * i);
		rim -= digit;
		val += digit * pow(10, i);
		}
	return val;
	}

ll findNext(ll n) {
	ll val = 0;
	vi r1, r2, r3, r4;
	while (n % 10 == 0) {
		r1.push_back(0);
		n /= 10;
		}

	r2.push_back(n % 10);
	n /= 10;

	while (n % 10 == 9 && n > 0) {
		r3.push_back(9);
		n /= 10;
		}
	while (n > 0) {
		r4.push_back(n % 10);
		n /= 10;
		}
	r4.push_back(0);
	// cout << r1.size() << " " << r2.size() << " " << r3.size() << " " << r4.size() << endl;
	if (!r4.empty())r4[0]++;
	reverse(r4.end(), r4.begin());
	r2[0]--;
	reverse(r3.end(), r3.begin());

	r3.insert(r3.end(), r2.begin(), r2.end());
	r3.insert(r3.end(), r1.begin(), r1.end());
	r3.insert(r3.end(), r4.begin(), r4.end());

	// cout << "r3 size: " << r3.size() << endl;

	for (int i = r3.size() - 1; i >= 0; i--) {
		val += r3[i] * pow(10, i);
		}
	return val;
	}

bool checkNum(ll n) {
	if (n % a != 0)
		return false;
	while (n > 0) {
		if (n % 10 == 0)
			return false;
		n /= 10;
		}
	return true;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> k;
	// cout << a << " " << b << " " << k << endl;
	ll val = findFirst(b);
	if (checkNum(val)) {
		// cout << val << endl;
		k--;
		}
	while (k) {
		val = findNext(val);
		if (checkNum(val)) {
			// cout << val << endl;
			k--;
			}
		}
	cout << val << endl;
	return 0;
	}
