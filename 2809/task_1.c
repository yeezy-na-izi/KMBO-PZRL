#include <stdio.h>

int main() {
    int n;
    int dublicate = 0;
    int b;

    printf("Please enter n: ");
    scanf("%d", &n);


    for (int i = 0; i < 10; i++) {
        b = n
        while (b > 0) {
            if (b % 10 == i) {
                dublicate++;
            }
            b /= 10;
        }
        if (dublicate > 1) {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}