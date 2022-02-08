// https://training.olinfo.it/#/task/ois_lootboxes/statement
#include <bits/stdc++.h>
using namespace std;

struct LootB {
	int prob;
	int cost;
	};

struct CompareLootB {
	bool operator()(const LootB& a, const LootB& b) {
		return (a.prob / a.cost) < (b.prob / b.cost);
		};
	};


int main(int argc, char** argv) {
	priority_queue<LootB, vector<LootB>, CompareLootB> prob;
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }  // usage: a.out <input_file>

	int N, X, t1, t2, maxN = 0;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		LootB tmp;
		cin >> tmp.prob >> tmp.cost;
		prob.push(tmp);
		}

	//cout << X << endl;
	while (X > 0) {
		//cout << prob.top().prob << "-" << prob.top().cost << endl;
		if (X - prob.top().cost >= 0) {
			maxN += prob.top().prob;
			X -= prob.top().cost;
			}
		prob.pop();
		}

	cout << maxN << endl;
	return 0;
	}