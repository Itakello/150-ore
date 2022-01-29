#include <stdio.h>
#include <assert.h>

#define MAXN 10000
#define MAXW 10

char W[MAXN][MAXW+1];
char P[MAXN+1];

int main() {
    FILE *fr, *fw;
    int N, K, L, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &K, &L));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%s", W[i]));

    // insert your code here
    P[0] = 'a';
    P[1] = 0;

    fprintf(fw, "%s\n", P);
    fclose(fr);
    fclose(fw);
    return 0;
}
