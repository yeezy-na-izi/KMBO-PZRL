#include <stdio.h>
#include <stdlib.h>


typedef struct array {
    int *mass;
    int size;
    int capacity;
} array;

void init(array *arr, int size) {
    arr->mass = malloc(size * sizeof(int));
    arr->size = size;
    arr->capacity = 1;
}

void print(array *arr) {
    for (int i = 0; i < arr->size; ++i) {
        printf("%i ", arr->mass[i]);
    }
    printf("\n");
}

void print_size(array *arr) {
    printf("%i\n", arr->size);
}

void add(array *arr, int value) {
    if (arr->size == arr->capacity) {
        printf("Размер массива изменился\n");
        arr->capacity *= 2;
        arr->mass = realloc(arr->mass, arr->capacity * sizeof(int));
    }
    arr->mass[arr->size] = value;
    arr->size++;
}

void delete(array *arr, int index) {
    arr->size--;
    for (int i = index; i < arr->size; ++i) {
        arr->mass[i] = arr->mass[i + 1];
    }
}

void delete_last(array *arr) {
    arr->size--;
}


int find(array *arr, int value) {
    for (int i = 0; i < arr->size; ++i) {
        if (arr->mass[i] == value) {
            return i;
        }
    }
    return -1;
}

enum {
    INIT,
    PRINT,
    PRINT_SIZE,
    ADD,
    DELETE,
    DELETE_LAST,
    FIND,
    EXIT
};

int main() {
    array arr;
    printf("Команды:\n");
    printf("1 - вывести массив\n");
    printf("2 - вывести размер массива\n");
    printf("3 - добавить элемент в массив\n");
    printf("4 - удалить элемент из массива\n");
    printf("5 - удалить последний элемент массива\n");
    printf("6 - найти элемент в массиве\n");
    printf("7 - выйти\n");
    int user_out = INIT;
    while (1) {
        if (user_out == INIT) {
            init(&arr, 0);
        }
        if (user_out == PRINT) {
            print(&arr);
        }
        if (user_out == PRINT_SIZE) {
            print_size(&arr);
        }
        if (user_out == ADD) {
            int value;
            printf("Введите элемент для добавления: ");
            scanf("%i", &value);
            add(&arr, value);
        }
        if (user_out == DELETE) {
            int index;
            printf("Введите индекс элемента для удаления: ");
            scanf("%i", &index);
            delete(&arr, index);
        }
        if (user_out == DELETE_LAST) {
            delete_last(&arr);
        }
        if (user_out == FIND) {
            int value;
            printf("Введите элемент для поиска: ");
            scanf("%i", &value);
            printf("%i\n", find(&arr, value));
        }
        if (user_out == EXIT) {
            break;
        }
        printf("Введите номер команды:\n");
        scanf("%i", &user_out);
    }
    return 0;
}