// https://training.olinfo.it/#/task/ois_police3/submissions

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	//  uncomment the following lines if you want to read/write from files
	ifstream cin("input.txt");
	//  ofstream cout("output.txt");

	int N, tot = 0;
	cin >> N;

	vector<int> T(N);
	for (int i = 0; i < N; i++)
		cin >> T[i];

	int incl = T[0];
	int excl = 0;
	tot += T[0];
	int excl_new;
	for (int i = 1; i < N; i++) {
		tot += T[i];
		excl_new = (incl > excl) ? incl : excl;
		incl = excl + T[i];
		excl = excl_new;
		}

	cout << tot - ((incl > excl) ? incl : excl) << endl;
	return 0;
	}
