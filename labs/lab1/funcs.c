#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

void sort(double *a, int n) {
    for (int i = 0; i < n; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max]) {
                max = j;
            }
        }
        double tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
    }
}

void print(double *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%g ", a[i]);
    }
    printf("\n");
}

double *read(int n) {
    double *a = (double *) calloc(n, sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    return a;
}