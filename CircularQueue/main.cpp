#include <iostream>

using namespace std;

struct Queue {
    int size, front, rear, *Q;
};

void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *) malloc(size * sizeof(int));
}

void enqueue(struct Queue *q, int x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    }
    q->Q[q->rear = ((q->rear + 1) % q->size)] = x;
}

int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->front++;
}

void display(struct Queue q) {
    if (q.front == q.rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = (q.front + 1) % q.size; i != (q.rear + 1) % q.size; i = (i + 1) % q.size)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main() {
    return 0;
}
