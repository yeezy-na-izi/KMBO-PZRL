#include <stdio.h>
#include <math.h>

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    // get len of number
    int len = 0;
    int tmp = number;
    while (tmp != 0) {
        tmp = tmp / 10;
        len += 1;
    }
    tmp = number;
    int digit;
    int sum = 0;
    while (tmp != 0) {
        digit = tmp % 10;
        tmp = tmp / 10;
        sum += pow(digit, len);
    }
    if (sum == number) {
        printf("Yes");
    } else {
        printf("No");
    }
}