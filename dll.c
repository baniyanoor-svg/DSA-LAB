#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert at beginning
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete from beginning
struct Node* deleteBegin(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);

    return head;
}

// Delete a specific value
struct Node* deleteValue(struct Node* head, int key) {
    struct Node* temp = head;

    // Search node
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return head;
    }

    // If first node
    if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);

    printf("Initial List:\n");
    display(head);

    // Delete from beginning
    head = deleteBegin(head);
    printf("After deleting from beginning:\n");
    display(head);

    // Delete specific value
    head = deleteValue(head, 10);
    printf("After deleting value 10:\n");
    display(head);

    return 0;
}