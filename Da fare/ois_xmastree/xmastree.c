/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 200000

// input data
int N, i;
int A[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N-1; i++) {
        int a, b;
        assert(2 == scanf("%d %d", &a, &b));
        // TODO: there is a branch between a and b
    }
    for(i=0; i<N; i++) {
        assert(1 == scanf("%d", &A[i]));
    }

    // insert your code here
    long long sol = 42;
    
    printf("%lld\n", sol); // print the result
    return 0;
}
