#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int n, a, b, c;
    int guess = 0;
    int number = 0;

    srand(time(NULL));
    number = rand() % 100 + 1;

    printf("Введите число: ");
    scanf("%d", &n);

    while (guess != number) {
        printf("Введите число: ");
        scanf("%d", &guess);
        if (guess > number) {
            printf("Слишком много\n");
        } else if (guess < number) {
            printf("Слишком мало\n");
        }
    }
    printf("Вы угадали число");
    return 0;
}