// https://training.olinfo.it/#/task/ois_metro/submissions
#include <bits/stdc++.h>
using namespace std;

string forwardd, backward, obs;

int solve() {
	int count = 0;
	int pos = 0, index;
	string obs1, obs2;

	for (auto it : obs) {
		if (it == '<') {
			obs1.append("^");
			obs2.append("v");
			}
		else {
			obs1.append("v");
			obs2.append("^");
			}
		}

	while ((index = forwardd.find(obs1, pos)) != string::npos) {
		count++;
		pos = index + 1;
		}

	pos = 0;
	reverse(obs2.begin(), obs2.end());
	while ((index = backward.find(obs2, pos)) != string::npos) {
		count++;
		pos = index + 1;
		}
	return count;
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); } //
	int N, M;
	cin >> N >> forwardd >> backward >> M >> obs;
	cout << solve() << endl;
	return 0;
	}