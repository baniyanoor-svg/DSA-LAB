#include <stdio.h>

#define size 5

int pq[size];
int front = -1;
int rear = -1;

void insert(int item);
void delete();
void display();

int main()
{
    int ch, item;

    do
    {
        printf("\n\nPriority Queue:");
        printf("\n1. Insert\n2. Delete\n3. Display\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}

void insert(int item)
{
    int i;

    if (rear == size - 1)
    {
        printf("Queue is full");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
        pq[rear] = item;
    }
    else
    {
        // shift elements to maintain priority (highest first)
        for (i = rear; i >= front; i--)
        {
            if (item > pq[i])
                pq[i + 1] = pq[i];
            else
                break;
        }
        pq[i + 1] = item;
        rear++;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Deleted element: %d", pq[front]);
        
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }

    printf("Priority Queue: ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", pq[i]);
    }
}