#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* insert(struct Node* head, int value) {
 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  
    newNode->data = value;

  
    newNode->next = head;

  
    head = newNode;

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

   
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);

    
    display(head);

    return 0;
}