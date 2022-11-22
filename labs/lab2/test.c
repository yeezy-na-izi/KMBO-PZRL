#include "string_lab.h"
#include <stdio.h>


int main() {
    char str1[100] = "123";
    printf("str1: %s\n", str1);
    printf("int1: %d\n", _atoi(str1));
    printf("str1_reverse: %s\n", _strreverse(str1));

    char str2[100] = "abc";
    printf("str2: %s\n", str2);
    printf("str2_upper: %s\n", _strtoupper(str2));

    char str3[100] = "ABC";
    printf("str3: %s\n", str3);
    printf("str3_lower: %s\n", _strtolower(str3));

    char str4[100] = "Hello, world!";
    printf("str4: %s\n", str4);
    printf("str4_remove: %s\n", _strremove(str4, 'l'));

    char str5[100] = "Hello, world!";
    printf("str5: %s\n", str5);
    printf("str5_count: %d\n", _strcountchar(str5, 'l'));

    char str6[100] = "Hello,   world!";
    printf("str6: %s\n", str6);
    printf("str6_delspaces: %s\n", _strdelspaces(str6));

    char str7[100] = "Hello, world!";
    char str8[100] = "Hello, world!";
    char str9[100] = "Hello, world?";
    printf("str7: %s\n", str7);
    printf("str8: %s\n", str8);
    printf("str7 == str8: %d\n", _strcmp(str7, str8));
    printf("str7 == str9: %d\n", _strcmp(str7, str9));

    char str10[100] = "Hello, world!";
    printf("str10: %s\n", str10);
    printf("str10_chr: %s\n", _strchr(str10, 'w'));

    char str11[100] = "this is a test";
    printf("str11: %s\n", str11);
    printf("str11_strstr: %s\n", _strstr(str11, "is"));

    return 0;
}