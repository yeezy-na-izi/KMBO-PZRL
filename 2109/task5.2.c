// print factorial of n


#include <stdio.h>


int main() {
    int n;
    int fact = 1;

    printf("Please enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("%d\n", fact);
    return 0;
}