#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int *a = (int *) calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
//        a[i] = i;
        printf("a[%d] = %d -> %p\n", i, a[i], &a[i]);
    }
    printf("%lu\n", sizeof(a));
    free(a);
    return 0;
}