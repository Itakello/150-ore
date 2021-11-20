// https://training.olinfo.it/#/task/ois_picarats/statement

#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// constraints
#define MAXN 10000
#define MAXM 50000
#define MAXC 100

int N, M, C_0, a, b, c;

int main() {
  cin >> N, M, C_0;
  vi g_diff(N);
  for (int i = 0; i < N; i++) {
    cin >> g_diff[i];
    }
  vii g_weitghts(M);
  for (int i = 0; i < M; i++) {
    cin >> a, b, c;
    g_weitghts[a] = make_pair(b, c);
    }



  cout << 42 << endl;
  return 0;
  }
