#include "student.h"
#include "queue.h"

int main() {
    system("chcp 65001");

    struct Queue* student_queue = create_queue();

    enqueue(student_queue, create_student("Иванова", "Анна", "female", 20, "ИСП-208", 4, 5, 5));
    enqueue(student_queue, create_student("Петрова", "Мария", "female", 21, "ИСП-307", 5, 5, 4));
    enqueue(student_queue, create_student("Сидорова", "Елена", "female", 19, "СИС-107", 5, 5, 5));

    printf("Unique constant value: %d\n", UNIQUE_CONSTANT);
    printf("All students in queue:\n");
    print_queue(student_queue);

    printf("Students with top grades:\n");
    struct QueueNode* current = student_queue->front;
    while (current != NULL) {
        struct Student* student = current->student;
        if (strcmp(student->gender, "female") == 0 && student->physics_grade == 5 && student->chemistry_grade == 5) {
            print_student(student);
        }
        current = current->next;
    }

    free_queue(student_queue);

    return 0;
}
