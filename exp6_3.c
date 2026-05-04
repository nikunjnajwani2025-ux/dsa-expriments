#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

// Create node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert in sorted order (descending exponent)
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (head == NULL || head->exp < e) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != NULL && temp->next->exp > e)
        temp = temp->next;

    if (temp->next != NULL && temp->next->exp == e) {
        temp->next->coeff += c;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

// Display polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Addition
struct Node* add(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Subtraction (p1 - p2)
struct Node* subtract(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coeff - p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insert(result, -p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, -p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Multiplication
struct Node* multiply(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    for (struct Node* t1 = p1; t1 != NULL; t1 = t1->next) {
        for (struct Node* t2 = p2; t2 != NULL; t2 = t2->next) {
            int c = t1->coeff * t2->coeff;
            int e = t1->exp + t2->exp;
            result = insert(result, c, e);
        }
    }

    return result;
}

// Create polynomial
struct Node* createPoly() {
    int n, c, e;
    struct Node* head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        head = insert(head, c, e);
    }

    return head;
}

// Main menu
int main() {
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1.Create Polynomial 1\n2.Create Polynomial 2\n");
        printf("3.Addition\n4.Subtraction (P1 - P2)\n5.Multiplication\n");
        printf("6.Display P1\n7.Display P2\n8.Display Result\n9.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                p1 = createPoly();
                break;

            case 2:
                p2 = createPoly();
                break;

            case 3:
                result = add(p1, p2);
                printf("Result (Addition): ");
                display(result);
                break;

            case 4:
                result = subtract(p1, p2);
                printf("Result (Subtraction): ");
                display(result);
                break;

            case 5:
                result = multiply(p1, p2);
                printf("Result (Multiplication): ");
                display(result);
                break;

            case 6:
                printf("Polynomial 1: ");
                display(p1);
                break;

            case 7:
                printf("Polynomial 2: ");
                display(p2);
                break;

            case 8:
                printf("Result: ");
                display(result);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
