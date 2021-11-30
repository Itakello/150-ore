// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 250000

// input data
int N, M, Q, i, x, y;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &M, &Q));

    for (i = 0; i < M; i++) {
        assert(2 == scanf("%d %d", &x, &y));
        // insert your code here
    }

    for (i = 0; i < Q; i++) {
        assert(2 == scanf("%d %d", &x, &y));
        // insert your code here

        printf("%d\n", 42); // print the result
    }

    return 0;
}
