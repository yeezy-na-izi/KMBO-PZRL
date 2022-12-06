#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"


int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0) {
        printf("error\n");
        return 1;
    }

    double *a = read(n);
    sort(a, n);
    print(a, n);

    free(a);
    return 0;
}
