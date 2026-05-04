#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

// Pop operation
char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    gets(str);   // you can also use fgets(str, MAX, stdin)

    // Push all characters into stack
    for (i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    // Pop characters back into string
    for (i = 0; i < strlen(str); i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
