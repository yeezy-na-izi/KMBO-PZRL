// input line output max and min (by length) word
// string input by getline
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char *str = NULL;
    size_t size;
    printf("Enter your text: ");
    getline(&str, &size, stdin);
    int len = strlen(str);
    char *max = NULL;
    char *min = NULL;
    char *tmp = NULL;
    tmp = (char *) malloc(len * sizeof(char));
    max = (char *) malloc(len * sizeof(char));
    min = (char *) malloc(len * sizeof(char));
    memset(max, '\0', len);
    memset(min, '\0', len);
    memset(tmp, '\0', len);
    int j = 0;
    int k = 0;
    int max_len = 0;
    int min_len = 10000;
    for (int i = 0; i < len - 1; i++) {
        if (str[i] != ' ') {
            tmp[j] = str[i];
            j++;
        } else {
            if (j > max_len) {
                max_len = j;
                memset(max, '\0', len);
                k = 0;
                while (tmp[k] != '\0') {
                    max[k] = tmp[k];
                    k++;
                }
            }
            if (j < min_len) {
                min_len = j;
                memset(min, '\0', len);
                k = 0;
                while (tmp[k] != '\0') {
                    min[k] = tmp[k];
                    k++;
                }
            }
            j = 0;
            memset(tmp, '\0', len);
        }
    }
    if (j > max_len) {
        memset(max, '\0', len);
        k = 0;
        while (tmp[k] != '\0') {
            max[k] = tmp[k];
            k++;
        }
    }
    if (j < min_len) {
        memset(min, '\0', len);
        k = 0;
        while (tmp[k] != '\0') {
            min[k] = tmp[k];
            k++;
        }
    }
    printf("Max: %s\n", max);
    printf("Min: %s", min);
    return 0;
}