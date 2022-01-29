// Link
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 1010

// input data
int N;
int boardF[MAXN][MAXN], boardW[MAXN][MAXN];

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }

	cin >> N;
	// Inserimento con somma
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char c;
			cin >> c;
			if (c == 'R') {
				boardF[i][j] = boardF[i][j - 1] + 1;
				boardW[i][j] = 0;
				}
			else {
				boardF[i][j] = 0;
				boardW[i][j] = boardW[i][j - 1] + 1;
				}
			}
		}

	// Stampa
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << boardF[i][j] << " ";
			}
		cout << "\n";
		}

	// Ordinamento
	for (int i = 1; i <= N; i++) {
		int count[N + 1] = { 0 };
		for (int j = 1; j <= N; j++) {
			count[boardF[j][i]]++;
			}
		cout << endl << "S: ";
		for (int j = 1; j <= N; j++) {
			cout << count[j] << " ";
			}
		int row_no = 0;
		for (int j = N; j > 0; j--) {
			if (count[j] > 0) {
				for (int k = 0; k < count[j]; k++) {
					boardF[row_no][i] = j;
					row_no++;
					}
				}
			}
		}

	// Stampa
	cout << "\nStampa ordinata:\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << boardF[i][j] << " ";
			}
		cout << "\n";
		}

	return 0;
	}
