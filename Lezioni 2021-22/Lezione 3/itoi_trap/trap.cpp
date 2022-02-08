// https://training.olinfo.it/#/task/itoi_trap/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> um;
vector<string> strs;
int N, L;

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	int imp;
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		int M;
		cin >> M;
		set<string> ss;
		if (i == 0)
			imp = M;
		for (int j = 0; j < M; ++j) {
			string s;
			cin >> s;
			if (i == 0) {
				strs.push_back(s);
				if (um.find(s) == um.end()) {
					//cout << "OK" << endl;
					um.insert(make_pair(s, 0));
					}
				}
			else {
				if (um.find(s) != um.end()) {
					if (ss.find(s) == ss.end()) {
						ss.insert(s);
						um[s]++;
						}
					}
				}
			}
		}
	//cout << um.size() << endl;
/* 	for (auto& it : um) {
		cout << it.first << " " << it.second << endl;
		} */
	for (int i = 0; i < imp; i++) {
		cout << um[strs[i]] << " ";
		}
	return 0;
	}