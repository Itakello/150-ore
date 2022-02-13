#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	//  uncomment the following lines if you want to read/write from files
	//  ifstream cin("input.txt");
	//  ofstream cout("output.txt");

	int N;
	ll K;
	cin >> N >> K;

	vector<int> V(N);
	for (int& v : V) {
		cin >> v;
		}

	auto check = [&](ll x) {
		ll c = 0;
		ll s = 0;
		for (int i = 0, j = 0; i < N; i++) {
			while (j < N && s + V[j] <= x) {
				s += V[j++];
				}
			c += (j - i);
			s -= V[i];
			}
		return c;
		};

	ll l = 0, r = 1e18;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (check(m) < K) {
			l = m;
			}
		else {
			r = m;
			}
		}

	ll c = check(l);
	ll s = 0;
	for (int i = 0, j = 0; i < N; i++) {
		while (j < N && s + V[j] < r) {
			s += V[j++];
			}
		if (j < N && s + V[j] == r) {
			if (++c == K) {
				cout << i << ' ' << j << endl;
				break;
				}
			s += V[j++];
			}
		s -= V[i];
		}

	return 0;
	}
