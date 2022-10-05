// input n and input n elem

#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Please enter n: ");
    scanf("%d", &n);
    int vec[n];

    for (int i = 0; i < n; ++i) {
        printf("Please enter vec[%d]: ", i);
        scanf("%d", &vec[i]);
    }

    int sum = 0;
    int el;
    for (int i = 0; i < n; ++i) {
        printf("Please enter point[%d]: ", i + 1);
        scanf("%d", &el);
        sum += pow(el, i + 1) * vec[i];
    }
    printf("value = %d\n", sum);

    return 0;
}