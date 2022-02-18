#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef long long ll;
int main() {
	int n;
	ll m, l;
	cin >> n >> m >> l;
	map<ll, int>mappa;
	mappa[0] = 0;
	mappa[l] = 0;
	for (int i = 0;i < n;i++) {
		ll tmp;
		cin >> tmp;
		mappa[tmp - m]++;
		mappa[tmp + m + 1]--;
		}
	int conta = 0;
	int ris = 1e9;

	for (auto x : mappa) {
		conta += x.second;
		if (x.first >= 0 && x.first <= l) {
			ris = min(ris, conta);
			}
		}
	cout << ris << endl;
	}