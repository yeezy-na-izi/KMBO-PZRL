#include <stdio.h>

int main() {
    int hour_1;
    int minute_1;
    int second_1;
    int hour_2;
    int minute_2;
    int second_2;

    printf("Hours of first day: ");
    scanf("%d", &hour_1);
    printf("Minutes of first day: ");
    scanf("%d", &minute_1);
    printf("Seconds of first day: ");
    scanf("%d", &second_1);
    printf("Hours of second day: ");
    scanf("%d", &hour_2);
    printf("Minutes of second day: ");
    scanf("%d", &minute_2);
    printf("Seconds of second day: ");
    scanf("%d", &second_2);

    int total_seconds_1 = hour_1 * 3600 + minute_1 * 60 + second_1;
    int total_seconds_2 = hour_2 * 3600 + minute_2 * 60 + second_2;

    printf("Answer: %d\n", total_seconds_2 - total_seconds_1);
    return 0;
}