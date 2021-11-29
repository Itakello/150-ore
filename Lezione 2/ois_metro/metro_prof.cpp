#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

char haystack[2][MAXN + 1], needle[MAXN + 1];
int prefix[MAXN];

int main() {
	int N;
	cin >> N;

	cin >> haystack[0];
	cin >> haystack[1];
	reverse(haystack[1], haystack[1] + N);

	for (int i = 0; i < N; i++)
		haystack[0][i] = (haystack[0][i] == '^') ? '<' : '>';

	for (int i = 0; i < N; i++)
		haystack[1][i] = (haystack[1][i] == '^') ? '>' : '<';

	int M;
	cin >> M;
	cin >> needle;

	int k = -1;
	prefix[0] = k;
	for (int i = 1; i < M; i++) {
		while (k > -1 && needle[k + 1] != needle[i])
			k = prefix[k];
		if (needle[i] == needle[k + 1])
			k++;
		prefix[i] = k;
		}

	int answer = 0;

	for (int i = 0; i < 2; i++) {
		// cerr << "cerco " << needle << " in " << haystack[i] << endl;

		int k = -1;
		for (int j = 0; j < N; j++) {
			while (k > -1 && needle[k + 1] != haystack[i][j])
				k = prefix[k];
			if (haystack[i][j] == needle[k + 1])
				k++;
			if (k == M - 1) {
				answer += 1;
				// return j - k;
				}
			}
		}

	cout << answer << endl;
	}
