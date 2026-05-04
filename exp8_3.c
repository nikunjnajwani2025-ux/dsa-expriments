#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX];
int front = 0, rear = -1;

// Enqueue
void enqueue(char ch) {
    queue[++rear] = ch;
}

// Dequeue
char dequeue() {
    return queue[front++];
}

int main() {
    char str[MAX];
    int i, len, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Insert all characters into queue
    for (i = 0; i < len; i++) {
        enqueue(str[i]);
    }

    // Compare with reverse using array
    for (i = len - 1; i >= 0; i--) {
        char ch = dequeue();
        if (str[i] != ch) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
