#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int get_rand_number(int min, int max) {
    int number_int = rand() % (max - min + 1) + min;;
    return number_int;
}

// quick sort
void quick_sort(int *vec, int left, int right) {
    int i = left;
    int j = right;
    int pivot = vec[(left + right) / 2];
    int temp;
    while (i <= j) {
        while (vec[i] < pivot) {
            ++i;
        }
        while (vec[j] > pivot) {
            --j;
        }
        if (i <= j) {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            ++i;
            --j;
        }
    }
    if (left < j) {
        quick_sort(vec, left, j);
    }
    if (i < right) {
        quick_sort(vec, i, right);
    }
}

// get fashion
int get_fashion(int *vec, int len) {
    int fashion = vec[0];
    int fashion_count = 1;
    int current = vec[0];
    int current_count = 1;
    for (int i = 1; i < len; ++i) {
        if (vec[i] == current) {
            ++current_count;
        } else {
            if (current_count > fashion_count) {
                fashion = current;
                fashion_count = current_count;
            }
            current = vec[i];
            current_count = 1;
        }
    }
    if (current_count > fashion_count) {
        fashion = current;
        fashion_count = current_count;
    }
    return fashion;
}


int main() {
    int a;
    int b;

    printf("Please enter a: ");
    scanf("%d", &a);
    printf("Please enter b: ");
    scanf("%d", &b);

    int mass[100];
    int sum = 0;
    int elem;

    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        elem = get_rand_number(a, b);
        mass[i] = elem;
        sum += elem;
    }

    quick_sort(mass, 0, 99);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%5d ", mass[i * 10 + j]);
        }
        printf("\n");
    }
    printf("\n");

    int min = mass[0];
    int max = mass[99];
    int scope = max - min;
    int fashion = get_fashion(mass, 100);
    float median = ((float) mass[49] + (float) mass[50]) / 2;
    float average = (float) sum / 100;

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Median: %.2f\n", median);
    printf("Scope: %d\n", scope);
    printf("Average: %.2f\n", average);
    printf("Fashion: %d\n", fashion);
    return 0;
}
