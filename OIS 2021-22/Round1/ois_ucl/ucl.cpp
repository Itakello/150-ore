// https://training.olinfo.it/#/task/ois_ucl/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

struct score {
	int win, draw, loss;
	int score;
	};

int T, N;
score teams[4];

bool checkValidity() {
	for (int i = 0; i < N - 1; i++) {
		if (teams[i].score < teams[i + 1].score)
			return false;
		if (teams[i].score == teams[i + 1].score && teams[i].win < teams[i + 1].win)
			return false;
		if (teams[i].win + teams[i].loss + teams[i].draw != (2 * (N - 1)))
			return false;
		}
	return true;
	int wins = 0, losses = 0, draws = 0, i = 0, j = N - 1;
	while (i <= j) {
		wins -= abs(teams[i].win - min(2, teams[j].loss)) - abs(teams[j].win - min(2, teams[i].loss));
		losses -= abs(teams[i].loss - min(2, teams[j].win)) - abs(teams[j].loss - min(2, teams[i].win));
		draws -= teams[i].draw + teams[j].draw - (min(min(teams[i].draw, teams[j].draw), 2) * 2);
		i++;
		j--;
		}
	return !(wins > 0 || draws > 0 || losses > 0);
	}

bool checkUniqueness() {
	int draws = 0;
	for (int i = 0; i < N - 2; i++)
		draws += teams[i].draw;
	if (draws > 0)
		return false;
	if (teams[N - 1].draw != teams[N - 2].draw)
		return false;
	if (teams[N - 1].draw != 0 && teams[N - 1].draw != 2)
		return false;
	if (teams[0].win != 0 && teams[0].win != (N - 1) * 2)
		return  false;
	return true;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T-- > 0) {
		cin >> N;
		int num;
		for (int i = 0; i < N; i++) {
			score s;
			cin >> num;
			s.loss = num % 10; num /= 10;
			s.draw = num % 10; num /= 10;
			s.win = num % 10; num /= 10;
			s.score = s.win * 3 + s.draw;
			teams[i] = s;
			}
		if (!checkValidity())
			cout << "Invalid" << endl;
		else if (checkUniqueness())
			cout << "Unique" << endl;
		else
			cout << "Not unique" << endl;
		}
	return 0;
	}