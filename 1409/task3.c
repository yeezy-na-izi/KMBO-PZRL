// get number and calculate prod and sum of digits

#include <stdio.h>


int main() {
    int n;
    int sum;
    int prod;
    int wide;

    printf("Please enter n value: ");
    scanf("%d", &n);

    printf("Please enter wide value: ");
    scanf("%d", &wide);

    printf("Number in hex format: %*x = %*X\n", wide, n, wide, n);
    printf("Number in oct format: %*o = %*O\n", wide, n, wide, n);

    sum = n % 10 + n / 10 % 10 + n / 100 % 10;
    prod = (n % 10) * (n / 10 % 10) * (n / 100 % 10);

    printf("Sum of digits: %*d\n", wide, sum);
    printf("Product of digits: %*d\n", wide, prod);
    return 0;
}