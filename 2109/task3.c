// are given natural numbers from 35 to 87 enter number % 7 == 1 or 2 or 5


#include <stdio.h>


int main() {
    for (int i = 35; i <= 87; i++) {
        if (i % 7 == 1 || i % 7 == 2 || i % 7 == 5) {
            printf("%d\n", i);
        }
    }
    return 0;
}