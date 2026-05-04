#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// Create new node
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertBeg(int data) {
    struct node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void insertEnd(int data) {
    struct node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct node *last = head->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Insert at position
void insertPos(int data, int pos) {
    if (pos == 1) {
        insertBeg(data);
        return;
    }

    struct node *temp = head;
    struct node *newNode = createNode(data);
    int i = 1;

    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    struct node *nextNode = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}

// Delete from beginning
void deleteBeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct node *last = head->prev;
        struct node *temp = head;

        head = head->next;
        last->next = head;
        head->prev = last;

        free(temp);
    }
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *last = head->prev;

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct node *secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;

        free(last);
    }
}

// Delete at position
void deletePos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    struct node *temp = head;
    int i = 1;

    while (i < pos && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (i != pos) {
        printf("Invalid position\n");
        return;
    }

    struct node *prevNode = temp->prev;
    struct node *nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    free(temp);
}

// Search element
void search(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    int pos = 1;

    do {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element not found\n");
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    printf("List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Main function (Menu)
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Doubly Circular Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeg(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertPos(data, pos);
                break;

            case 4:
                deleteBeg();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
