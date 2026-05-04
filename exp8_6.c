#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Push into stack1
void push1(int val) {
    if (top1 == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack1[++top1] = val;
}

// Push into stack2
void push2(int val) {
    if (top2 == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack2[++top2] = val;
}

// Pop from stack1
int pop1() {
    if (top1 == -1) return -1;
    return stack1[top1--];
}

// Pop from stack2
int pop2() {
    if (top2 == -1) return -1;
    return stack2[top2--];
}

// Enqueue operation
void enqueue(int val) {
    push1(val);
    printf("Inserted: %d\n", val);
}

// Dequeue operation
void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    // Move elements from stack1 to stack2 if needed
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    printf("Deleted: %d\n", pop2());
}

// Display Queue
void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    // Print stack2 (correct order)
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    // Print stack1 (reverse order)
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }

    printf("\n");
}

// Main (Menu Driven)
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue using Stacks ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
