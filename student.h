#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UNIQUE_CONSTANT 42
#define AVERAGE_GRADE(math, physics, chemistry) ((math + physics + chemistry) / 3.0)

struct Student {
    char surname[50];
    char name[50];
    char gender[10];
    int age;
    char group[10];
    int math_grade;
    int physics_grade;
    int chemistry_grade;
    struct Student* next;
};

struct Student* create_student(const char* surname, const char* name, const char* gender, int age, const char* group, int math_grade, int physics_grade, int chemistry_grade);
void print_student(const struct Student* student);
void print_students_with_top_grades(const struct Student* students);
void print_all_students(const struct Student* students);
struct Student* add_student(struct Student* students, struct Student* new_student);
void* wrap_print_student(void* student_ptr);
void* wrap_print_students_with_top_grades(void* students_ptr);
void* wrap_print_all_students(void* students_ptr);

#endif // STUDENT_H
