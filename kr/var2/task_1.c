#include <stdio.h>

int main() {
    int number;
    int reversed_number = 0;
    printf("Enter number: ");
    scanf("%d", &number);
    while (number != 0) {
        reversed_number = reversed_number * 10 + number % 10;
        number = number / 10;
    }
    printf("Reversed number: %d", reversed_number);
}