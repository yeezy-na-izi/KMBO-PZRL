#include "lab3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


University *initUniversity(const char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        return NULL;
    }
    University *university = (University *) malloc(sizeof(University));
    if (university == NULL) {
        return NULL;
    }
    university->groups = NULL;
    university->groupsCount = 0;
    while (!feof(file)) {
        Student *student = (Student *) malloc(sizeof(Student));
        fread(student, sizeof(Student), 1, file);
        if (feof(file)) {
            free(student);
            break;
        }
        g_Id++;
        Group *group = getGroup(university, student->groupName);
        if (group == NULL) {
            group = (Group *) malloc(sizeof(Group));
            strcpy(group->name, student->groupName);
            group->students = NULL;
            group->studentsCount = 0;
            if (!addNewGroup(university, *group)) {
                continue;
            }
        }
        if (!addNewStudent(group, *student)) {
            continue;
        }
    }
    fclose(file);
    return university;
}

bool addNewGroup(University *university, const Group group) {
    printf("addNewGroup: %s\n", group.name);
    if (university == NULL) {
        return false;
    }
    university->groups = (Group **) realloc(university->groups, sizeof(Group *) * (university->groupsCount + 1));
    if (university->groups == NULL) {
        return false;
    }
    university->groups[university->groupsCount] = group;
    university->groupsCount++;
    return true;
}

bool addNewStudent(Group *group, Student student) {
    if (group == NULL) {
        return false;
    }
    if (group->students == NULL) {
        group->students = (Student *) malloc(sizeof(Student));
        group->studentsCount = 0;
    } else {
        group->students = (Student *) realloc(group->students, sizeof(Student) * (group->studentsCount + 1));
    }
    if (group->students == NULL) {
        return false;
    }
    group->students[group->studentsCount] = student;
    group->studentsCount++;
    return true;
}

bool removeGroup(University *university, const char *name) {

}

bool removeStudent(University *university, const unsigned long id) {

}

Group *getGroup(const University *university, const char *name) {
    // return pointer to group with name
    for (int i = 0; i < university->groupsCount; i++) {
        if (strcmp(university->groups[i].name, name) == 0) {
            return &university->groups[i];
        }
    }
    return NULL;

}

Student *getStudent(const University *university, const unsigned long id) {

}

void printUniversity(const University *university) {
    for (int i = 0; i < university->groupsCount; i++) {
        printGroup(university->groups[i]);
        printf("------------------------------------------------------------------------------\n");
    }
}


void printGroup(const Group group) {
    printf("%s\n", group.name);
    for (int i = 0; i < group.studentsCount; i++) {
        printStudent(group.students[i]);
    }

}

void printStudent(const Student student) {
    printf("%lu\n", student.id);
    printf("\t%s %s\n", student.name, student.surname);
    printf("\t%d\n", student.birthYear);
}

void freeUniversity(University *university) {
    // free memory allocated for university
    // free all groups
    // free all students
    // free university

}

bool saveToFile(const char *fileName, const University *university) {

}

int main() {
    char *fileName = "/Users/yeezy_na_izi/CLionProjects/FirstSem/labs/lab3/kmbo22.dat";
    University *university = initUniversity(fileName);
    if (university == NULL) {
        printf("Error: %s not found", fileName);
        return 1;
    }
    printUniversity(university);
}