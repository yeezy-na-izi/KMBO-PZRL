#include <stdio.h>


int main() {
    int number;
    int check_sum = 0;
    int first_div;
    int second_div;
    printf("Enter number: ");
    scanf("%d", &number);

    for (int i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            first_div = i;
            second_div = number / i;
            if (first_div != second_div && first_div != 1) {
                printf("%d %d ", first_div, second_div);
                check_sum += first_div + second_div;
            } else {
                printf("%d ", first_div);
                check_sum += first_div;
            }
        }
    }
    printf("\n");
    if (check_sum == number) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}