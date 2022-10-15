// get n, get n numbers, sort them by Selection sort and print them

#include <stdio.h>
#include <stdlib.h>


// selection sort
void sort(int *a, int n) {
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


int main(int argc, char *argv[]) {
    int n;
    int *a = (int *) calloc(n, sizeof(int));
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
    }
    sort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}
