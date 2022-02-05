// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
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

int is_reachable(int x, int y) {
    // ...and also here
    return 1;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    int i, t, x, y, ans, sum;

    assert(2 == scanf("%d%d", &N, &Q));
    for(i = 0; i < N - 1; i++) {
        assert(2 == scanf("%d%d", &X[i], &Y[i]));
    }

    init();
    sum = 0;
    for (i = 0; i < Q; i++) {
        assert(3 == scanf("%d%d%d", &t, &x, &y));
        if (t == 1) {
            toggle_edge(x, y);
        } else {
            x = (x + sum) % N + 1;
            y = (y + sum) % N + 1;
            ans = is_reachable(x, y);
            printf("%d\n", ans);
            sum += ans;
        }
    }

    return 0;
}
