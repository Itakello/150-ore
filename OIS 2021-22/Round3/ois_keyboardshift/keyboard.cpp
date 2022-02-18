//https://training.olinfo.it/#/task/ois_keyboardshift/statement
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

string tot = "qwertyuiopasdfghjklzxcvbnm";
map<char, char> mp;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 0; i < tot.size() - 1; i++) {
		mp[tot[i]] = tot[i + 1];
		}

	int n;
	cin >> n;
	char c;
	cin.get(c);
	for (int i = 0; i < n; i++) {
		cin.get(c);
		cout << mp[c];// << "|";
		}
	cout << endl;
	return 0;
	}