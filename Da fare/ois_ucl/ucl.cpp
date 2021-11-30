// https://training.olinfo.it/#/task/ois_ucl/statement

#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// input data
int N, T;
vector<int> V;
vector<int> scores;
vector<int> wins;
vector<int> draws;
vector<int> losses;
vector<int> _scores;
vector<int> _wins;
vector<int> _draws;
vector<int> _losses;

bool checkScores() {
	for (int z = 0; z < N - 1; z++) {
		if (scores[z] < scores[z + 1])
			return false;
		}
	return true;
	}

bool checkWLD() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != i) {
				for (int k = 0; k < 2; k++) {
					if (_wins[i] > 0 && _losses[j] > 0) {
						//cerr << "W";
						_wins[i]--;
						_losses[j]--;
						}
					if (_losses[i] > 0 && _wins[j] > 0) {
						//cerr << "L";
						_losses[i]--;
						_wins[j]--;
						}
					if (_draws[i] > 0 && _draws[j] > 0) {
						//cerr << "D";
						_draws[i]--;
						_draws[j]--;
						}
					}
				}
			}
		}
	/* cerr << endl;
	for (int p = 0; p < N; p++)
		cerr << "w:" << wins[p] << " d:" << draws[p] << " l:" << losses[p] << " s:" << scores[p] << endl;
	} */
	for (int i = 0; i < N; i++)
		if (_losses[i] != 0 || _wins[i] != 0 || _draws[i] != 0)
			return false;
	return true;
	}

bool unique() {
	int i = 0, j = N, rim = j - i - 1;
	while (i < j) {
		if (wins[i] == rim * 2) {
			for (int k = i + 1; k < j; k++) {
				losses[k] -= 2;
				}
			i++;
			}
		else if (draws[i] == rim * 2) {
			for (int k = i + 1; k < j; k++) {
				draws[k] -= 2;
				}
			i++;
			}
		else if (losses[j] == rim * 2) {
			for (int k = i; k < j - 1; k++) {
				wins[k] -= 2;
				}
			j--;
			}
		else
			return false;
		rim = j - i - 1;
		}
	return true;
	{

	}
	if (losses[j] == rim * 2) {
		for (int k = i; k < j - 1; k++) {
			wins[k] -= 2;
			}
		}
	}

int main() {
	// Giocano gli uni contro gli altri 2 volte
	// Possono esserci degli errori nei dati
	// Prima cifra : (V[i]/100)%10
	ifstream cin("input.txt");

	cin >> T;
	for (int t = 0; t < T; t++) {
		V.clear();
		cin >> N;
		V.resize(N);
		wins.resize(N);
		losses.resize(N);
		draws.resize(N);
		scores.resize(N);
		_wins.resize(N);
		_losses.resize(N);
		_draws.resize(N);
		_scores.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> V[i];
			}

		for (int p = 0; p < N; p++) {
			wins[p] = (V[p] / 100) % 10;
			draws[p] = (V[p] / 10) % 10;
			losses[p] = V[p] % 10;
			scores[p] = wins[p] * 3 + draws[p];
			_wins[p] = wins[p];
			_draws[p] = draws[p];
			_losses[p] = losses[p];
			_scores[p] = scores[p];
			//cerr << "w:" << wins[p] << " d:" << draws[p] << " l:" << losses[p] << " s:" << scores[p] << endl;
			}

		if (!checkScores() || !checkWLD())
			cout << "Invalid" << endl;
		else if (unique())
			cout << "Unique" << endl;
		else
			cout << "Not unique" << endl;
		}

	return 0;
	}
