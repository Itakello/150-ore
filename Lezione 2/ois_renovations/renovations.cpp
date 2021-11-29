// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#define C 1000000007;

using namespace std;

long long int count(int range, int tot) {
	long long int res;
	if (tot > range) {
		res = 1;

		}
	for (int k = tot; k > ceil(tot / 2); k--) {
		int rim = tot - k;
		for (int y = 0; y < range; y++) {

			}
		}
	return res % C;
	}

// input data
int N, Q, K, type;
vector<int> V;

int main() {
	//  uncomment the following lines if you want to read/write from files
	ifstream cin("input.txt");
	//  ofstream cout("output.txt");

	cin >> N >> Q >> K;
	V.resize(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];

	for (int i = 0; i < Q; i++) {
		cin >> type;
		if (type == 1) {
			// building update
			int a, b;
			cin >> a >> b;
			V[a] = b;
			}
		if (type == 2) {
			// redevelopment planning
			int l, r, s;
			cin >> l >> r >> s;
			int tot = 0;
			int range = r - l + 1;
			vector<int> temp(range);
			for (int j = l; j <= r; j++) {
				temp[j] = (V[j] < K) ? K : V[j];
				tot += temp[j];
				}
			tot = s - tot;
			cout << count(range, tot) << endl; // print the result of the query
			}
		}
	return 0;
	}
