// make algorithm pow of number


#include <stdio.h>


int main(int argc, char **argv) {
    int number, pow, result = 1;
    printf("Enter number: ");
    scanf("%d", &number);
    printf("Enter pow: ");
    scanf("%d", &pow);

    for (int i = 0; i < pow; i++) {
        result *= number;
    }

    printf("Result: %d\n", result);
    return 0;
}