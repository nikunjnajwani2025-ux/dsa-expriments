#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <math.h>    // for pow()

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;
    int op1, op2;

    while (exp[i] != '\0') {

        // If operand, push to stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');   // convert char to int
        }
        // If operator
        else {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push(pow(op1, op2)); break;
                default: printf("Invalid operator\n");
            }
        }
        i++;
    }
    return pop();
}

// Main function
int main() {
    char exp[MAX];

    printf("Enter postfix expression (single digit operands): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
