// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 250000

// input data
int T, K, t, i;
char S[MAXN];

void solve() {
    assert(1 == scanf("%d", &K));
    assert(1 == scanf("%s", S));

    // insert your code here

    printf("%d\n", 42); // print the result
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(t=0; t<T; t++) {
        solve();
    }
    
    return 0;
}
