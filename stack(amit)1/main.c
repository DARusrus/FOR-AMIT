#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
Node* top = NULL;
int capacity = 5;
int count = 0;

Node* makeNode(int x){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

void push(int x){
    if(count == capacity){
        printf("Stack Overflow\n");
        return;
    }
    Node* p = makeNode(x);
    p->next = top;
    top = p;
    count++;
}

int pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }
    Node* del = top;

    int value = top->data;
    top = top->next;
    free(del);
    count--;
    return value;
}

int main(){

    push(1);
    push(2);
    push(3);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}
