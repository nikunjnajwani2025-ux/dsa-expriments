#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Main conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        
        // Operand
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        
        // Left parenthesis
        else if (ch == '(') {
            push(ch);
        }
        
        // Right parenthesis
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Main
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
