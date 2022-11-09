// get name and surname and out them
#include <stdio.h>
#include <string.h>


int main() {
    char name[20];
    char surname[20];
    memset(name, '\0', 20);
    memset(surname, '\0', 20);


    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your surname: ");
    scanf("%s", surname);
    char full_name[40];
    sprintf(full_name, "%sЯ%s", name, surname);
    printf("Your name is %s\n", full_name);
    printf("%i\n", strcmp(name, surname));

    return 0;
}