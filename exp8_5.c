#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

// Queue operations for q1
void enqueue1(int x) {
    if (rear1 == MAX - 1) return;
    if (front1 == -1) front1 = 0;
    q1[++rear1] = x;
}

int dequeue1() {
    if (front1 == -1 || front1 > rear1) return -1;
    return q1[front1++];
}

// Queue operations for q2
void enqueue2(int x) {
    if (rear2 == MAX - 1) return;
    if (front2 == -1) front2 = 0;
    q2[++rear2] = x;
}

int dequeue2() {
    if (front2 == -1 || front2 > rear2) return -1;
    return q2[front2++];
}

// Push
void push(int x) {
    // Step 1: enqueue in q2
    enqueue2(x);

    // Step 2: move all q1 elements to q2
    while (front1 != -1 && front1 <= rear1) {
        enqueue2(dequeue1());
    }

    // Step 3: swap q1 and q2
    int i;
    front1 = front2;
    rear1 = rear2;

    for (i = 0; i <= rear2; i++) {
        q1[i] = q2[i];
    }

    // reset q2
    front2 = rear2 = -1;
}

// Pop
void pop() {
    if (front1 == -1 || front1 > rear1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", dequeue1());
}

// Peek
void peek() {
    if (front1 == -1 || front1 > rear1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", q1[front1]);
}

// Display
void display() {
    if (front1 == -1 || front1 > rear1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = front1; i <= rear1; i++) {
        printf("%d\n", q1[i]);
    }
}

// Main
int main() {
    int choice, data;

    while (1) {
        printf("\n--- STACK USING QUEUES ---\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
