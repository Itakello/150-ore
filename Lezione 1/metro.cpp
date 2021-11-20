// https://training.olinfo.it/#/task/ois_metro/submissions

#include <iostream>
#include <assert.h>
#include <string>
#include <algorithm>
using namespace std;

string forwardd, backward, obs;

int solve(int N, int M) {
	int count = 0;
	int pos = 0, index;

	replace(obs.begin(), obs.end(), '<', '^');
	replace(obs.begin(), obs.end(), '>', 'v');
	while ((index = forwardd.find(obs, pos)) != string::npos) {
		count++;
		pos = index + 1;
		}
	//cerr << "count:" << count << endl;
	pos = 0;
	replace(obs.begin(), obs.end(), '^', '|');
	replace(obs.begin(), obs.end(), 'v', '^');
	replace(obs.begin(), obs.end(), '|', 'v');
	reverse(obs.begin(), obs.end());

	cerr << "obs:" << obs << endl;
	cerr << "back:" << backward << endl;

	while ((index = backward.find(obs, pos)) != string::npos) {
		count++;
		pos = index + 1;
		}
	return count;
	}

int main() {
	int N, M;
	cin >> N >> forwardd >> backward >> M >> obs;

	cout << solve(N, M) << endl;
	return 0;
	}
