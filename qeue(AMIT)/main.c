#include <stdio.h>
#include <stdlib.h>
typedef struct Queue Queue;
struct Queue{
    int* arr;
    int front, rear;
    int count, size;
};
Queue initQueue(int size){
    Queue new_queue;
    new_queue.arr = (int*) malloc(sizeof(int) * size);
    new_queue.size = size;
    new_queue.count = 0;
    new_queue.front = 0;
    new_queue.rear = 0;
    return new_queue;
}
void enQueue(Queue* q, int value){
    if(q->count == q->size){
        printf("Queue is full!!\n");
        return;
    }
    q->arr[q->rear] = value;
    q->rear = (q->rear + 1) % q->size;

    q->count++;
}
int deQueue(Queue* q){
    if(q->count == 0){
        printf("Queue is empty\n");
        return -999;
    }
    int temp = q->arr[q->front];
    q->front = (q->front + 1) % q->size;
    q->count--;
    return temp;
}
void display(Queue* q){
    Queue temp = initQueue(q->size);
    while(q->count > 0){
        int x = deQueue(q);
        printf("%d -> ", x);
        enQueue(&temp, x);
    }
    printf("\n");
    while(temp.count > 0){
        int x = deQueue(&temp);
        enQueue(q, x);
    }
}
int main(){
    Queue q1 = initQueue(6);
    enQueue(&q1, 10);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    enQueue(&q1, 8);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    enQueue(&q1, 5);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    enQueue(&q1, 9);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    deQueue(&q1);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    deQueue(&q1);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    enQueue(&q1, 4);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    enQueue(&q1, 2);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    enQueue(&q1, 3);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    enQueue(&q1, 99);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    enQueue(&q1, 99);
    printf("front: %d, rear: %d\n", q1.front, q1.rear);
    display(&q1);

    return 0;
}
