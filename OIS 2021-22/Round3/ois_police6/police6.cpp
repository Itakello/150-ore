//https://training.olinfo.it/#/task/ois_police6/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int n;
ll m, l;
map<ll, ii> mp;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> l;
	ll tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		pair<ll, ll> p = { max((ll)0, tmp - m), min(tmp + m, l) };
		cout << "---" << p.first << "-" << p.second << "---" << endl;
		if (auto s = mp.find(p.first) == mp.end()) {
			mp[p.first] = { 0,0 };
			cout << "New start" << endl;
			}
		if (auto s = mp.find(p.second) == mp.end()) {
			mp[p.second] = { 0,0 };
			cout << "New end" << endl;
			}
		mp[p.first].second++;
		mp[p.second].first++;

		auto start = mp.upper_bound(p.first);
		auto end = mp.lower_bound(p.second);
		for_each(start++, end--, [](auto& v) {
			cout << "UP " << v.first << endl;
			v.second.first++;
			v.second.second++;
			});
		}

	for (auto x : mp) {
		cout << x.first << " : " << x.second.first << "," << x.second.second << endl;
		}

	return 0;
	}