// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAXN 250005

// input data
int N, Q;
int X[MAXN], Y[MAXN]; // edges


void init() {
    // insert your code here...
}

void toggle_edge(int x, int y) {
    // ...and here...
}

bool is_reachable(int x, int y) {
    // ...and also here
    return 1;
}


int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    ios::sync_with_stdio(false);

    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        cin >> X[i] >> Y[i];
    }

    init();
    int sum = 0;
    for (int i = 0; i < Q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            toggle_edge(x, y);
        } else {
            x = (x + sum) % N + 1;
            y = (y + sum) % N + 1;
            bool ans = is_reachable(x, y);
            cout << ans << '\n';
            sum += ans;
        }
    }

    return 0;
}
