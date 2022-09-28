#include <stdio.h>


int main() {
    int m;
    int h;

    printf("Please enter m: ");
    scanf("%d", &m);
    printf("Please enter h: ");
    scanf("%d", &h);

    int angle = 30 * h - 5.5 * m;
    if (angle < 0) {
        angle = -angle;
    }
    if (angle > 180) {
        angle = 360 - angle;
    }
    printf("%d\n", angle);

}
