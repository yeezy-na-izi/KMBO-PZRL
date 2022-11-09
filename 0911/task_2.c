// check string1 == string2 without using strcmp
#include <stdio.h>
#include <string.h>


int main() {
    char str1[100];
    char str2[100];
    printf("Enter string1: ");
    scanf("%s", str1);
    printf("Enter string2: ");
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        printf("Strings are not equal");
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            printf("Strings are not equal");
            return 0;
        }
    }
    printf("Strings are equal");
    return 0;
}

