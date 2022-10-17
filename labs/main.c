#include <stdio.h>
#include <stdlib.h>

void sort(float *a, int n) {
    for (int i = 0; i < n; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max]) {
                max = j;
            }
        }
        int tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
    }
}


int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("n must be positive\n");
        return 1;
    }
    float *a = (float *) calloc(n, sizeof(float));
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
    sort(a, n);

    for (int i = 0; i < n; i++) {
        printf("%f ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}
