// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 50000

// input data
int N, Q, K, type, i;
int V[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &Q, &K));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &V[i]));

    for (int i=0; i<Q; i++) {
        assert(1 == scanf("%d", &type));
        if (type == 1) {
            // building update
            int a, b;
            assert(2 == scanf("%d %d", &a, &b));

            // insert your code here

        }
        if (type == 2) {
            // redevelopment planning
            int l, r, s;
            assert(3 == scanf("%d %d %d", &l, &r, &s));

            // insert your code here

            printf("%d\n", 42); // print the result of the query
        }
    }
    return 0;
}
