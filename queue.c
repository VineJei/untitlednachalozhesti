#include "queue.h"


struct Queue* create_queue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct Student* student) {
    struct QueueNode* new_node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    new_node->student = student;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

struct Student* dequeue(struct Queue* queue) {
    if (is_queue_empty(queue)) {
        return NULL;
    }
    struct QueueNode* temp = queue->front;
    struct Student* student = temp->student;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return student;
}

int is_queue_empty(struct Queue* queue) {
    return queue->front == NULL;
}

void print_queue(const struct Queue* queue) {
    struct QueueNode* current = queue->front;
    while (current != NULL) {
        print_student(current->student);
        current = current->next;
    }
}

void free_queue(struct Queue* queue) {
    while (!is_queue_empty(queue)) {
        struct Student* student = dequeue(queue);
        free(student);
    }
    free(queue);
}
