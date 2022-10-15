#include <iostream>

using namespace std;

struct Queue {
    int size, front, rear;
    int *Q;
};

void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *) malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->Q[++q->rear] = x;
}

int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->Q[++q->front];
}

void display(struct Queue q) {
    if (q.rear == -1)
        return;
    for (int i = q.front + 1; i <= q.rear; ++i)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main() {
    struct Queue q{};
    create(&q, 5);
    display(q);
    enqueue(&q, 10);
    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 15);
    enqueue(&q, 20);
    enqueue(&q, 23);
    display(q);
    printf("%d\n", dequeue(&q));
    display(q);
    return 0;
}
