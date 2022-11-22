#include "string_lab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strremove(char *str, const char ch) {
    char *p = str;
    while (*p) {
        if (*p == ch) {
            memmove(p, p + 1, strlen(p));
        } else {
            p++;
        }
    }
    return str;
}

int _strcountchar(const char *str, const char ch) {
    if (str == NULL || ch == '\0') {
        return -1;
    }
    int count = 0;
    int str_len = strlen(str);
    int cur_index = strchr(str, ch) - &str[0];
    while (cur_index < str_len && cur_index >= 0) {
        count++;
        cur_index = strchr(&str[cur_index + 1], ch) - &str[0];
    }
    if (count == 0) {
        return -1;
    }
    return count;
}

char *_strdelspaces(char *str) {
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            memmove(&str[i], &str[i + 1], str_len - i);
            i--;
            str_len--;
        }
    }

    return str;
}

char *_strtolower(char *str) {
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return str;
}

char *_strtoupper(char *str) {
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}

int _strcmp(const char *str1, const char *str2) {
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    if (str1_len < str2_len) {
        return -1;
    }
    if (str1_len > str2_len) {
        return 1;
    }
    for (int i = 0; i < str1_len; i++) {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
    }

    return 0;
}

char *_strreverse(const char *str1) {
    int str1_len = strlen(str1);
    char *str2 = (char *) malloc(str1_len * sizeof(char));
    for (int i = 0; i < str1_len; i++) {
        str2[i] = str1[str1_len - i - 1];
    }
    return str2;
}


int _atoi(const char *str) {
    int str_len = strlen(str);
    int result = 0;
    for (int i = 0; i < str_len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            return 0;
        }
    }
    return result;
}

char *_strchr(char *str, int ch) {
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        if (str[i] == ch) {
            return &str[i];
        }
    }
    return NULL;
}

char *_strstr(const char *str, const char *substr) {
    int str_len = strlen(str);
    int substr_len = strlen(substr);
    for (int i = 0; i < str_len; i++) {
        if (str[i] == substr[0]) {
            int j = 0;
            while (j < substr_len && str[i + j] == substr[j]) {
                j++;
            }
            if (j == substr_len) {
                return (char *) &str[i];
            }
        }
    }
    return NULL;
}
