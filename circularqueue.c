//WAP to implement circular queue

#include <stdio.h>

#define size 5

void insertq(int queue[], int item);
void deleteq(int queue[]);
void display(int queue[]);

int front = -1;
int rear = -1;

int main()
{
    int queue[size];
    int choice, value;

    do
    {
        printf("\n\n--- Circular Queue ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertq(queue, value);
                break;

            case 2:
                deleteq(queue);
                break;

            case 3:
                display(queue);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

void insertq(int queue[], int item)
{
    // Check if full
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Queue is FULL\n");
        return;
    }

    if (rear == -1) // First element
    {
        front = rear = 0;
    }
    else if (rear == size - 1 && front > 0) // Wrap around
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = item;
    printf("%d inserted successfully\n", item);
}

void deleteq(int queue[])
{
    if (front == -1)
    {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("%d deleted\n", queue[front]);

    if (front == rear) // Only one element
    {
        front = rear = -1;
    }
    else if (front == size - 1) // Wrap around
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display(int queue[])
{
    int i;

    if (front == -1)
    {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("Queue elements: ");

    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i < size; i++)
            printf("%d ", queue[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    printf("\n");
}