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
vector<pair<ll, ll>> ranges(MAXN);

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> l;
	ll tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		ranges[i] = { max((ll)0, tmp - m), min(tmp + m, l) };
		if (mp.find(ranges[i].first) == mp.end())
			mp[ranges[i].first] = { 0,0 };
		if (mp.find(ranges[i].second) == mp.end())
			mp[ranges[i].second] = { 0,0 };

		mp[ranges[i].first].second++;
		mp[ranges[i].second].first++;
		}

	for (int i = 0; i < n; i++) {
		auto start = mp.upper_bound(ranges[i].first);
		auto end = mp.lower_bound(ranges[i].second);
		for (;start != end; start++) {
			start->second.first++;
			start->second.second++;
			}
		}

	int min_val = INT_MAX;
	for (auto x : mp) {
		if (x.first == 0)
			min_val = min(min_val, x.second.second);
		else if (x.first == l)
			min_val = min(min_val, x.second.first);
		else {
			min_val = min(min_val, x.second.first);
			min_val = min(min_val, x.second.second);
			}
		}
	cout << min_val << endl;

	return 0;
	}