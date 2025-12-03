// WAP to implement queue using array. Special Condition :- Priorities "10" for every dequeue operation.

#include <stdio.h>

#define MAX 5

int data[MAX];
int priority[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void enqueue(int value, int pri) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = rear + 1;
    data[rear] = value;
    priority[rear] = pri;

    printf("Inserted: %d with priority %d\n", value, pri);
}

int dequeue() {
    int i;
    int pos = -1;
    int removedValue;

    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }

    for (i = front; i <= rear; i++) {
        if (priority[i] == 10) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        removedValue = data[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }
    } else {
        removedValue = data[pos];

        for (i = pos; i < rear; i++) {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }

        rear = rear - 1;

        if (rear < front) {
            front = rear = -1;
        }
    }

    printf("Deleted: %d\n", removedValue);
    return removedValue;
}

void display() {
    int i;

    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (value:priority):\n");
    for (i = front; i <= rear; i++) {
        printf("%d:%d  ", data[i], priority[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int val, pri;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter priority (10 = highest): ");
            scanf("%d", &pri);
            enqueue(val, pri);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            printf("Exiting...\n");
            return 0;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
}
