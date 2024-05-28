#include "student.h"

struct Student* create_student(const char* surname, const char* name, const char* gender, int age, const char* group, int math_grade, int physics_grade, int chemistry_grade) {
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    strcpy(student->surname, surname);
    strcpy(student->name, name);
    strcpy(student->gender, gender);
    student->age = age;
    strcpy(student->group, group);
    student->math_grade = math_grade;
    student->physics_grade = physics_grade;
    student->chemistry_grade = chemistry_grade;
    student->next = NULL;
    return student;
}

void print_student(const struct Student* student) {
    printf("Name: %s %s\n", student->surname, student->name);
    printf("Gender: %s\n", student->gender);
    printf("Age: %d\n", student->age);
    printf("Group: %s\n", student->group);
    printf("Math grade: %d\n", student->math_grade);
    printf("Physics grade: %d\n", student->physics_grade);
    printf("Chemistry grade: %d\n", student->chemistry_grade);
    printf("Average grade: %.2f\n", AVERAGE_GRADE(student->math_grade, student->physics_grade, student->chemistry_grade));
    printf("\n");
}

void print_students_with_top_grades(const struct Student* students) {
    while (students != NULL) {
        if (strcmp(students->gender, "female") == 0 && students->physics_grade == 5 && students->chemistry_grade == 5) {
            print_student(students);
        }
        students = students->next;
    }
}

void print_all_students(const struct Student* students) {
    while (students != NULL) {
        print_student(students);
        students = students->next;
    }
}

struct Student* add_student(struct Student* students, struct Student* new_student) {
    if (students == NULL) {
        students = new_student;
    } else {
        struct Student* current = students;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
    return students;
}

void* wrap_print_student(void* student_ptr) {
    print_student((struct Student*)student_ptr);
    return student_ptr;
}

void* wrap_print_students_with_top_grades(void* students_ptr) {
    print_students_with_top_grades((struct Student*)students_ptr);
    return students_ptr;
}

void* wrap_print_all_students(void* students_ptr) {
    print_all_students((struct Student*)students_ptr);
    return students_ptr;
}
