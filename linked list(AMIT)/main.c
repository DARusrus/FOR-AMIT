#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;

Node* makeNode(int x){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

void insertFront(int x){
    Node* p = makeNode(x);
    p->next = head;
    head = p;
}

void insertEnd(int x){
    Node* p = makeNode(x);


    if(head == NULL){
        head = p;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = p;
}

void insertSorted(int x){
    Node* p = makeNode(x);

    if(head == NULL){
        head = p;
        return;
    }

    if(head->next == NULL){

        if(head->data >= x){
            p->next = head;
            head = p;
        }

        else{
            head->next = p;
        }
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data < x){
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
}

void deleteNode(int x){

    if(head == NULL){
        return;
    }

    if(head->data == x){
        Node* del = head;
        head = head->next;
        free(del);
        return;
    }
    Node* temp = head;

    while(temp->next != NULL && temp->next->data != x){
        temp = temp->next;
    }
    if(temp->next != NULL){
        Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    insertSorted(30);
    insertFront(10);
    insertSorted(20);
    insertSorted(40);



     insertEnd(50);
     insertEnd(60);
    ;
    display();

    return 0;
}
