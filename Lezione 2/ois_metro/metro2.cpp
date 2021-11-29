// https://training.olinfo.it/#/task/ois_metro/statement
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000000
char T[2][MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1; // starting values
	while (i < m) { // pre-process the pattern string P
		while (j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
		i++; j++; // if same, advance both pointers
		b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
		}
	} // in the example of P = "SEVENTY SEVEN" above
int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
	int count = 0;
	for (int k = 0; k < 2; k++) {
		int i = 0, j = 0; // starting values
		while (i < n) { // search through string T
			while (j >= 0 && T[k][i] != P[j]) j = b[j]; // different, reset j using b
			i++; j++; // if same, advance both pointers
			if (j == m) { // a match found when j == m
				//printf("P is found at index %d in T\n", i - j);
				count++;
				j = b[j]; // prepare j for the next possible match
				}
			}
		}
	return count;
	}


int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }  // usage: a.out <input_file>
	cin >> n >> T[0] >> T[1] >> m >> P;
	reverse(T[1], T[1] + n);
	for (size_t i = 0; i < n; i++) {
		T[0][i] = (T[0][i] == '^') ? '<' : '>';
		T[1][i] = (T[1][i] == '^') ? '>' : '<';
		}
	kmpPreprocess();
	cout << kmpSearch() << endl;
	return 0;
	}