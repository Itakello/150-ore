/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// constraints
#define MAXN 500000
#define MAXS 100000

// input data
int N, S;
vector<int> A, B;
vector<long long> T;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N >> S;
    A.resize(N);
    B.resize(N);
    T.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> T[i];
    }

    // insert your code here

    for (int i = 0; i < N; i++) {
        cout << 42 << '\n';
    }
    return 0;
}
