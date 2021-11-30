// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>

// constraints
#define MAXT 100000
#define MAXN 4

// input data
int T, N, i, t;
int V[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for (t = 0; t < T; t++) {

        assert(1 == scanf("%d", &N));
        for (i = 0; i < N; i++)
            assert(1 == scanf("%d", &V[i]));

        // insert your code here

        printf("%d\n", 42); // print the result
    }
    return 0;
}
