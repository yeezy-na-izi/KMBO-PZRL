// get 2 numbers if first > second print first else print second if equal print 0

// Language: c

#include <stdio.h>


int main() {
    int x;
    int y;

    printf("Please enter first num: ");
    scanf("%d", &x);
    printf("Please enter second num: ");
    scanf("%d", &y);

    if (x > y) {
        printf("Больше\n");
    } else if (x < y) {
        printf("Меньше\n");
    } else {
        printf("Числа равны\n");
    }
    return 0;
}