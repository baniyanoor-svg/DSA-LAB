#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* insertSorted(struct Node* head, int value) {
   
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

 
    if (head == NULL || value < head->data) {
        newNode->next = head;
        head = newNode;
        return head;
    }


    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }

 
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}


void display(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertSorted(head, 25);
    head = insertSorted(head, 10);
    head = insertSorted(head, 30);
    head = insertSorted(head, 20);

    display(head);

    return 0;
}